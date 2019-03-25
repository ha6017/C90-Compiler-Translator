#ifndef ast_assign_op_hpp
#define ast_assign_op_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "ast_context.hpp"

class UnaryAssignOperator
    : public ASTNode
{
protected:
    std::string var;
public:
    UnaryAssignOperator(std::string _var)
        : var(_var)
    {}

    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const {
        throw std::runtime_error("No python Impl");
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const =0;
};


class BinaryAssignOperator
    : public ASTNode
{
protected:
    std::string var;
    nodePtr exp;
public:
    BinaryAssignOperator(std::string _var, nodePtr _exp)
        : var(_var)
        , exp(_exp)
    {}

    ~BinaryAssignOperator(){
        delete exp;
    }

    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream) const {
        throw std::runtime_error("No python Impl");
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const =0;
};

class PreIncrement
    : public UnaryAssignOperator
{
protected:
    int ArrayIndex;

public:
    PreIncrement(std::string &_var, int _ArrayIndex)
        : UnaryAssignOperator(_var)
        , ArrayIndex(_ArrayIndex)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
       // outStream<<"++"<<var;
        if(ArrayIndex==-1){ outStream<<"++"<<var; }
            else { outStream<<"++"<<var<<"["<<ArrayIndex<<"]"; }
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        if(ArrayIndex==-1){ outStream<<"++"<<var; }
            else { outStream<<"++"<<var<<"["<<ArrayIndex<<"]"; }
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string var_reg = myContext.findTemp();
        std::string addr_reg;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }else{
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"LW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        }
        outStream<<"ADDI "<<var_reg<<", "<<var_reg<< ", 1"<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0, "<< var_reg<<std::endl;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
    }
};


class PreDecrement
    : public UnaryAssignOperator
{
protected:
    int ArrayIndex;

public:
    PreDecrement(std::string &_var, int _ArrayIndex)
        : UnaryAssignOperator(_var)
        , ArrayIndex(_ArrayIndex)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        if(ArrayIndex==-1){ outStream<<"--"<<var; }
            else { outStream<<"--"<<var<<"["<<ArrayIndex<<"]"; }
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
       if(ArrayIndex==-1){ outStream<<"--"<<var; }
            else { outStream<<"--"<<var<<"["<<ArrayIndex<<"]"; }
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
         
        std::string var_reg = myContext.findTemp();
        std::string addr_reg;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }else{
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"LW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        }
        outStream<<"ADDIU "<<var_reg<<", "<<var_reg<< ", -1"<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
    }
};

class PostIncrement //THIS IS MUCH HARDER BECAUSE NEEDS TO OCCUR AFTER THE FOR LOOP/ SEMICOLON / WHILE LOOP.
    : public UnaryAssignOperator
{

protected:
    int ArrayIndex;

public:
    PostIncrement(std::string &_var, int _ArrayIndex)
        : UnaryAssignOperator(_var)
        , ArrayIndex(_ArrayIndex)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        if(ArrayIndex==-1){ outStream<<"++"<<var; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"++"; }
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        if(ArrayIndex==-1){ outStream<<"++"<<var; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"++"; }
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
         
        std::string var_reg = myContext.findTemp();
        std::string addr_reg;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }else{
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"LW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        }
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        outStream<<"ADDI "<<var_reg<<", "<<var_reg<< ", 1"<<std::endl;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
    }
};

class PostDecrement //THIS IS MUCH HARDER BECAUSE NEEDS TO OCCUR AFTER THE FOR LOOP/ SEMICOLON / WHILE LOOP.
    : public UnaryAssignOperator
{
protected:
    int ArrayIndex;

public:
    PostDecrement(std::string &_var, int _ArrayIndex)
        : UnaryAssignOperator(_var)
        , ArrayIndex(_ArrayIndex)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
       if(ArrayIndex==-1){ outStream<<"--"<<var; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"--"; }
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
       if(ArrayIndex==-1){ outStream<<"--"<<var; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"--"; }
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string var_reg = myContext.findTemp();
        std::string addr_reg;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }else{
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"LW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        }
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        outStream<<"ADDIU "<<var_reg<<", "<<var_reg<< ", -1"<<std::endl;
        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
    }
};

