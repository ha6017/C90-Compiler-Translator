#ifndef ast_bitwise_op_hpp
#define ast_bitwise_op_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "ast_context.hpp"

class BitwiseOperator
    : public ASTNode
{
protected:
    nodePtr left;
    nodePtr right;
public:
    BitwiseOperator(nodePtr _left, nodePtr _right)
        : left(_left)
        , right(_right)
    {}

    virtual ~BitwiseOperator()
    {
        delete left;
        delete right;
    }

    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const =0; 


    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const =0;
};

class BitAnd
    : public BitwiseOperator
{

public:
    BitAnd(nodePtr _left, nodePtr _right)
        : BitwiseOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" & ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" & ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"AND "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);
        
    }
};

class BitOr
    : public BitwiseOperator
{

public:
    BitOr(nodePtr _left, nodePtr _right)
        : BitwiseOperator(_left, _right)
    {}
    // virtual ~BitOr()
    // {
    //     delete left;
    //     delete right;
    // }
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" | ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" | ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"OR "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);
    }
};

class BitXor
    : public BitwiseOperator
{

public:
    BitXor(nodePtr _left, nodePtr _right)
        : BitwiseOperator(_left, _right)
    {}

    // virtual ~BitXor()
    // {
    //     delete left;
    //     delete right;
    // }
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" ^ ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" ^ ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"XOR "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);    
    }
};

class BitNot
    : public ASTNode
{
protected:
    nodePtr exp;
public:
    BitNot(nodePtr _exp)
        : exp(_exp)
    {}
    // virtual ~BitNot()
    // {
    //     delete exp;
    // }
    
    ~BitNot(){
        if (exp!=NULL){ delete exp;}
    }

    virtual void printC(std::ostream &outStream) const override{
        outStream<<"~";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<"~";
        exp->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);
        outStream<<"NOR "<<dstreg<<", "<<exp_reg<<", "<<exp_reg<<std::endl;
        myContext.UnlockReg(exp_reg);
    }
};

class LShift
    : public BitwiseOperator
{

public:
    LShift(nodePtr _left, nodePtr _right)
        : BitwiseOperator(_left, _right)
    {}
    // virtual ~LShift()
    // {
    //     delete left;
    //     delete right;
    // }
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" << ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" << ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"SLLV "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);   
    }
};
class RShift
    : public BitwiseOperator
{

public:
    RShift(nodePtr _left, nodePtr _right)
        : BitwiseOperator(_left, _right)
    {}

    // virtual ~RShift()
    // {
    //     delete left;
    //     delete right;
    // }
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" >> ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" >> ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        outStream<<"SRLV "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);   
    }
};

#endif
