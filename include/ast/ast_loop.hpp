#ifndef ast_loop_hpp
#define ast_loop_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

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


    virtual void printC(std::ostream &outStream) const {
        outStream<<"for(";
        initialisation->printC(outStream);
        outStream<<";";
        condition->printC(outStream);
        outStream<<";";
        postLoopExp->printC(outStream);
        outStream<<") {"<<std::endl;
        branch->printC(outStream);
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        //enter scope dont forget
        initialisation->convertIR(dstreg, myContext, outStream);

        std::string compare_reg = myContext.makeRegName();

        std::string my_labelA="top_"+std::to_string(myContext.scope_counter);
        std::string my_labelB="bottom_"+std::to_string(myContext.scope_counter);

        outStream.push_back(IntermediateRep(my_labelA, "N_A", "N_A", "N_A"));
        condition->convertIR(compare_reg, myContext, outStream);

        outStream.push_back(IntermediateRep("BEQ", compare_reg, "reg_0", my_labelB));

        branch->convertIR(dstreg, myContext, outStream);
        postLoopExp->convertIR(dstreg, myContext, outStream);
        
        outStream.push_back(IntermediateRep("J", "N_A", "N_A", my_labelA));

        outStream.push_back(IntermediateRep(my_labelB, "N_A", "N_A", "N_A"));
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

    virtual ~While()
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

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        outStream.push_back(IntermediateRep("ENTERLOCALSCOPE", "N_A", "N_A", "N_A"));
        myContext.enterScope();
        std::string compare_reg = myContext.makeRegName();
        std::string my_labelA="top_"+std::to_string(myContext.scope_counter);
        std::string my_labelB="bottom_"+std::to_string(myContext.scope_counter);
        outStream.push_back(IntermediateRep(my_labelA, "N_A", "N_A", "N_A"));
        condition->convertIR(compare_reg, myContext, outStream);
        outStream.push_back(IntermediateRep("BEQ", compare_reg, "reg_0", my_labelB));
        branch->convertIR(dstreg, myContext, outStream);
        outStream.push_back(IntermediateRep("J", "N_A", "N_A", my_labelA));
        outStream.push_back(IntermediateRep(my_labelB, "N_A", "N_A", "N_A"));
        outStream.push_back(IntermediateRep("EXITLOCALSCOPE", "N_A", "N_A", "N_A"));
        myContext.exitScope();
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

    virtual ~DoWhile()
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

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        outStream.push_back(IntermediateRep("ENTERLOCALSCOPE", "N_A", "N_A", "N_A"));
        myContext.enterScope();

        std::string compare_reg = myContext.makeRegName();
        std::string my_labelA="top_"+std::to_string(myContext.scope_counter);
        std::string my_labelB="bottom_"+std::to_string(myContext.scope_counter);
        outStream.push_back(IntermediateRep(my_labelA, "N_A", "N_A", "N_A"));
        branch->convertIR(dstreg, myContext, outStream);
        condition->convertIR(compare_reg, myContext, outStream);
        outStream.push_back(IntermediateRep("BEQ", compare_reg, "reg_0", my_labelB));
        outStream.push_back(IntermediateRep("J", "N_A", "N_A", my_labelA));
        outStream.push_back(IntermediateRep(my_labelB, "N_A", "N_A", "N_A"));

        outStream.push_back(IntermediateRep("EXITLOCALSCOPE", "N_A", "N_A", "N_A"));
        myContext.exitScope();
     }
};

class Break
    : public ASTNode
{
protected:

public:
    Break()
    {}

    virtual ~Break()
    {}

    virtual void printC(std::ostream &outStream) const {
        outStream<<"break";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        outStream<<"break";
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        outStream.push_back(IntermediateRep("ENTERLOCALSCOPE", "N_A", "N_A", "N_A"));
        myContext.enterScope();
        std::string my_label="bottom_"+std::to_string(myContext.scope_counter);
        outStream.push_back(IntermediateRep("J", "N_A", "N_A", my_label));
        outStream.push_back(IntermediateRep("EXITLOCALSCOPE", "N_A", "N_A", "N_A"));
        myContext.exitScope();
     }
};

class Continue
    : public ASTNode
{
protected:

public:
    Continue()
    {}

    virtual ~Continue()
    {}

    virtual void printC(std::ostream &outStream) const {
        outStream<<"continue";
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        outStream<<"continue";
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        std::string my_label="top_"+std::to_string(myContext.scope_counter);
        outStream.push_back(IntermediateRep("J", "N_A", "N_A", my_label));
     }
};

#endif
