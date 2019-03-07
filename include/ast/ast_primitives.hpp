#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <vector>

#include "ast_node.hpp"
#include "ast_context.hpp"

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

     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const override{
        
        outStream<<"LW "<<dstreg<<", "<<findLocalInt(var)<<"(0)"<<std::endl;

    }

};

class Number
    : public ASTNode
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

     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const override{

        outStream<<"ADDI "<<dstreg<<", "<<reg_0<<", "<< value<<std::endl;

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

    virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const override{
        outStream<<"LW "<<dstreg<<", "<<createLocalArray(id, element)<<"(0)"<<std::endl;
    }

};


#endif
