#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>


#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class FuncProto
    : public ASTNode
{
protected:
    std::string type;
    std::string id;
    //nodePtr myParamList;  //<---- subject to change 
public:
    FuncProto(std::string &_type, std::string &_id)
        : type(_type)
        , id(_id)
    {}

    virtual ~FuncProto()
    { }
    virtual void printC(std::ostream &outStream) const {}

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {

     }
};

class FuncDef
    : public ASTNode
{
protected:
    std::string type;
    std::string id;
    nodePtr myParamList;  //<---- subject to change 
    nodePtr myBranch;
public:
    FuncDef(std::string &_type, std::string &_id, nodePtr _myParamList, nodePtr _myBranch )
        : type(_type)
        , id(_id)
        , myParamList(_myParamList)
        , myBranch(_myBranch)
    {}

    virtual ~FuncDef()
    {
        delete myParamList;
        delete myBranch;
    }

    virtual void printC(std::ostream &outStream) const {

    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {

     }
};

class FuncCall
    : public ASTNode
{
protected:
    std::string id;
    nodePtr myParamList;  //<---- subject to change 
public:
    FuncCall(std::string &_id, nodePtr _myParamList)
        : id(_id)
        , myParamList(_myParamList)
    {}

    virtual ~FuncCall()
    {
        delete myParamList;
    }

    virtual void printC(std::ostream &outStream) const {

    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {

    }
};

#endif
