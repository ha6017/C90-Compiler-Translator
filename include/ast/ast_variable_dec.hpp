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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {
        IRlist.push_back(IntermediateRep("ADDI", var, "reg_0", "0"));
    }
};*/

class InitInt
    : public ASTNode
{
protected:
    std::string var;
    nodePtr exp;
public:
    InitInt(std::string _var, nodePtr _exp)
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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {
        std::string exp_reg=myContext.makeRegName();
        exp->convertIR(exp_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("ADDU", var, "reg_0", exp_reg));
    }
};

class DecArray
    : public ASTNode
{
protected:
    std::string var;
    int size;
public:
    DecArray(std::string _var, int _size)
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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {

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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const {

    }
};*/

#endif
