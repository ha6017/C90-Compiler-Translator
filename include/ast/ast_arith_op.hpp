#ifndef ast_arith_op_hpp
#define ast_arith_op_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "ast_context.hpp"

//#include "intermediate_rep.hpp"

class ArithOperator
    : public ASTNode
{
protected:
    nodePtr left;
    nodePtr right;
public:

    ArithOperator(nodePtr _left, nodePtr _right)
        : left(_left)
        , right(_right)
    {}

    virtual ~ArithOperator(){
        delete left;
        delete right;
    }

    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const {
        throw std::runtime_error("No python Impl");
        
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const =0;
};

class Add
    : public ArithOperator
{

public:
    Add(nodePtr _left, nodePtr _right)
        : ArithOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"( ";
        left->printC(outStream);
        outStream<<" + ";
        right->printC(outStream);
        outStream<<" )";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" + ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
         
        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"ADDU "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);
    }
};


class Sub
    : public ArithOperator
{

public:
    Sub(nodePtr _left, nodePtr _right)
        : ArithOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"( ";
        left->printC(outStream);
        outStream<<" - ";
        right->printC(outStream);
        outStream<<" )";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" - ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"SUBU "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);   
    }
};


class Mult
    : public ArithOperator
{

public:
    Mult(nodePtr _left, nodePtr _right)
        : ArithOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"( ";
        left->printC(outStream);
        outStream<<" * ";
        right->printC(outStream);
        outStream<<" )";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" * ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"MUL "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;

        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);   
    }
};

class Div
    : public ArithOperator
{

public:
    Div(nodePtr _left, nodePtr _right)
        : ArithOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" / ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<"( ";
        left->printPython(outStream, tab);
        outStream<<" / ";
        right->printPython(outStream, tab);
        outStream<<" )";
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"DIV "<<left_reg<<", "<<right_reg<<std::endl;
        outStream<<"MFLO "<<dstreg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);   
    }
};

class Mod
    : public ArithOperator
{

public:
    Mod(nodePtr _left, nodePtr _right)
        : ArithOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"( ";
        left->printC(outStream);
        outStream<<" % ";
        right->printC(outStream);
        outStream<<" )";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" % ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"DIV "<<left_reg<<", "<<right_reg<<std::endl;
        outStream<<"MFHI "<<dstreg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);
    }
};

#endif
