#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class Variable
    : public ASTnode
{
public:
    std::string id;

    Variable(std::string _id)
        : id(_id)
    {}
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<id;
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<id;
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }

};

class Number
    : public ASTnode
{
public:
    int value;
    
    Number(int value)
        : value(value)
    {}
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<value;
    }

    virtual void printPython(std::ostream &outStream) const override{
        outStream<<value;
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }

};

class ArrElement
    : public ASTnode
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
        outStream<<id<<"["<<element<<"]"
    }

     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }

};


#endif
