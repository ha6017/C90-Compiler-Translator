#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include <memory>

class ASTNode;

typedef const ASTNode *nodePtr;

class ASTNode
{
public:
    virtual ~ASTNode()
    {}

    virtual void printC(std::ostream &outStream) const {

    }

    virtual void printPython(std::ostream &outStream) const {
        throw std::runtime_error("No python Impl");
    
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const =0;
};


#endif
