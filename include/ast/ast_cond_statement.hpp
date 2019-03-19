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
    
        outStream<<"BEQ "<<compare_reg<<"reg_0"<<my_label<<std::endl;
        branch->printMips(dstreg, newContext, outStream);
        outStream<<my_label<<std::endl;

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

    virtual ~IfElse()
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
    
        outStream<<"BEQ "<<compare_reg<<"reg_0"<<my_labelA<<std::endl;
        branchA->printMips(dstreg, newContext, outStream);
        outStream<<"J "<<my_labelB<<std::endl;
        outStream<<my_labelA<<std::endl;
        branchB->printMips(dstreg, newContext, outStream);
        outStream<<my_labelB<<std::endl;
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

    virtual void printC(std::ostream &dst) const override
    {
            dst<<"return";
            if(expr!=NULL){
                dst<<" ";
                expr->printC(dst);
            }
            dst<<";";
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

    virtual void printC(std::ostream &dst) const override
    {
            dst<<type<<" ";
            declist->printC(dst);
            dst<<";";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const override{
        for(int i=tab.indent;i!=0;i--){
            outStream<<"\t";
        }
        declist->printPython(outStream, tab);
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {

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

    virtual void printC(std::ostream &dst) const override
    {
            dst<<id;
            if(expr!=NULL){
                dst<<"=";
                expr->printC(dst);
            }
    }

    virtual void printPython(std::ostream &dst, IndentAdd &tab) const override{
            dst<<id;
            if(expr!=NULL){
                dst<<"=";
                expr->printPython(dst, tab);
            } else {
                dst<<"=0";
            }
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {

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

    virtual void printC(std::ostream &dst) const override
    {
            dst<<id<<"(";
            if(arg!=NULL){
                arg->printC(dst);
            }
            dst<<")";
    }

    virtual void printPython(std::ostream &dst, IndentAdd &tab) const override{
            dst<<id<<"(";
            if(arg!=NULL){
                arg->printPython(dst, tab);
            }  
            dst<<")";
    }

    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const override {

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

//     virtual void printC(std::ostream &dst) const override
//     {
       
//     }

//     virtual void printPython(std::ostream &dst) const override{

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

//     virtual void printC(std::ostream &dst) const override
//     {
       
//     }

//     virtual void printPython(std::ostream &dst) const override{

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

//     virtual void printC(std::ostream &dst) const override
//     {
       
//     }

//     virtual void printPython(std::ostream &dst) const override{

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
