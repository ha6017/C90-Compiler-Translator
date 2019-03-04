#ifndef ast_loop_hpp
#define ast_loop_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class For
    : public ASTNode
{
protected:
    nodePtr initialisation;
    nodePtr condition;
    nodePtr postLoopExp;
    nodePtr branch;
public:
    For(nodePtr _initialisation, nodePtr _condition, nodePtr _postLoopExp, nodePtr _branch)
        : initialisation(_initialisation)
        , condition(_condition)
        , postLoopExp(_postLoopExp)
        , branch(_branch)
    {}


    virtual void printC(std::ostream &outStream) const {
        outStream<<"for(";
        initialisation->printC(outStream);
        outStream<<";";
        condition->printC(outStream);
        outStream<<";";
        postLoopExp->printC(outStream);
        outStream<<") {"<<std::endl;
        branch->printC(outStream);
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {
        initialisation->convertIR(dstreg, myContext, IRlist);

        std::string compare_reg = myContext.makeRegName();
        condition->convertIR(compare_reg, myContext, IRlist);

        std::string my_labelA=myContext.makeLabelName();
        std::string my_labelB=myContext.makeLabelName();

        IRlist.push_back(IntermediateRep(my_labelA, "N_A", "N_A", "N_A"));

        IRlist.push_back(IntermediateRep("BEQ", compare_reg, "reg_0", my_labelB));

        branch->convertIR(dstreg, myContext, IRlist);
        postLoopExp->convertIR(dstreg, myContext, IRlist);
        
        IRlist.push_back(IntermediateRep("J", "N_A", "N_A", my_labelA));

        IRlist.push_back(IntermediateRep(my_labelB, "N_A", "N_A", "N_A"));
    }
};

class While
    : public ASTNode
{
protected:
    nodePtr condition;
    nodePtr branch;
public:
    While(nodePtr _condition, nodePtr _branch)
        : condition(_condition)
        , branch(_branch)
    {}

    virtual ~While()
    {
        delete condition;
        delete branch;
    }
    virtual void printC(std::ostream &outStream) const {
        outStream<<"while(";
        condition->printC(outStream);
        outStream<<") {";
        branch->printC(outStream);
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

class DoWhile
    : public ASTNode
{
protected:
    nodePtr condition;
    nodePtr branch;

public:
    DoWhile(nodePtr _condition, nodePtr _branch)
        : condition(_condition)
        , branch(_branch)
    {}

    virtual ~DoWhile()
    {
        delete condition;
        delete branch;
    }

    virtual void printC(std::ostream &outStream) const {

        outStream<<"do {";
        branch->printC(outStream);
        outStream<<"}";
        outStream<<"while(";
        condition->printC(outStream);
        outStream<<")";
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
