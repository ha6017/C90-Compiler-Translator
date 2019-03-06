#ifndef ast_variable_dec_hpp
#define ast_variable_dec_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

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
    nodePtr myParamList;
public:
    LocalDecArray(std::string _var, int _size, nodePtr _myParamList)
        :   var(_var)
        ,   size(_size)
        ,   myParamList(_myParamList)
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
            outStream<<"LW "<<"reg_0"<<", "<<arrayLocation<<"(0)"<<std::endl;  //this needs to be swapped with the PARAMS!!!!
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
public:
    GlobalDecArray(std::string _var, int _size)
        :   var(_var)
        ,   size(_size)
    {}

    virtual void printC(std::ostream &outStream) const {
        outStream<<"int "<<var<<"["<<size<<"]";
    }

    virtual void printPython(std::ostream &outStream) const {
        //nothing
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {
        unsigned int arrayLocation=createGlobalArray(var,size);
        if(myParamList!=NULL){
            outStream<<"LW "<<"reg_0"<<", "<<arrayLocation<<"(0)"<<std::endl;  //this needs to be swapped with the PARAMS!!!!
        }else{
            for(int i=0;i<size;i++){
                outStream<<"LW "<<"reg_0"<<", "<<(arrayLocation+i*4)<<"(0)"<<std::endl; 
            }
        }
    }
};

/*class InitArray
    : public ASTNode
{
protected:
    std::string var;
    int size;
    nodePtr listElements; //can make into array cus size is known ASTnode
public:
    InitArray(std::string _var, int _size, nodePtr _listElements)
        :   var(_var)
        ,   size(_size)
    {

        //{1,2,3,4,5}  (int a, int b, )

        listElements = new [size];
        for(int i=0;i<size;i++){
            listElements[i]=
        }
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
     virtual void convertIR(std::string dstreg, Context myContext, std::vector<IntermediateRep> outStream) const {

    }
};*/

#endif
