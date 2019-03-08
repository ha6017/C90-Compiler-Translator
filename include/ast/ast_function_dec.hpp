#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>


#include "ast_node.hpp"
#include "ast_context.hpp"

// class FuncProto
//     : public ASTNode
// {
// protected:
//     std::string type;
//     std::string id;
//     //nodePtr myParamList;  //<---- subject to change 
// public:
//     FuncProto(std::string &_type, std::string &_id)
//         : type(_type)
//         , id(_id)
//     {}

//     virtual ~FuncProto()
//     { }
//     virtual void printC(std::ostream &outStream) const {}

//     virtual void printPython(std::ostream &outStream) const 
//     {
//         throw std::runtime_error("No python Impl");
        
//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        
//     }
// };

class FuncDef
    : public ASTNode
{
protected:
    std::string type;
    std::string id;
    nodePtr myNameList;  //<---- subject to change 
    nodePtr myBranch;
public:
    FuncDef(std::string &_type, std::string &_id, nodePtr _myNameList, nodePtr _myBranch )
        : type(_type)
        , id(_id)
        , myNameList(_myNameList)
        , myBranch(_myBranch)
    {}

    virtual ~FuncDef()
    {
        delete myNameList;
        delete myBranch;
    }

    virtual void printC(std::ostream &outStream) const {

    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        outStream<<id<<std::endl;
        //still need to use paramlist
        myNameList->printMips(dstreg,myContext,outStream);
        myBranch->printMips("reg_2", myContext, outStream);
        outStream<<"JR reg_31"<<std::endl;
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
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        Context newContext(myContext);
        myParamList->printMips(dstreg, newContext, outStream);
        newContext.enterScope();
        newContext.updateStackOffset();
        outStream<<"JAL "<<id<<std::endl;
        outStream<<"ADDU "<<dstreg<<"reg_2, "<<"reg_0"<<std::endl;
    }
};

#endif
