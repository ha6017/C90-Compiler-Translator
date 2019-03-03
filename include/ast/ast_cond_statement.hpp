#ifndef ast_cond_statement_hpp
#define ast_cond_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class If
    : public ASTNode
{
protected:
    nodePtr condition;
    nodePtr branch;
public:
    If(nodePtr _condition, nodePtr _branch)
        : condition(_condition)
        , branch(_branch)
    {}

    virtual void printC(std::ostream &outStream) const {
        outStream<<"if(";
        condition->printC(outStream);
        outStream<<"){";
        branch->printC(outStream);
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {
        // std::string my_label=myContext.makeLabelName();
        // IRlist.pushback(IntermediateRep("BNE", left_reg, right_reg, my_label));
     }
};

class IfElse
    : public ASTNode
{
protected:
    nodePtr condition;
    nodePtr branchA;
    nodePtr branchB;

public:
    IfElse(nodePtr _condition, nodePtr _branchA, nodePtr _branchB)
        : condition(_condition)
        , branchA(_branchA)
        , branchB(_branchB)
    {}

    virtual void printC(std::ostream &outStream) const {
        outStream<<"if(";
        condition->printC(outStream);
        outStream<<"){";
        branchA->printC(outStream);
        outStream<<"} else {";
        branchB->printC(outStream);
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {

     }
};


#endif
