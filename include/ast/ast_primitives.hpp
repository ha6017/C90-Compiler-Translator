#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"

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

    virtual double printMips(std::ostream &outStream, Context &myContext) const override{
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

    virtual double printMips(std::ostream &outStream, Context &myContext) const override{
        //NEED TO IMPLEMENT CONTEXT FIRST 
    }

};


#endif
