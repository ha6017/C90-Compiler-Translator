#ifndef ast_assign_op_hpp
#define ast_assign_op_hpp

#include <string>
#include <iostream>
#include <cmath>

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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const =0;
};


class BinaryAssignOperator
    : public ASTNode
{
protected:
    std::string var;
    nodePtr exp;
public:
    UnaryAssignOperator(std::string _var, nodePtr exp)
        : var(_var)
        , exp(_exp)
    {}

    virtual void printC(std::ostream &outStream) const =0;

    virtual void printPython(std::ostream &outStream) const {
        throw std::runtime_error("No python Impl");
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const =0;
};

class PreIncrement
    : public UnaryAssignOperator
{

public:
    PreIncrement(std::string _var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"++"<<var;
    }

    virtual void printPython(std::ostream &outStream) const override{
        // need to research python

    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};


class PreDecrement
    : public UnaryAssignOperator
{

public:
    PreDecrement(std::string _var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<"--"<<var;
    }

    virtual void printPython(std::ostream &outStream) const override{
        // need to research python

    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class PostIncrement //THIS IS MUCH HARDER BECAUSE NEEDS TO OCCUR AFTER THE FOR LOOP/ SEMICOLON / WHILE LOOP.
    : public UnaryAssignOperator
{

public:
    PostIncrement(std::string _var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"++";
    }

    virtual void printPython(std::ostream &outStream) const override{
        // need to research python

    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class PostDecrement //THIS IS MUCH HARDER BECAUSE NEEDS TO OCCUR AFTER THE FOR LOOP/ SEMICOLON / WHILE LOOP.
    : public UnaryAssignOperator
{

public:
    PostDecrement(std::string _var)
        : UnaryAssignOperator(_var)
    {}
    
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<var<<"--";
    }

    virtual void printPython(std::ostream &outStream) const override{
        // need to research python

    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class AssignEqual //this is only for the case a=5 need to deal with int a=5 seperately
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    AssignEqual(std::string _var, nodePtr _exp)
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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class PlusEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    PlusEqual(std::string _var, nodePtr _exp)
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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class SubEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    SubEqual(std::string _var, nodePtr _exp)
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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class SubEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    SubEqual(std::string _var, nodePtr _exp)
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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class MultEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    MultEqual(std::string _var, nodePtr _exp)
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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

class DivEqual 
    : public BinaryAssignOperator
{
protected:
    std::string var;
    nodePtr exp;
public:
    MultEqual(std::string _var, nodePtr _exp)
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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }
};

#endif
