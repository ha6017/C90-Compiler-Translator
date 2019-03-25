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

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const =0; 

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const =0;
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

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" && ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);

        std::string my_labelA=myContext.makeLabelName();
        std::string my_labelB=myContext.makeLabelName();

        outStream<<"ADDI "<<dstreg<<", $0"<<", 1"<<std::endl;
        outStream<<"BEQ "<<left_reg<<", $0,"<<my_labelA<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"BEQ "<<right_reg<<", $0,"<<my_labelA<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"J "<<my_labelB<<std::endl;
        outStream<<"nop"<<std::endl;

        outStream<<my_labelA<<":"<<std::endl;
        outStream<<"ADDI "<<dstreg<<", $0"<<", 0"<<std::endl;
        outStream<<my_labelB<<":"<<std::endl;

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

    
    
    virtual void printC(std::ostream &outStream) const override{
        left->printC(outStream);
        outStream<<" || ";
        right->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        left->printPython(outStream, tab);
        outStream<<" || ";
        right->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string left_reg = myContext.findTemp();
        left->printMips(left_reg, myContext, outStream);
        std::string right_reg = myContext.findTemp();
        right->printMips(right_reg, myContext, outStream);

        std::string my_labelA=myContext.makeLabelName();
        std::string my_labelB=myContext.makeLabelName();

        outStream<<"ADDI "<<dstreg<<", $0"<<", 0"<<std::endl;
        outStream<<"BNE "<<left_reg<<", $0,"<<my_labelA<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"BNE "<<right_reg<<", $0,"<<my_labelA<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"J "<<my_labelB<<std::endl;
        outStream<<"nop"<<std::endl;

        outStream<<my_labelA<<":"<<std::endl;
        outStream<<"ADDI "<<dstreg<<", $0"<<", 1"<<std::endl;
        outStream<<my_labelB<<":"<<std::endl;
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
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"!";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<"!";
        exp->printPython(outStream, tab);
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);

        std::string my_label=myContext.makeLabelName();
        outStream<<"ADDI "<<dstreg<<", $0"<<", 1"<<std::endl;
        outStream<<"BEQ "<<exp_reg<<", $0,"<<my_label<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"ADDI "<<dstreg<<", $0"<<", 0"<<std::endl;
        outStream<<my_label<<":"<<std::endl;
        myContext.UnlockReg(exp_reg);
    }
};


#endif
