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
public:
    FuncProto(std::string &_type, std::string &_id)
        : type(_type)
        , id(_id)
    {}

    ~FuncProto()
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

    ~FuncDef()
    {
        if(myNameList!=NULL) {delete myNameList;}
        if(myBranch!=NULL) {delete myBranch;}
    }

    virtual void printC(std::ostream &outStream) const {
        outStream<<type<<" "<< id<<"(";
		if (myNameList != NULL){
			myNameList->printC(outStream);
		}
		outStream << ")"<<" {" << std::endl;
		if (myBranch!= NULL){
			myBranch->printC(outStream);
			outStream << std::endl;
		}
		outStream<<" }" << std::endl;
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

<<<<<<< HEAD
class FuncCall
    : public ASTNode
{
protected:
    std::string type;
    nodePtr myParamList;  //<---- subject to change 
public:
    FuncCall(std::string &_type, nodePtr _myParamList)
        : type(_type)
        , myParamList(_myParamList)
    {}

    virtual ~FuncCall()
    {
        delete myParamList;
    }

    virtual void printC(std::ostream &outStream) const {

=======
class Top_List : public ASTNode{

    public:
        nodePtr func;
        nodePtr nextfunc;

    Top_List(nodePtr _func, nodePtr _nextfunc)
        : func(_func)
        , nextfunc(_nextfunc)
    {}

    virtual void printC(std::ostream &dst) const {
        if(nextfunc!=NULL){
            nextfunc->printC(dst);
            dst<<std::endl;
        }
        func->printC(dst);
>>>>>>> 0553b77468247b3ad501efa0eb79243ef595e5d6
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
<<<<<<< HEAD
        Context newContext(myContext);
        myParamList->printMips(dstreg, newContext, outStream);
        
=======
        
    }

};

class FuncCall
    : public ASTNode
{
protected:
    std::string type;
    std::string id;
    nodePtr myParamList;  //<---- subject to change 
public:
    FuncCall(std::string &_type, std::string &_id, nodePtr _myParamList)
        : type(_type)
        , id(_id)
        , myParamList(_myParamList)
    {}

    ~FuncCall()
    {
        if(myParamList!=NULL)   {delete myParamList;}
    }

    virtual void printC(std::ostream &outStream) const {
        outStream<<type<<" "<<"(";
        myParamList->printC(outStream);
        outStream<<");"<<std::endl;
    }

    virtual void printPython(std::ostream &outStream) const 
    {
        throw std::runtime_error("No python Impl");
        
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        Context newContext(myContext);
        myParamList->printMips(dstreg, newContext, outStream);
        
>>>>>>> 0553b77468247b3ad501efa0eb79243ef595e5d6
        outStream<<"ADDI "<<"reg_sp, "<<"reg_fp, "<<newContext.currentLocalPointer<<std::endl;
        newContext.enterFunction();

        // newContext.updateStackOffset();
        // outStream<<"SW "<<"reg_fp"<<", "<<"reg_fp"<<myContext.createLocalInt(id)<<std::endl;
        // outStream<<"SW "<<"reg_fp, "<<"reg_sp, "<<"reg_0"<<std::endl;
<<<<<<< HEAD
        outStream<<"SW "<<"reg_fp"<<", "<<myContext.createLocalInt("framePointer")<<" (reg_sp)"<<std::endl;
=======
        outStream<<"SW "<<"reg_fp"<<", "<<myContext.createLocalInt("framePointer")<<" (reg_fp)"<<std::endl;
>>>>>>> 0553b77468247b3ad501efa0eb79243ef595e5d6
        outStream<<"ADDI "<<"reg_fp, "<<"reg_sp, "<<" 0"<<std::endl;
        outStream<<"JAL "<<type<<std::endl;
        outStream<<"ADDU "<<dstreg<<"reg_2, "<<"reg_0"<<std::endl;
    }
};

#endif
