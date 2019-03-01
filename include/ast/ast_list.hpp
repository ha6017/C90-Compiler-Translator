#ifndef ast_bitwise_op_hpp
#define ast_bitwise_op_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"

class BranchList: ASTNode
{
protected:


public:
    virtual ~ASTNode()
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
