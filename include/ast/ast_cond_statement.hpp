#ifndef ast_cond_statement_hpp
#define ast_cond_statement_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>


#include "ast_node.hpp"
#include "ast_context.hpp"

class If
    : public ASTNode
{
protected:
    nodePtr condition;
    nodePtr branch;
public:
    If(nodePtr _condition, nodePtr _branch)
        : condition(_condition)
        , branch(_branch)
    {}

    ~If()
    {
        delete condition;
        delete branch;
    }
    

    virtual void printC(std::ostream &outStream) const {
        outStream<<"if(";
        condition->printC(outStream);
        outStream<<"){";
        branch->printC(outStream);
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
            for(int i=tab.indent;i!=0;i--){
                outStream<<"\t";
            }
            outStream<<"if (";
            condition->printPython(outStream, tab);
            outStream<<") :"<<std::endl;
            tab.indent++;
            branch->printPython(outStream, tab);      
            tab.indent--;
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {

        Context newContext(myContext);
        std::string my_label=newContext.makeLabelName();

        std::string compare_reg = newContext.findTemp();

        condition->printMips(compare_reg, newContext, outStream);
    
        outStream<<"BEQ "<<compare_reg<<", $0, "<<my_label<<std::endl;
        outStream<<"nop"<<std::endl;
        branch->printMips(dstreg, newContext, outStream);
        outStream<<my_label<<":"<<std::endl;
        myContext.UnlockReg(compare_reg);

    }
};

class Switch: public ASTNode
{
    protected:
        nodePtr condition;
        nodePtr branch;

    public:
        Switch(nodePtr _condition, nodePtr _branch)
        :   condition(_condition)
        ,   branch(_branch)
        {}

        ~Switch(){
            if(condition!=NULL){delete condition;}
            if (branch!=NULL){delete branch;}
        }

        virtual void printC(std::ostream &outStream) const{
            outStream<<"switch(";
            condition->printC(outStream);
            outStream<<"){";
            branch->printC(outStream);
            outStream<<"}";
        }

        virtual void printPython(std::ostream &outStream, IndentAdd &tab) const {
            for(int i=tab.indent;i!=0;i--){
                outStream<<"\t";
            }
            outStream<<"switch (";
            condition->printPython(outStream, tab);
            outStream<<") :"<<std::endl;
            tab.indent++;
            branch->printPython(outStream, tab);      
            tab.indent--;
        }

        virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
            

        }


};

class IfElse
    : public ASTNode
{
protected:
    nodePtr condition;
    nodePtr branchA;
    nodePtr branchB;

public:
    IfElse(nodePtr _condition, nodePtr _branchA, nodePtr _branchB)
        : condition(_condition)
        , branchA(_branchA)
        , branchB(_branchB)
    {}

    ~IfElse()
    {
        delete condition;
        delete branchA;
        delete branchB;
    }

    virtual void printC(std::ostream &outStream) const {
        
        outStream<<"if(";
        condition->printC(outStream);
        outStream<<"){";
        outStream<<std::endl;
        branchA->printC(outStream);
        outStream<<std::endl;
        outStream<<"} else {";
        outStream<<std::endl;
        branchB->printC(outStream);
        outStream<<std::endl;
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
        for(int i=tab.indent;i!=0;i--){
            outStream<<"\t";
        }
        outStream<<"if (";
        condition->printPython(outStream, tab);
        outStream<<") :"<<std::endl;
        tab.indent++;
        branchA->printPython(outStream, tab);
        outStream<<std::endl;
        tab.indent--;
        for(int i=tab.indent;i!=0;i--){
            outStream<<"\t";
        }
        outStream<<"else :";
        outStream<<std::endl;
        tab.indent++;
        branchB->printPython(outStream, tab);
        outStream<<std::endl;
        tab.indent--;
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        Context newContext(myContext);

        std::string my_labelA=newContext.makeLabelName();
        std::string my_labelB=newContext.makeLabelName();

        std::string compare_reg = newContext.findTemp();

        condition->printMips(compare_reg, newContext, outStream);
    
        outStream<<"BEQ "<<compare_reg<<", $0, "<<my_labelA<<std::endl;
        outStream<<"nop"<<std::endl;
        branchA->printMips(dstreg, newContext, outStream);
        outStream<<"J "<<my_labelB<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<my_labelA<<":"<<std::endl;
        branchB->printMips(dstreg, newContext, outStream);
        outStream<<my_labelB<<":"<<std::endl;
        myContext.UnlockReg(compare_reg);
    }
};

