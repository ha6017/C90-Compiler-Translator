#ifndef ast_function_dec_hpp
#define ast_function_dec_hpp

#include <string>
#include <iostream>
#include <cmath>

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
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {

     }
};

#endif
