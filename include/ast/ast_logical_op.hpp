#ifndef ast_logical_op_hpp
#define ast_logical_op_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class LogicalOperator
    : public ASTNode
{
protected:
    nodePtr left;
    nodePtr right;
public:
    LogicalOperator(nodePtr _left, nodePtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~LogicalOperator()
    {
        delete left;
        delete right;
    }
    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream) const {
        throw std::runtime_error("No python Impl");

    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const =0;
};

class LogAnd
    : public LogicalOperator
{

public:
    LogAnd(nodePtr _left, nodePtr _right)
        : LogicalOperator(_left, _right)
    {}
    virtual ~LogAnd()
    {
        delete left;
        delete right;
    }
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" && ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" && ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();//BRANCH TO TEST IF EQUAL TO 0 and then AND THEM
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("AND", dstreg, left_reg, right_reg));
    }
};

class LogOr
    : public LogicalOperator
{

public:
    LogOr(nodePtr _left, nodePtr _right)
        : LogicalOperator(_left, _right)
    {}

    virtual ~LogOr()
    {
        delete left;
        delete right;
    }
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" || ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" || ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class LogNot
    : public ASTNode
{
protected:
    nodePtr exp;
public:
    LogNot(nodePtr _exp)
        : exp(_exp)
    {}
    virtual ~LogNot()
    {
        delete exp;
    }
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"!";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<"!";
        exp->printC(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
   
    }
};


#endif