class AssignEqual //this is only for the case a=5,   int a=5 is dealt with seperately
    : public BinaryAssignOperator
{
protected:
    int ArrayIndex;

public:
    AssignEqual(std::string &_var, nodePtr _exp, int _ArrayIndex)
        : BinaryAssignOperator(_var, _exp)
        ,  ArrayIndex(_ArrayIndex)
    {}


    virtual void printC(std::ostream &outStream) const override{
        if(ArrayIndex==-1){ outStream<<var<<"="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"="; }
            exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        if(ArrayIndex==-1){ outStream<<var<<"="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"="; }
            exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        if(!myContext.localIntExists(var) && !myContext.globalIntExists(var)){
            throw "Variable has not yet been declared";
        }
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< exp_reg<<std::endl;
        // if(myContext.localIntExists(var)){
        //     if(ArrayIndex==-1){
        //         outStream<<"SW "<<dstreg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        //     }else{
        //         outStream<<"SW "<<dstreg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
        //     }
        // }else if(myContext.globalIntExists(var)){
        //     if(ArrayIndex==-1){
        //         outStream<<"SW "<<dstreg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
        //     }else{
        //         outStream<<"SW "<<dstreg<<", "<<myContext.findGlobalArrayElement(var, ArrayIndex)<<"($0)"<<std::endl; 
        //     }
        // }else{
        //     throw "Variable has not yet been declared";
        // }        

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<dstreg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<dstreg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"SW "<<dstreg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<dstreg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        }

        myContext.UnlockReg(exp_reg);
    }
};

class PlusEqual 
    : public BinaryAssignOperator
{
protected:
    int ArrayIndex;


public:
    PlusEqual(std::string &_var, nodePtr _exp, int _ArrayIndex)
        : BinaryAssignOperator(_var, _exp)
        , ArrayIndex(_ArrayIndex)
    {}


    virtual void printC(std::ostream &outStream) const override{
        // outStream<<var<<" += ";
        // exp->printC(outStream);
         if(ArrayIndex==-1){ outStream<<var<<"+="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"+="; }
            exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
       if(ArrayIndex==-1){ outStream<<var<<"+="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"+="; }
            exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();

std::string addr_reg;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }else{
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"LW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        }  

        outStream<<"ADDU "<<var_reg<<", "<<var_reg<<", "<< exp_reg<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
        myContext.UnlockReg(exp_reg);

    }
};

class SubEqual 
    : public BinaryAssignOperator
{
protected:
    int ArrayIndex;

public:
    SubEqual(std::string &_var, nodePtr _exp, int _ArrayIndex)
        : BinaryAssignOperator(_var, _exp)
        , ArrayIndex(_ArrayIndex)
    {}


    virtual void printC(std::ostream &outStream) const override{
       if(ArrayIndex==-1){ outStream<<var<<"-="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"-="; }
            exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        if(ArrayIndex==-1){ outStream<<var<<"-="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"-="; }
            exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();
        std::string addr_reg;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }else{
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"LW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        } 

        outStream<<"SUBU "<<var_reg<<", "<<var_reg<<", "<< exp_reg<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;


        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
        myContext.UnlockReg(exp_reg);    
    }
};

class MultEqual 
    : public BinaryAssignOperator
{
protected:
    int ArrayIndex;

public:
    MultEqual(std::string &_var, nodePtr _exp, int _ArrayIndex)
        : BinaryAssignOperator(_var, _exp)
        , ArrayIndex(_ArrayIndex)
    {}


    virtual void printC(std::ostream &outStream) const override{
        if(ArrayIndex==-1){ outStream<<var<<"*="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"*="; }
            exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
       if(ArrayIndex==-1){ outStream<<var<<"*="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"*="; }
            exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();
        std::string addr_reg;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }else{
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"LW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        }
        outStream<<"MUL "<<dstreg<<", "<< var_reg<<", "<< exp_reg<<std::endl;
        // outStream<<"MFLO "<<var_reg<<std::endl;
        // outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<dstreg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<dstreg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<dstreg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<dstreg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
        myContext.UnlockReg(exp_reg); 
    }
};

