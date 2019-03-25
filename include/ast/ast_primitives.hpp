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
        // if(myContext.localIntExists(var)){
        //     outStream<<"LW "<<dstreg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl; //no global?
        //     outStream<<"nop"<<std::endl;
        // }else if(myContext.globalIntExists(var)){
        //     outStream<<"LW "<<dstreg<<", "<<myContext.findGlobalInt(var)<<"($0)"<<std::endl; //no global?
        //     outStream<<"nop"<<std::endl;
        // }else{
        //     throw "Variable has not yet been declared";
        // }


        if(myContext.localIntExists(var)){
            outStream<<"LW "<<dstreg<<", "<<myContext.findLocalInt(var)<<"($fp)"<<std::endl;
            outStream<<"nop"<<std::endl;
        }else if(myContext.globalIntExists(var)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<var<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<var<<")"<<std::endl;
            outStream<<"LW "<<dstreg<<", "<<"0"<<"("<<addr_reg<<")"<<std::endl; 
            outStream<<"nop"<<std::endl;
            myContext.UnlockReg(addr_reg);
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

        outStream<<"ADDI "<<dstreg<<", $0, "<< value<<std::endl;

    }

};

class ArrElement
    : public ASTNode
{
public:
    int element;
    std::string id; 

    ArrElement(std::string &_id, int _element)
        :   element(_element)
        ,   id(_id)
    {}
    
    virtual void printC(std::ostream &outStream) const override{
        outStream<<id<<"["<<element<<"]";
    }

    virtual void printPython(std::ostream &outStream , IndentAdd &tab) const override{
        outStream<<id<<"["<<element<<"]";
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override{
        
        // if(myContext.localIntExists(id)){
        //         outStream<<"LW "<<dstreg<<", "<<myContext.findLocalArrayElement(id, element)<<"($fp)"<<std::endl;
        //         outStream<<"nop"<<std::endl;
        // }else if(myContext.globalIntExists(id)){
        //         outStream<<"LW "<<dstreg<<", "<<myContext.findGlobalArrayElement(id, element)<<"($0)"<<std::endl; 
        //         outStream<<"nop"<<std::endl;
            
        // }else{
        //     throw "Variable has not yet been declared";
        // } 


        if(myContext.localIntExists(id)){
            outStream<<"LW "<<dstreg<<", "<<myContext.findLocalArrayElement(id, element)<<"($fp)"<<std::endl;
            outStream<<"nop"<<std::endl;
        }else if(myContext.globalIntExists(id)){
            std::string addr_reg = myContext.findTemp();
            outStream<<"LUI "<<addr_reg<<", %hi("<<id<<")"<<std::endl;
            outStream<<"ADDI "<<addr_reg<<", "<<addr_reg<<", %lo("<<id<<")"<<std::endl;
            outStream<<"LW "<<dstreg<<", "<<(element*4)<<"("<<addr_reg<<")"<<std::endl; 
            outStream<<"nop"<<std::endl;
            myContext.UnlockReg(addr_reg);

        }else{
            throw "Variable has not yet been declared";
        } 

    }

};


#endif
