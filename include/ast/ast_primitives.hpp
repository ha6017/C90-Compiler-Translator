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

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<var;
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        if(myContext.localIntExists(var)){
            outStream<<"LW "<<dstreg<<", "<<myContext.findLocalInt(var)<<"(reg_fp)"<<std::endl; //no global?
        }else if(myContext.globalIntExists(var)){
            outStream<<"LW "<<dstreg<<", "<<myContext.findGlobalInt(var)<<"(0)"<<std::endl; //no global?
        }else{
            throw "Variable has not yet been declared";
        }

    }

};

class Number
    : public ASTNode
{
public:
    int value;
    
    Number(float value, float neg)
        : value(value-neg)
    {}

    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<value;
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        outStream<<value;
    }

     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{

        outStream<<"ADDI "<<dstreg<<", "<<"reg_0"<<", "<< value<<std::endl;

    }

};

class ArrElement
    : public ASTNode
{
public:
    int element;
    std::string id; 

    ArrElement(std::string &_id, int element)
        :   element(element)
        ,   id(_id)
    {}
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<id<<"["<<element<<"]";
    }

    virtual void printPython(std::ostream &outStream , IndentAdd &tab) const override{
        outStream<<id<<"["<<element<<"]";
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        outStream<<"LW "<<dstreg<<", "<<myContext.createLocalArray(id, element)<<"(reg_fp)"<<std::endl;
    }

};


#endif
