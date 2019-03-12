#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <vector>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class Variable
    : public ASTNode
{
public:
    std::string var;

    Variable(std::string &_var)
        : var(_var)
    {}

    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<var;
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<var;
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        IRlist.push_back(IntermediateRep("ADDU", dstreg, "reg_0", var));
    }

};

class Number
    : public ASTNode
{
public:
    int value;
    
    Number(int _value)
        : value(_value)
    {}

    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<value;
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<value;
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        IRlist.push_back(IntermediateRep("ADDI", dstreg, "reg_0", std::to_string(value)));
    }

};

class ArrElement
    : public ASTNode
{
public:
    int element;
    std::string id; 

    ArrElement(int element, std::string id)
        :   element(element)
        ,   id(id)
    {}
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<id<<"["<<element<<"]";
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<id<<"["<<element<<"]";
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }

};


#endif
