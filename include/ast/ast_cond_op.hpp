#ifndef ast_cond_op_hpp
#define ast_cond_op_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class ConditionalOperator
    : public ASTNode
{
protected:
    nodePtr left;
    nodePtr right;
    
public:
    ConditionalOperator(nodePtr _left, nodePtr _right)
        : left(_left)
        , right(_right)
    {}

    virtual ~ConditionalOperator()
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

class CondEqual
    : public ConditionalOperator
{

public:
    CondEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}
    virtual ~CondEqual()
    {
        delete left;
        delete right;
    }
    
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

    virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);

        std::string my_label=myContext.makeLabelName();

        IRlist.push_back(IntermediateRep("ADDI", dstreg, "reg_0", "0"));
        IRlist.push_back(IntermediateRep("BNE", left_reg, right_reg, my_label));
        IRlist.push_back(IntermediateRep("ADDI", dstreg, "reg_0", "1"));
        IRlist.push_back(IntermediateRep(my_label, "N_A", "N_A", "N_A"));
    }
};

class NotEqual
    : public ConditionalOperator
{

public:
    NotEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    virtual ~NotEqual()
    {
        delete left;
        delete right;
    }
    
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        std::string my_label=myContext.makeLabelName();
        IRlist.push_back(IntermediateRep("ADDI", dstreg, "reg_0", "0"));
        IRlist.push_back(IntermediateRep("BEQ", left_reg, right_reg, my_label));
        IRlist.push_back(IntermediateRep("ADDI", dstreg, "reg_0", "1"));
        IRlist.push_back(IntermediateRep(my_label, "N_A", "N_A", "N_A"));
    }
};

class Less
    : public ConditionalOperator
{

public:
    Less(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    virtual ~Less()
    {
        delete left;
        delete right;
    }
    
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("SLT", dstreg, left_reg, right_reg));    
    }
};

class Greater
    : public ConditionalOperator
{

public:
    Greater(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    virtual ~Greater()
    {
        delete left;
        delete right;
    }
    
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("SLT", dstreg, right_reg, left_reg));    
    }
};


class LessOrEqual
    : public ConditionalOperator
{

public:
    LessOrEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    virtual ~LessOrEqual()
    {
        delete left;
        delete right;
    }
    
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("SLT", dstreg, right_reg, left_reg));    
        std::string one_reg = myContext.makeRegName();
        IRlist.push_back(IntermediateRep("ADDI", one_reg, "reg_0", "1"));
        IRlist.push_back(IntermediateRep("SLT", dstreg, dstreg, one_reg));
    }
};

class GreaterOrEqual
    : public ConditionalOperator
{

public:
    GreaterOrEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    virtual ~GreaterOrEqual()
    {
        delete left;
        delete right;
    }
    
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

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string left_reg = myContext.makeRegName();
        left->convertIR(left_reg, myContext, IRlist);
        std::string right_reg = myContext.makeRegName();
        right->convertIR(right_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("SLT", dstreg, left_reg, right_reg));    
        std::string one_reg = myContext.makeRegName();
        IRlist.push_back(IntermediateRep("ADDI", one_reg, "reg_0", "1"));
        IRlist.push_back(IntermediateRep("SLT", dstreg, dstreg, one_reg));    
    }
};

#endif
