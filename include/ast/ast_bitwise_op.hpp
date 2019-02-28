#ifndef ast_bitwise_op_hpp
#define ast_bitwise_op_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class BitwiseOperator
    : public ASTnode
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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const =0;
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class BitNot
    : public BitwiseOperator
{

public:
    BitNot(nodePtr _left)
        : left(_left);
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<" ~";
        left->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<" ~ ";
        left->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

#endif
