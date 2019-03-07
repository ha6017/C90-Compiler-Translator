#ifndef ast_logical_op_hpp
#define ast_logical_op_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "ast_context.hpp"

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
     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const =0;
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

     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const override{

        std::string left_reg = myContext.findTemp();
        left->convertIR(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->convertIR(right_reg, myContext, outStream);

        std::string my_labelA=myContext.makeLabelName();
        std::string my_labelB=myContext.makeLabelName();

        outStream<<"ADDI "<<dstreg<<", reg_0"<<", 1"<<std::endl;
        outStream<<"BEQ "<<left_reg<<", reg_0,"<<my_labelA<<std::endl;
        outStream<<"BEQ "<<right_reg<<", reg_0,"<<my_labelA<<std::endl;
        outStream<<"J "<<my_labelB<<std::endl;

        outStream<<my_labelA<<std::endl;
        outStream<<"ADDI "<<dstreg<<", reg_0"<<", 0"<<std::endl;
        outStream<<my_labelB<<std::endl;

        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);
        
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

     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const override{

        std::string left_reg = myContext.findTemp();
        left->convertIR(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->convertIR(right_reg, myContext, outStream);

        std::string my_labelA=myContext.makeLabelName();
        std::string my_labelB=myContext.makeLabelName();



        outStream<<"ADDI "<<dstreg<<", reg_0"<<", 0"<<std::endl;
        outStream<<"BNE "<<left_reg<<", reg_0,"<<my_labelA<<std::endl;
        outStream<<"BNE "<<right_reg<<", reg_0,"<<my_labelA<<std::endl;
        outStream<<"J "<<my_labelB<<std::endl;

        outStream<<my_labelA<<std::endl;
        outStream<<"ADDI "<<dstreg<<", reg_0"<<", 1"<<std::endl;
        outStream<<my_labelB<<std::endl;
        myContext.UnlockReg(left_reg);
        myContext.UnlockReg(right_reg);
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

     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const override{

        std::string exp_reg = myContext.findTemp();
        exp->convertIR(exp_reg, myContext, outStream);

        std::string my_label=myContext.makeLabelName();
        outStream<<"ADDI "<<dstreg<<", reg_0"<<", 1"<<std::endl;
        outStream<<"BEQ "<<exp_reg<<", reg_0,"<<my_label<<std::endl;
        outStream<<"ADDI "<<dstreg<<", reg_0"<<", 0"<<std::endl;
        outStream<<my_label<<std::endl;
        myContext.UnlockReg(exp_reg);
    }
};


#endif
