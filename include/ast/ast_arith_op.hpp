#ifndef ast_arith_op_hpp
#define ast_arith_op_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

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

    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream) const {
        throw std::runtime_error("No python Impl");
        
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const =0;
};

class Add
    : public ArithOperator
{

public:
    Add(nodePtr _left, nodePtr _right)
        : ArithOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" + ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" + ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("ADDU", dstreg, left_reg, right_reg));
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
        left->printC(outStream);
        outStream<<" - ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" - ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("SUBU", dstreg, left_reg, right_reg));    
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
        left->printC(outStream);
        outStream<<" * ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" * ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("MULT", "N_A", left_reg, right_reg));
        IRlist.pushback(IntermediateRep("MFLO", dstreg, "N_A", "N_A"));
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

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" / ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("DIV", "N_A", left_reg, right_reg));
        IRlist.pushback(IntermediateRep("MFLO", dstreg, "N_A", "N_A"));    
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
        left->printC(outStream);
        outStream<<" % ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" % ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.pushback(IntermediateRep("DIV", "N_A", left_reg, right_reg));
        IRlist.pushback(IntermediateRep("MFLO", dstreg, "N_A", "N_A"));       }
};

#endif
