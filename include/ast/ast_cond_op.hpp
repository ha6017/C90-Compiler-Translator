#ifndef ast_cond_op_hpp
#define ast_cond_op_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "ast_context.hpp"

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
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const =0;
};

class CondEqual
    : public ConditionalOperator
{

public:
    CondEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}
    // virtual ~CondEqual()
    // {
    //     delete left;
    //     delete right;
    // }
    
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

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {

        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        std::string my_label=myContext.makeLabelName();

        outStream<<"ADDI "<<dstreg<<", reg_0, 0"<<std::endl;
        outStream<<"BNE "<<left_reg<<", "<<right_reg<<", "<<my_label<<std::endl;
        outStream<<"ADDI "<<dstreg<<", reg_0, 1"<<std::endl;
        outStream<<my_label<<std::endl;

        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);
    }
};

class NotEqual
    : public ConditionalOperator
{

public:
    NotEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    // virtual ~NotEqual()
    // {
    //     delete left;
    //     delete right;
    // }
    
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

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {

        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        std::string my_label=myContext.makeLabelName();

        outStream<<"ADDI "<<dstreg<<", reg_0, 0"<<std::endl;
        outStream<<"BEQ "<<left_reg<<", "<<right_reg<<", "<<my_label<<std::endl;
        outStream<<"ADDI "<<dstreg<<", reg_0, 1"<<std::endl;
        outStream<<my_label<<std::endl;

        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);
    }
};

class Less
    : public ConditionalOperator
{

public:
    Less(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    // virtual ~Less()
    // {
    //     delete left;
    //     delete right;
    // }
    
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

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        std::string my_label=myContext.makeLabelName();

        outStream<<"SLT "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg); 
    }
};

class Greater
    : public ConditionalOperator
{

public:
    Greater(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    // virtual ~Greater()
    // {
    //     delete left;
    //     delete right;
    // }
    
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

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        std::string my_label=myContext.makeLabelName();

        outStream<<"SLT "<<dstreg<<", "<<right_reg<<", "<<left_reg<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg); 

    }
};


class LessOrEqual
    : public ConditionalOperator
{

public:
    LessOrEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    // virtual ~LessOrEqual()
    // {
    //     delete left;
    //     delete right;
    // }
    
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

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        std::string my_label=myContext.makeLabelName();

        outStream<<"SLT "<<dstreg<<", "<<right_reg<<", "<<left_reg<<std::endl;
        std::string one_reg = myContext.findTemp();
        outStream<<"ADDI "<<dstreg<<", reg_0, 1"<<std::endl;
        outStream<<"SLT "<<dstreg<<", "<<dstreg<<", "<<one_reg<<std::endl;


        myContext.UnlockReg(one_reg);
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg); 
    }
};

class GreaterOrEqual
    : public ConditionalOperator
{

public:
    GreaterOrEqual(nodePtr _left, nodePtr _right)
        : ConditionalOperator(_left, _right)
    {}

    // virtual ~GreaterOrEqual()
    // {
    //     delete left;
    //     delete right;
    // }
    
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

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);
        std::string my_label=myContext.makeLabelName();

        outStream<<"SLT "<<dstreg<<", "<<left_reg<<", "<<right_reg<<std::endl;
        std::string one_reg = myContext.findTemp();
        outStream<<"ADDI "<<dstreg<<", reg_0, 1"<<std::endl;
        outStream<<"SLT "<<dstreg<<", "<<dstreg<<", "<<one_reg<<std::endl;


        myContext.UnlockReg(one_reg);
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg); 
    }
};

#endif