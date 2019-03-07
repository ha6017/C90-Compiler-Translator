#ifndef ast_variable_dec_hpp
#define ast_variable_dec_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "ast_context.hpp"


/*class DecInt
    : public ASTNode
{
protected:
    std::string var;
public:
    DecInt(std::string _var)
        : var(_var)
    {}


    virtual void printC(std::ostream &outStream) const {
        outStream<<"int "<<var;
    }

    virtual void printPython(std::ostream &outStream) const {
        //nothing
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {
        outStream.push_back(IntermediateRep("ADDI", var, "reg_0", "0"));
    }
};*/

class LocalInitInt
    : public ASTNode
{
protected:
    std::string var;
    nodePtr exp;
public:
    LocalInitInt(std::string _var, nodePtr _exp)
        :   var(_var)
        ,   exp(_exp)
    {}

    virtual ~InitInt()
    {
        delete exp;
    }

    virtual void printC(std::ostream &outStream) const {
        outStream<<"int "<<var<<" = ";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const {
        outStream<<var<<" = ";
        exp->printPython(outStream);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {
        std::string exp_reg = myContext.findTemp();
        exp->convertIR(exp_reg, myContext, outStream);
        outStream<<"SW "<<exp_reg<<", "<<createLocalInt(var)<<"(0)"<<std::endl;
        myContext.UnlockReg(exp_reg);
    }
};

class LocalInitArray
    : public ASTNode
{
protected:
    std::string var;
    int size;
    nodePtr myArrayList;
public:
    LocalDecArray(std::string _var, int _size, nodePtr _myArrayList)
        :   var(_var)
        ,   size(_size)
        ,   myArrayList(_myArrayList)
    {}

    virtual void printC(std::ostream &outStream) const {
        outStream<<"int "<<var<<"["<<size<<"] = {";
        myParamList->printC(outStream);
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream) const {
        //nothing
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {
        unsigned int arrayLocation=createLocalArray(var,size);
        if(myParamList!=NULL){
            myContext.currentArrayElement=0;
            myContext.currentArrayName=var;
            myArrayList->convertIR(dstreg, myContext, outStream);
        }else{
            for(int i=0;i<size;i++){
                outStream<<"LW "<<"reg_0"<<", "<<(arrayLocation+i*4)<<"(0)"<<std::endl; 
            }
        }
    }
};

class GlobalInitInt
    : public ASTNode
{
protected:
    std::string var;
    nodePtr exp;
public:
    GlobalInitInt(std::string _var, nodePtr _exp)
        :   var(_var)
        ,   exp(_exp)
    {}

    virtual ~InitInt()
    {
        delete exp;
    }

    virtual void printC(std::ostream &outStream) const {
        outStream<<"int "<<var<<" = ";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const {
        outStream<<var<<" = ";
        exp->printPython(outStream);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {
        std::string exp_reg = myContext.findTemp();
        exp->convertIR(exp_reg, myContext, outStream);
        std::string var_reg = myContext.findTemp();
        outStream<<"ADDU "<<var_reg<<", "<<reg_0<<", "<< exp_reg<<std::endl;
        outStream<<"SW "<<var_reg<<", "<<createGlobalInt(var)<<"(0)"<<std::endl;
        myContext.UnlockReg(var_reg);
        myContext.UnlockReg(exp_reg);
    }
};

class GlobalInitArray
    : public ASTNode
{
protected:
    std::string var;
    int size;
    nodePtr myArrayList;
public:
    GlobalInitArray(std::string _var, int _size, nodePtr _myArrayList)
        :   var(_var)
        ,   size(_size)
        ,   myArrayList(_myArrayList)
    {}

    virtual void printC(std::ostream &outStream) const {
        outStream<<"int "<<var<<"["<<size<<"] = {";
        myParamList->printC(outStream);
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream) const {
        //nothing
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {
        unsigned int arrayLocation=createGlobalArray(var,size);
        if(myParamList!=NULL){
            myContext.currentArrayElement=0;
            myContext.currentArrayName=var;
            myArrayList->convertIR(dstreg, myContext, outStream);
        }else{
            for(int i=0;i<size;i++){
                outStream<<"LW "<<"reg_0"<<", "<<(arrayLocation+i*4)<<"(0)"<<std::endl; 
            }
        }
    }
};



#endif
