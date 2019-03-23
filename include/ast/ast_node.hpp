#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include <memory>

#include "ast_context.hpp"

class ASTNode;

class IndentAdd
{
public:
    int indent;

    std::vector<std::string> global_var;
    std::vector<std::string> global_array;

    //std::string currentType;

    IndentAdd():
        indent(0) {}

    ~IndentAdd(){}
};

typedef const ASTNode *nodePtr;

class ASTNode
{
public:
    virtual ~ASTNode()
    {}

    virtual void printC(std::ostream &outStream) const {

    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const {};

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {};

    // void printPython(std::ostream &outStream){
    //     IndentAdd tab;
    //     printPython(outStream, tab);
    // }
};


#endif
