#ifndef ast_assign_op_hpp
#define ast_assign_op_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class UnaryAssignOperator
    : public ASTNode
{
protected:
    std::string var;
public:
    UnaryAssignOperator(std::string _var)
        : var(_var)
    {}

    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream) const {
        throw std::runtime_error("No python Impl");
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const =0;
};


class BinaryAssignOperator
    : public ASTNode
{
protected:
    std::string var;
    nodePtr exp;
public:
    BinaryAssignOperator(std::string _var, nodePtr _exp)
        : var(_var)
        , exp(_exp)
    {}

    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream) const {
        throw std::runtime_error("No python Impl");
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const =0;
};

class PreIncrement
    : public UnaryAssignOperator
{

public:
    PreIncrement(std::string &_var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"++"<<var;
    }

    virtual void printPython(std::ostream &outStream) const override{
        // need to research python

    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        IRlist.push_back(IntermediateRep("ADDI", var, var, "1"));
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var));    
    }
};


class PreDecrement
    : public UnaryAssignOperator
{

public:
    PreDecrement(std::string &_var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"--"<<var;
    }

    virtual void printPython(std::ostream &outStream) const override{
        // need to research python

    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        IRlist.push_back(IntermediateRep("SUBI", var, var, "1"));
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var));     
    }
};

class PostIncrement //THIS IS MUCH HARDER BECAUSE NEEDS TO OCCUR AFTER THE FOR LOOP/ SEMICOLON / WHILE LOOP.
    : public UnaryAssignOperator
{

public:
    PostIncrement(std::string &_var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"++";
    }

    virtual void printPython(std::ostream &outStream) const override{
        // need to research python

    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var)); 
        IRlist.push_back(IntermediateRep("ADDI", var, var, "1"));
    }
};

class PostDecrement //THIS IS MUCH HARDER BECAUSE NEEDS TO OCCUR AFTER THE FOR LOOP/ SEMICOLON / WHILE LOOP.
    : public UnaryAssignOperator
{

public:
    PostDecrement(std::string &_var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"--";
    }

    virtual void printPython(std::ostream &outStream) const override{
        // need to research python

    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var)); 
        IRlist.push_back(IntermediateRep("SUBI", var, var, "1"));    
    }
};

class AssignEqual //this is only for the case a=5,   int a=5 is dealt with seperately
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    AssignEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}

    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<var<<"=";
        exp->printPython(outStream);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string exp_reg=myContext.makeRegName();
        exp->convertIR(exp_reg, myContext, IRlist);
        
        IRlist.push_back(IntermediateRep("ADDU", var, "reg_0", exp_reg)); //cannot put var itself in the convert IR cus var might be refered to in an expression.
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var)); //because assignment also has a return value
    }
};

class PlusEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    PlusEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}

    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"+=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<var<<"+=";
        exp->printPython(outStream);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string exp_reg=myContext.makeRegName();
        exp->convertIR(exp_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("ADDU", var, var, exp_reg));
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var));    
    }
};

class SubEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    SubEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}

    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"-=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<var<<"-=";
        exp->printPython(outStream);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string exp_reg=myContext.makeRegName();
        exp->convertIR(exp_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("SUBU", var, var, exp_reg));
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var));       
    }
};

class MultEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    MultEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}

    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"*=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<var<<"*=";
        exp->printPython(outStream);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        std::string exp_reg=myContext.makeRegName();
        exp->convertIR(exp_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("MULT", "N_A", var, exp_reg));
        IRlist.push_back(IntermediateRep("MFLO", var, "N_A", "N_A"));       
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var));
    }
};

class DivEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    DivEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}

    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"/=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<var<<"/=";
        exp->printPython(outStream);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{

        
        std::string exp_reg=myContext.makeRegName();
        exp->convertIR(exp_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("DIV", "N_A", var, exp_reg));
        IRlist.push_back(IntermediateRep("MFLO", var, "N_A", "N_A"));       
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var));
    }
};

class RemEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    RemEqual(std::string &_var, nodePtr _exp)
        : BinaryAssignOperator(_var, _exp)
    {}

    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"%=";
        exp->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<var<<"%=";
        exp->printPython(outStream);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{

        std::string exp_reg=myContext.makeRegName();
        exp->convertIR(exp_reg, myContext, IRlist);
        IRlist.push_back(IntermediateRep("DIV", "N_A", var, exp_reg));
        IRlist.push_back(IntermediateRep("MFHI", var, "N_A", "N_A"));       
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var));
       
    }
};

#endif
