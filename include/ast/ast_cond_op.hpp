#ifndef ast_cond_op_hpp
#define ast_cond_op_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class ConditionalOperator
    : public ASTnode
{
protected:
    nodePtr left;
    nodePtr right;
    
public:
    ConditionalOperator(nodePtr _left, nodePtr _right)
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

class CondEqual
    : public ConditionalOperator
{

public:
    CondEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" == ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" == ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class NotEqual
    : public ConditionalOperator
{

public:
    NotEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" != ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" != ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class Less
    : public ConditionalOperator
{

public:
    Less(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" < ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" < ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class Greater
    : public ConditionalOperator
{

public:
    Greater(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" > ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" > ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};


class LessOrEqual
    : public ConditionalOperator
{

public:
    LessOrEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" <= ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" <= ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class GreaterOrEqual
    : public ConditionalOperator
{

public:
    GreaterOrEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" >= ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        left->printPython(outStream);
        outStream<<" >= ";
        right->printPython(outStream);
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

#endif