class DivEqual 
    : public BinaryAssignOperator
{
protected:
    int ArrayIndex;

public:
    DivEqual(std::string &_var, nodePtr _exp, int _ArrayIndex)
        : BinaryAssignOperator(_var, _exp)
        , ArrayIndex(_ArrayIndex)
    {}


    virtual void printC(std::ostream &outStream) const override{
        if(ArrayIndex==-1){ outStream<<var<<"/="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"/="; }
            exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        if(ArrayIndex==-1){ outStream<<var<<"/="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"/="; }
            exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();
        std::string addr_reg;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }else{
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"LW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        } 
        outStream<<"DIV "<<var_reg<<", "<< exp_reg<<std::endl;
        outStream<<"MFLO "<<var_reg<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        } 
        myContext.UnlockReg(var_reg);
        myContext.UnlockReg(exp_reg); 
    }
};

class RemEqual 
    : public BinaryAssignOperator
{
protected:
    int ArrayIndex;

public:
    RemEqual(std::string &_var, nodePtr _exp, int _ArrayIndex)
        : BinaryAssignOperator(_var, _exp)
        , ArrayIndex(_ArrayIndex)
    {}


    virtual void printC(std::ostream &outStream) const override{
        if(ArrayIndex==-1){ outStream<<var<<"%="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"%="; }
            exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        if(ArrayIndex==-1){ outStream<<var<<"%="; }
            else { outStream<<var<<"["<<ArrayIndex<<"]"<<"%="; }
            exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();
        std::string addr_reg;

        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }else{
                outStream<<"LW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
                outStream<<"nop"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            if(ArrayIndex==-1){
                outStream<<"LW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"LW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        } 
        outStream<<"DIV "<<var_reg<<", "<< exp_reg<<std::endl;
        outStream<<"MFHI "<<var_reg<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        if(myContext.localIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            }else{
                outStream<<"SW "<<var_reg<<", "<<myContext.findLocalArrayElement(var, ArrayIndex)<<"($fp)"<<std::endl;
            }
        }else if(myContext.globalIntExists(var)){
            if(ArrayIndex==-1){
                outStream<<"SW "<<var_reg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            }else{
                outStream<<"SW "<<var_reg<<", "<<(ArrayIndex*4)<<"("<<addr_reg<<")"<<std::endl; 
            }
            myContext.UnlockReg(addr_reg);
        }else{
            throw "Variable has not yet been declared";
        }   
        myContext.UnlockReg(var_reg);
        myContext.UnlockReg(exp_reg); 
    }
};

class UnaryNeg: public ASTNode
{
    protected:
        nodePtr expr;

    public:
    UnaryNeg(nodePtr _expr)
        :expr(_expr){}

    ~UnaryNeg(){
        delete expr;
    }

    virtual void printC(std::ostream &outStream) const override{
        outStream<<"-(";
        expr->printC(outStream);
        outStream<<")";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<"-(";
        expr->printPython(outStream, tab);
        outStream<<")";
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        expr->printMips(exp_reg, myContext, outStream);
        outStream<<"SUBU "<<dstreg<<", $0, "<<exp_reg<<std::endl;
        myContext.UnlockReg(exp_reg);
    }
};



class UnaryPos: public ASTNode
{
    protected:
        nodePtr expr;

    public:

    UnaryPos(nodePtr _expr)
        :expr(_expr){}

    ~UnaryPos(){
        delete expr;
    }

    virtual void printC(std::ostream &outStream) const override{
        outStream<<"+(";
        expr->printC(outStream);
        outStream<<")";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<"+(";
        expr->printPython(outStream, tab);
        outStream<<")";
    }
    
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        expr->printMips(exp_reg, myContext, outStream);
        outStream<<"ADDU "<<dstreg<<", $0, "<<exp_reg<<std::endl;
        myContext.UnlockReg(exp_reg);
    }
};

#endif
