#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>
#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class ASTnode;

typedef const ASTnode *nodePtr;

class ASTNode
{
public:
    virtual ~ASTnode()
    {}

    virtual void printC(std::ostream &outStream) const {

    }

    virtual void printPython(std::ostream &outStream) const {
        throw std::runtime_error("No python Impl");
    
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const =0;
};


#endif
