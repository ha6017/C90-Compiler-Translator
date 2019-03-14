#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>


#include "ast_node.hpp"
#include "ast_context.hpp"

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

    virtual void printC(std::ostream &outStream) const {
        outStream<<type<<" ";
        outStream<<id;
        outStream<<"();"<<std::endl; 
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        
    }
};

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

    virtual void printC(std::ostream &dst) const {
        dst<<type;
        dst<<" ";
		dst << id;
		dst << "(";
		if (myNameList != NULL){
			myNameList->printC(dst);
		}
		dst << ")";
        dst<<" {" << std::endl;
		if (myBranch!= NULL){
			myBranch->printC(dst);
			dst << std::endl;
		}
		dst<<" }" << std::endl;
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
        
        outStream<<"LW "<<"reg_fp"<<", "<<"0"<<" (reg_fp)"<<std::endl;
        
        outStream<<"JR reg_31"<<std::endl;
    }
};

// class FuncCall
//     : public ASTNode
// {
// protected:
//     std::string type;
//     nodePtr myParamList;  //<---- subject to change 
// public:
//     FuncCall(std::string &_type, nodePtr _myParamList)
//         : type(_type)
//         , myParamList(_myParamList)
//     {}

//     virtual ~FuncCall()
//     {
//         delete myParamList;
//     }

//     virtual void printC(std::ostream &outStream) const {

//     }

//     virtual void printPython(std::ostream &outStream) const 
//     {
//         throw std::runtime_error("No python Impl");
        
//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         Context newContext(myContext);
//         myParamList->printMips(dstreg, newContext, outStream);
        
//         outStream<<"ADDI "<<"reg_sp, "<<"reg_fp, "<<newContext.currentLocalPointer<<std::endl;
//         newContext.enterFunction();

//         // newContext.updateStackOffset();
//         // outStream<<"SW "<<"reg_fp"<<", "<<"reg_fp"<<myContext.createLocalInt(id)<<std::endl;
//         // outStream<<"SW "<<"reg_fp, "<<"reg_sp, "<<"reg_0"<<std::endl;
//         outStream<<"SW "<<"reg_fp"<<", "<<myContext.createLocalInt("framePointer")<<" (reg_fp)"<<std::endl;
//         outStream<<"ADDI "<<"reg_fp, "<<"reg_sp, "<<" 0"<<std::endl;
//         outStream<<"JAL "<<type<<std::endl;
//         outStream<<"ADDU "<<dstreg<<"reg_2, "<<"reg_0"<<std::endl;
//     }
// };

#endif
