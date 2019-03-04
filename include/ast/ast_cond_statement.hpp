#ifndef ast_cond_statement_hpp
#define ast_cond_statement_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>


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

    virtual ~If()
    {
        delete condition;
        delete branch;
    }
    

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

        std::string my_label=myContext.makeLabelName();
        std::string compare_reg = myContext.makeRegName();

        IRlist.push_back(IntermediateRep("ENTERLOCALSCOPE", "N_A", "N_A", "N_A"));
        myContext.enterScope();

        condition->convertIR(compare_reg, myContext, IRlist);//evals the boolean condition
        IRlist.push_back(IntermediateRep("BEQ", compare_reg, "reg_0", my_label)); // branch until after the if statement if condition evals to 0
        branch->convertIR(dstreg, myContext, IRlist);
        IRlist.push_back(IntermediateRep(my_label, "N_A", "N_A", "N_A"));

        IRlist.push_back(IntermediateRep("EXITLOCALSCOPE", "N_A", "N_A", "N_A")); // scope needs thinking
        myContext.exitScope();
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

    virtual ~IfElse()
    {
        delete condition;
        delete branchA;
        delete branchB;
    }

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
        std::string compare_reg = myContext.makeRegName();
        condition->convertIR(compare_reg, myContext, IRlist); // evals the boolean condition


        IRlist.push_back(IntermediateRep("ENTERLOCALSCOPE", "N_A", "N_A", "N_A"));
        myContext.enterScope();

        std::string my_labelA=myContext.makeLabelName();
        IRlist.push_back(IntermediateRep("BEQ", compare_reg, "reg_0", my_labelA)); // branch to the else statement if condition evals to 0
        branchA->convertIR(dstreg, myContext, IRlist);
        std::string my_labelB=myContext.makeLabelName(); // if the if statement is taken skip to the end of the else statement
        IRlist.push_back(IntermediateRep("J", "N_A", "N_A", my_labelB));
        IRlist.push_back(IntermediateRep(my_labelA, "N_A", "N_A", "N_A"));
        branchB->convertIR(dstreg, myContext, IRlist);
        IRlist.push_back(IntermediateRep(my_labelB, "N_A", "N_A", "N_A"));

        IRlist.push_back(IntermediateRep("EXITLOCALSCOPE", "N_A", "N_A", "N_A")); // scope needs thinking
        myContext.exitScope();
    }
};


#endif