class ReturnStatement: 
    public ASTNode
{
    public:
        nodePtr expr;
        //nodePtr AdditionalStatements;

     ReturnStatement(nodePtr _expr )
	:	expr (_expr){}
    
    ~ReturnStatement()
    {
        if(expr!=NULL){delete expr;}   
    }

    virtual void printC(std::ostream &outStream) const override
    {
            outStream<<"return";
            if(expr!=NULL){
                outStream<<" ";
                expr->printC(outStream);
            }
            outStream<<";";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override
    {
            for(int i=tab.indent;i!=0;i--){
                outStream<<"\t";
            }
            outStream<<"return";
            if(expr!=NULL){
                outStream<<" ";
                expr->printPython(outStream, tab);
            }
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {
        expr->printMips("$2", myContext, outStream);

        outStream<<"LW "<<"$31"<<", "<<"-4"<<" ($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"LW "<<"$fp"<<", "<<"0"<<" ($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"ADDI $sp, $fp,  0"<<std::endl;
        outStream<<"JR $31"<<std::endl;
        outStream<<"nop"<<std::endl;
    }
};

class ExprStatement: public ASTNode
{
    public:
        nodePtr expr;
        

     ExprStatement(nodePtr _expr)
	:	expr (_expr){}
    
    ~ExprStatement()
    {
        if (expr!=NULL) {delete expr;}
       
    }

    virtual void printC(std::ostream &outStream) const override
    {
       if(expr!=NULL){ 
            
                expr->printC(outStream);
                outStream<<";";
            }
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        if(expr!=NULL){
            for(int i=tab.indent;i!=0;i--){
                outStream<<"\t";
            }
            expr->printPython(outStream, tab);
        }
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {
        if(expr!=NULL){
            expr->printMips(dstreg,myContext,outStream);
        }

    }
};

class DeclareStatement: public ASTNode
{
    public:
        std::string type;
        nodePtr declist;

    DeclareStatement(std::string &_type, nodePtr _declist)
    : type(_type), declist(_declist){}

    ~DeclareStatement(){
        if (declist!=NULL){ delete declist;}
    }

    virtual void printC(std::ostream &outStream) const override
    {
            outStream<<type<<" ";
            declist->printC(outStream);
            outStream<<";";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        for(int i=tab.indent;i!=0;i--){
            outStream<<"\t";
        }
        declist->printPython(outStream, tab);
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {
        if(declist!=NULL){
            declist->printMips(dstreg,myContext,outStream);
        }

    }

};

class Declare: public ASTNode
{
    public:
        std::string id;
        nodePtr expr;

    Declare(std::string &_id, nodePtr _expr)
    : id(_id), expr(_expr){}

    ~Declare(){
        if (expr!=NULL){ delete expr;}
    }

    virtual void printC(std::ostream &outStream) const override
    {
            outStream<<id;
            if(expr!=NULL){
                outStream<<"=";
                expr->printC(outStream);
            }
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
            outStream<<id;
            if(expr!=NULL){
                outStream<<"=";
                expr->printPython(outStream, tab);
            } else {
                outStream<<"=0";
            }
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {
        std::string exp_reg = myContext.findTemp();
        if(expr!=NULL){
            expr->printMips(exp_reg, myContext, outStream);
        }else{
            outStream<<"ADDI "<<exp_reg<<", $0, 0"<<std::endl;
        }
        outStream<<"SW "<<exp_reg<<", "<<myContext.createLocalInt(id)<<" ($fp)"<<std::endl;

        myContext.UnlockReg(exp_reg);
    }


};

class FunctionStatementInExpr: public ASTNode
{
    public:
        std::string id;
        nodePtr arg;

    FunctionStatementInExpr(std::string &_id, nodePtr _arg)
    : id(_id), arg(_arg){}

    ~FunctionStatementInExpr(){
        if (arg!=NULL){ delete arg;}
    }

    virtual void printC(std::ostream &outStream) const override
    {
            outStream<<id<<"(";
            if(arg!=NULL){
                arg->printC(outStream);
            }
            outStream<<")";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
            outStream<<id<<"(";
            if(arg!=NULL){
                arg->printPython(outStream, tab);
            }  
            outStream<<")";
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {
        Context newContext(myContext);
        newContext.paramCount=0;
        arg->printMips(dstreg, newContext, outStream);

        outStream<<"ADDI $sp, $fp, "<<newContext.currentLocalPointer<<std::endl;
        // newContext.enterFunction();

        // outStream<<"SW "<<"$fp"<<", "<<"0"<<" ($sp)"<<std::endl;
        
        // outStream<<"ADDI "<<"$fp, "<<"$sp, "<<" 0"<<std::endl;

        outStream<<"JAL "<<id<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"ADDU "<<dstreg<<", $2, "<<"$0"<<std::endl;
    }

};

// class ReturnList: public ASTNode
// {
//     public:
//         nodePtr expr;
//         nodePtr MoreStatements;

//      ReturnList(nodePtr _expr, nodePtr _AdditionalStatements )
// 	:	expr (_expr)
// 	,	MoreStatements(_AdditionalStatements){}
    
//     ~ReturnList()
//     {
//         delete expr;
//         delete MoreStatements;
//     }

//     virtual void printC(std::ostream &outStream) const override
//     {
       
//     }

//     virtual void printPython(std::ostream &outStream) const override{

//     }

//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {

//     }
// };

// class MinReturnList: public ASTNode
// {
//     public:
//         nodePtr expr;
//         nodePtr MoreStatements;

//      MinReturnList(nodePtr _expr, nodePtr _AdditionalStatements )
// 	:	expr (_expr)
// 	,	MoreStatements(_AdditionalStatements){}
    
//     ~MinReturnList()
//     {
//         delete expr;
//         delete MoreStatements;
//     }

//     virtual void printC(std::ostream &outStream) const override
//     {
       
//     }

//     virtual void printPython(std::ostream &outStream) const override{

//     }

//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {

//     }
// };

// class MulReturnList: public ASTNode
// {
//     public:
//         nodePtr expr;
//         nodePtr MoreStatements;

//      MulReturnList(nodePtr _expr, nodePtr _AdditionalStatements )
// 	:	expr (_expr)
// 	,	MoreStatements(_AdditionalStatements){}
    
//     ~MulReturnList()
//     {
//         delete expr;
//         delete MoreStatements;
//     }

//     virtual void printC(std::ostream &outStream) const override
//     {
       
//     }

//     virtual void printPython(std::ostream &outStream) const override{

//     }

//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {

//     }
// };

// class ParameterDef : public ASTNode
// {
// public:
// 	nodePtr Variable2;

	
//     ParameterDef(nodePtr _Variable2)
// 		: Variable2 (_Variable2)
// 		{}
	
//     ~ParameterDef(){
//         delete Variable2;
//     }

// 	virtual void printC(std::ostream &dst) const override
//     {
//        Variable2->printC(dst);
//     }

//     virtual void printPython(std::ostream &dst) const override{

//     }

//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {

//     }


// };


#endif
