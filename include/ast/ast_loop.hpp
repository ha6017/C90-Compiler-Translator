#ifndef ast_loop_hpp
#define ast_loop_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "ast_context.hpp"

class For
    : public ASTNode
{
protected:
    nodePtr initialisation;
    nodePtr condition;
    nodePtr postLoopExp;
    nodePtr branch;
public:
    For(nodePtr _initialisation, nodePtr _condition, nodePtr _postLoopExp, nodePtr _branch)
        : initialisation(_initialisation)
        , condition(_condition)
        , postLoopExp(_postLoopExp)
        , branch(_branch)
    {}

    ~For(){
        delete initialisation;
        delete condition;
        delete postLoopExp;
        if(branch!=NULL) {delete branch;}
    }

    virtual void printC(std::ostream &outStream) const {
        outStream<<"for(";
        initialisation->printC(outStream);
        outStream<<";";
        condition->printC(outStream);
        outStream<<";";
        postLoopExp->printC(outStream);
        outStream<<") {"<<std::endl;
        if(branch!=NULL){
             branch->printC(outStream);
        }
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
            for(int i=tab.indent;i!=0;i--){
                outStream<<"\t";
            }
            initialisation->printPython(outStream, tab);
            outStream<<std::endl;
            for(int i=tab.indent;i!=0;i--){
                outStream<<"\t";
            }
            outStream<<"While ";
            condition->printPython(outStream, tab);
            outStream<<" :"<<std::endl;
            tab.indent++;
            branch->printPython(outStream , tab);
            tab.indent--;
            if(postLoopExp!=NULL){ postLoopExp->printPython(outStream, tab); }
            outStream<<std::endl;
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        //enter scope dont forget
        Context newContext(myContext);
        myContext.scopeCountPerScope++;
        newContext.enterScope();
        initialisation->printMips(dstreg, newContext, outStream);

        std::string compare_reg = newContext.findTemp();

        std::string my_labelA="top_"+newContext.makeScopedLabelID();
        std::string my_labelB="bottom_"+newContext.makeScopedLabelID();
       
       
        outStream<<std::endl<<my_labelA<<":"<<std::endl;
        condition->printMips(compare_reg, newContext, outStream);
    
        outStream<<"BEQ "<<compare_reg<<", $0, "<<my_labelB<<std::endl;
        outStream<<"nop"<<std::endl;

        if(branch!=NULL){
            branch->printMips(dstreg, newContext, outStream);
        }

        postLoopExp->printMips(dstreg, newContext, outStream);
        outStream<<"J "<<my_labelA<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<std::endl<<my_labelB<<":"<<std::endl;
    }
};

class While
    : public ASTNode
{
protected:
    nodePtr condition;
    nodePtr branch;
public:
    While(nodePtr _condition, nodePtr _branch)
        : condition(_condition)
        , branch(_branch)
    {}

    ~While()
    {
        delete condition;
        delete branch;
    }

    virtual void printC(std::ostream &outStream) const {
        outStream<<"while(";
        condition->printC(outStream);
        outStream<<") {";
        branch->printC(outStream);
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
            for(int i=tab.indent;i!=0;i--){
                outStream<<"\t";
            }
            outStream<<"while (";
            condition->printPython(outStream, tab);
            outStream<<") :"<<std::endl;
            tab.indent++;
            branch->printPython(outStream, tab); 
            tab.indent--; 
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {

        Context newContext(myContext);
        myContext.scopeCountPerScope++;
        newContext.enterScope();

        std::string compare_reg = newContext.findTemp();

        std::string my_labelA="top_"+newContext.makeScopedLabelID();
        std::string my_labelB="bottom_"+newContext.makeScopedLabelID();
       
       
        outStream<<std::endl<<my_labelA<<":"<<std::endl;
        condition->printMips(compare_reg, newContext, outStream);
    
        outStream<<"BEQ "<<compare_reg<<", $0, "<<my_labelB<<std::endl;
        outStream<<"nop"<<std::endl;

        if(branch!=NULL){
            branch->printMips(dstreg, newContext, outStream);
        }
        outStream<<"J "<<my_labelA<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<std::endl<<my_labelB<<":"<<std::endl;
        //dont need to unlock reg because newContext is about to go out of scope.
     }
};

class DoWhile
    : public ASTNode
{
protected:
    nodePtr condition;
    nodePtr branch;

public:
    DoWhile(nodePtr _condition, nodePtr _branch)
        : condition(_condition)
        , branch(_branch)
    {}

   ~DoWhile()
    {
        delete condition;
        delete branch;
    }

    virtual void printC(std::ostream &outStream) const {
        outStream<<"do {";
        branch->printC(outStream);
        outStream<<"}";
        outStream<<"while(";
        condition->printC(outStream);
        outStream<<")";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
        
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {

        Context newContext(myContext);
        myContext.scopeCountPerScope++;
        newContext.enterScope();

        std::string compare_reg = newContext.findTemp();

        std::string my_labelA="top_"+newContext.makeScopedLabelID();
        std::string my_labelB="bottom_"+newContext.makeScopedLabelID();
       
       
        outStream<<std::endl<<my_labelA<<":"<<std::endl;
        if(branch!=NULL){
            branch->printMips(dstreg, newContext, outStream);
        }
        condition->printMips(compare_reg, newContext, outStream);
    
        outStream<<"BEQ "<<compare_reg<<", $0, "<<my_labelB<<std::endl;
        outStream<<"nop"<<std::endl;

        outStream<<"J "<<my_labelA<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<std::endl<<my_labelB<<":"<<std::endl;
     }
};

class Break
    : public ASTNode
{
protected:

public:
    Break()
    {}

    ~Break()
    {}

    virtual void printC(std::ostream &outStream) const {
        outStream<<"break";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
        for(int i=tab.indent;i!=0;i--){
                outStream<<"\t";
        }
        outStream<<"break";
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {

        std::string my_label="bottom_"+myContext.makeScopedLabelID();
        outStream<<"J "<<my_label<<std::endl;
        outStream<<"nop"<<std::endl;
        
     }
};

class Continue
    : public ASTNode
{
protected:

public:
    Continue()
    {}

    ~Continue()
    {}

    virtual void printC(std::ostream &outStream) const {
        outStream<<"continue";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
        for(int i=tab.indent;i!=0;i--){
            outStream<<"\t";
        }
        outStream<<"continue";    
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        std::string my_label="top_"+myContext.makeScopedLabelID();
        outStream<<"J "<<my_label<<std::endl;
        outStream<<"nop"<<std::endl;
     }
};

class NewScope
    : public ASTNode
{
protected: 
nodePtr body;
public:
    NewScope(nodePtr _body):
        body(_body)
    {}

    ~NewScope()
    {
        if(body!=NULL){ delete body; }
    }

    virtual void printC(std::ostream &outStream) const {
        outStream<<"{"<<std::endl; 
        body->printC(outStream);
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
        
        body->printPython(outStream, tab);     
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        if(body!=NULL){
            body->printMips(dstreg, myContext, outStream);
        }
        
    }
};

#endif