#ifndef ast_cond_statement_hpp
#define ast_cond_statement_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>


#include "ast_node.hpp"
#include "ast_context.hpp"

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
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {

        Context newContext(myContext);
        std::string my_label=newContext.makeLabelName();

        std::string compare_reg = newContext.findTemp();

        condition->printMips(compare_reg, newContext, outStream);
    
        outStream<<"BEQ "<<compare_reg<<"reg_0"<<my_label<<std::endl;
        branch->printMips(dstreg, newContext, outStream);
        outStream<<my_label<<std::endl;

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
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {


        
        Context newContext(myContext);

        std::string my_labelA=newContext.makeLabelName();
        std::string my_labelB=newContext.makeLabelName();

        std::string compare_reg = newContext.findTemp();

        condition->printMips(compare_reg, newContext, outStream);
    
        outStream<<"BEQ "<<compare_reg<<"reg_0"<<my_labelA<<std::endl;
        branchA->printMips(dstreg, newContext, outStream);
        outStream<<"J "<<my_labelB<<std::endl;
        outStream<<my_labelA<<std::endl;
        branchB->printMips(dstreg, newContext, outStream);
        outStream<<my_labelB<<std::endl;
    }
};


#endif
