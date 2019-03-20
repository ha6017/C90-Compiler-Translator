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

public:
    PreIncrement(std::string &_var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"++"<<var;
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<"++"<<var;
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string var_reg = myContext.findTemp();
        outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"ADDI "<<var_reg<<", "<<var_reg<< ", 1"<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0, "<< var_reg<<std::endl;

        if(myContext.localIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
    }
};


class PreDecrement
    : public UnaryAssignOperator
{

public:
    PreDecrement(std::string &_var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"--"<<var;
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        // need to research python
        outStream<<"--"<<var;
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
         
        std::string var_reg = myContext.findTemp();
        outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"SUBI "<<var_reg<<", "<<var_reg<< ", 1"<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;

        if(myContext.localIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($fp)"<<std::endl; 
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
    }
};

class PostIncrement //THIS IS MUCH HARDER BECAUSE NEEDS TO OCCUR AFTER THE FOR LOOP/ SEMICOLON / WHILE LOOP.
    : public UnaryAssignOperator
{

public:
    PostIncrement(std::string &_var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"++";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        // need to research python
        outStream<<var<<"++";
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
         
        std::string var_reg = myContext.findTemp();
        outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        outStream<<"ADDI "<<var_reg<<", "<<var_reg<< ", 1"<<std::endl;

        if(myContext.localIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
    }
};

class PostDecrement //THIS IS MUCH HARDER BECAUSE NEEDS TO OCCUR AFTER THE FOR LOOP/ SEMICOLON / WHILE LOOP.
    : public UnaryAssignOperator
{

public:
    PostDecrement(std::string &_var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"--";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        // need to research python
        outStream<<var<<"--";
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string var_reg = myContext.findTemp();
        outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        outStream<<"SUBI "<<var_reg<<", "<<var_reg<< ", 1"<<std::endl;

        if(myContext.localIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
        }else{
            throw "Variable has not yet been declared";
        }
        myContext.UnlockReg(var_reg);
    }
};

class AssignEqual //this is only for the case a=5,   int a=5 is dealt with seperately
    : public BinaryAssignOperator
{

public:
    AssignEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}


    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<var<<"=";
        exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< exp_reg<<std::endl;
        if(myContext.localIntExists(var)){
            outStream<<"SW "<<dstreg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){

            outStream<<"SW "<<dstreg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
        }else{
            throw "Variable has not yet been declared";
        }        
        myContext.UnlockReg(exp_reg);
    }
};

class PlusEqual 
    : public BinaryAssignOperator
{

public:
    PlusEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}


    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<" += ";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<var<<"+=";
        exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();

        //need a local int check here
        if(myContext.localIntExists(var)){
            outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            outStream<<"nop"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"LW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl;
            outStream<<"nop"<<std::endl;
        }else{
            throw "Variable has not yet been declared";
        }   
        outStream<<"ADDU "<<var_reg<<", "<<var_reg<<", "<< exp_reg<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;

        if(myContext.localIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
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

public:
    SubEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}


    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"-=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<var<<"-=";
        exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();
        outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"SUBU "<<var_reg<<", "<<var_reg<<", "<< exp_reg<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        if(myContext.localIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
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

public:
    MultEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}


    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"*=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<var<<"*=";
        exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();
        outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"MULT "<<var_reg<<", "<< exp_reg<<std::endl;
        outStream<<"MFLO "<<var_reg<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        if(myContext.localIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
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

public:
    DivEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}


    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"/=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<var<<"/=";
        exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();
        outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"DIV "<<var_reg<<", "<< exp_reg<<std::endl;
        outStream<<"MFLO "<<var_reg<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        if(myContext.localIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
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

public:
    RemEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}


    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"%=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<var<<"%=";
        exp->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();
        outStream<<"LW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"DIV "<<var_reg<<", "<< exp_reg<<std::endl;
        outStream<<"MFHI "<<var_reg<<std::endl;
        outStream<<"ADDU "<<dstreg<<", "<<"$0"<<", "<< var_reg<<std::endl;
        if(myContext.localIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            outStream<<"SW "<<var_reg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; 
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

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{}
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
    
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{}
};

#endif
