#ifndef ast_logical_op_hpp
#define ast_logical_op_hpp

#include <string>
#include <iostream>
#include <cmath>

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
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class LogOr
    : public LogicalOperator
{

public:
    LogOr(nodePtr _left, nodePtr _right)
        : LogicalOperator(_left, _right)
    {}
    
    
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
    : public LogicalOperator
{

public:
    LogNot(nodePtr _left, nodePtr _right)
        : LogicalOperator(_left,_right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<" ! ";
        left->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<" ! ";
        left->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};


#endif
