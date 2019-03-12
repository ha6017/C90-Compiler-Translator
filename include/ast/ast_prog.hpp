#ifndef ast_prog_hpp
#define ast_prog_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>


#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class ProgList
    : public ASTNode
{
protected:
    nodePtr prog1;
    nodePtr proglist;
public:
    ProgList(nodePtr _prog1, nodePtr _proglist)
        : prog1(_prog1)
        , proglist(_proglist)
    {}

    virtual ~ProgList()
    { 
        delete prog1;
        delete proglist;
    }

    virtual void printC(std::ostream &outStream) const {}

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {

     }
};

class Prog
    : public ASTNode
{
protected:
    nodePtr Prog1;
public:
    Prog(nodePtr _Prog1 )
        : Prog1(_Prog1)
    {}

    virtual ~Prog()
    {
        delete Prog1;
    }

    virtual void printC(std::ostream &outStream) const {

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
