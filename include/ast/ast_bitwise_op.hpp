#ifndef ast_bitwise_op_hpp
#define ast_bitwise_op_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

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

    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream) const {
        throw std::runtime_error("No python Impl");
        

    
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const =0;
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

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" & ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("AND", dstreg, left_reg, right_reg));
    }
};

class BitOr
    : public BitwiseOperator
{

public:
    BitOr(nodePtr _left, nodePtr _right)
        : BitwiseOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" | ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" | ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("OR", dstreg, left_reg, right_reg));    
    }
};

class BitXor
    : public BitwiseOperator
{

public:
    BitXor(nodePtr _left, nodePtr _right)
        : BitwiseOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" ^ ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" ^ ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("XOR", dstreg, left_reg, right_reg));       
    }
};

class BitNot
    : public ASTNode
{
protected:
    nodePtr exp;
public:
    RShift(nodePtr _exp)
    : exp(_exp)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" ~ ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" ~ ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string exp_reg = myContext.makeRegName();
        exp->convertIR(exp_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("NOR", dstreg, exp_reg, exp_reg));     
    }
};

class LShift
    : public BitwiseOperator
{

public:
    LShift(nodePtr _left, nodePtr _right)
        : BitwiseOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" << ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" << ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("SLLV", dstreg, left_reg, right_reg));   
    }
};
class RShift
    : public BitwiseOperator
{

public:
    RShift(nodePtr _left, nodePtr _right)
        : BitwiseOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" >> ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" >> ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("SRLV", dstreg, left_reg, right_reg)); 
    }
};

#endif
