#ifndef ast_bitwise_op_hpp
#define ast_bitwise_op_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class If
    : public ASTnode
{
protected:
    nodePtr condition;
    nodePtr branch;
public:
    BitwiseOperator(nodePtr _condition, nodePtr _branch)
        : condition(_condition)
        , branch(_branch)
    {}

    virtual void printC(std::ostream &outStream) const {
        std::cout<<"if(";
        condition->printC(outStream);
        std::cout<<"){";
        branch->printC(outStream);
        std::cout<<"}";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const {

     }
};

class IfElse
    : public ASTnode
{
protected:
    nodePtr condition;
    nodePtr branchA;
    nodePtr branchB;

public:
    BitwiseOperator(nodePtr _condition, nodePtr _branchA, nodePtr _branchB)
        : condition(_condition)
        , branchA(_branchA)
        , branchB(_branchB)
    {}

    virtual void printC(std::ostream &outStream) const {
        std::cout<<"if(";
        condition->printC(outStream);
        std::cout<<"){";
        branchA->printC(outStream);
        std::cout<<"} else {";
        branchB->printC(outStream);
        std::cout<<"}";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const {

     }
};

class While
    : public ASTnode
{
protected:
    nodePtr condition;
    nodePtr branch;

public:
    BitwiseOperator(nodePtr _condition, nodePtr _branch)
        : condition(_condition)
        , branch(_branch)
    {}

    virtual void printC(std::ostream &outStream) const {
        std::cout<<"while(";
        condition->printC(outStream);
        std::cout<<"){";
        branch->printC(outStream);
        std::cout<<"}";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const {

     }
};

class DoWhile
    : public ASTnode
{
protected:
    nodePtr condition;
    nodePtr branch;

public:
    BitwiseOperator(nodePtr _condition, nodePtr _branch)
        : condition(_condition)
        , branch(_branch)
    {}

    virtual void printC(std::ostream &outStream) const {

        std::cout<<"do {";
        branch->printC(outStream);
        std::cout<<"}";

        std::cout<<"while(";
        condition->printC(outStream);
        std::cout<<")";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const {

     }
};


#endif
