#ifndef ast_list_hpp
#define ast_list_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"
#include "ast_context.hpp"

class BranchList: ASTNode
{
protected:

    nodePtr statement;
    nodePtr myBranchList;

public:


    BranchList(nodePtr _statement,nodePtr _myBranchList)
        : statement(_statement)
        , myBranchList(_myBranchList)
    {}

    virtual void printC(std::ostream &outStream) const {
        statement->printC(outStream);//make it so that statement only uses the dstreg if has return!
        if(myBranchList!=NULL){
            myBranchList->printC(outStream);//need to account for the case where return is in the statement and also in the statement list, u want the first return.
        }
    }

    virtual void printPython(std::ostream &outStream) const {

    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {
        //detect return and end
        statement->convertIR(dstreg, myContext, outStream);//make it so that statement only uses the dstreg if has return!
        if(myBranchList!=NULL){
            myBranchList->convertIR(dstreg, myContext, outStream);//need to account for the case where return is in the statement and also in the statement list, u want the first return.
        }
    }
};

class ParamList : public ASTNode
{
protected:

    nodePtr param;
    nodePtr myParamList;

public:
    ParamList(nodePtr _param,nodePtr _paramList)
        : param(_param)
        , myParamList(_myParamList)
    {}

    virtual void printC(std::ostream &outStream) const {

    }

    virtual void printPython(std::ostream &outStream) const {


    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {

    }
};

class ArrayList: public ASTNode
{
protected:

    nodePtr exp;
    nodePtr myArrayList;

public:


    ArrayList(nodePtr _exp,nodePtr _myArrayList)
        :   exp(_exp)
        ,   myArrayList(_myArrayList)
        {}

    

    virtual void printC(std::ostream &outStream) const {
        // std::cout<<"{";
        // for(int i = 0; i < myArrayList.size();i++){
        //     myArrayList[i]->printC(outStream);
        //     if(i!=myArrayList.size()-1){
        //         std::cout<<", "<<std::endl;
        //     }
        // }
        // std::cout<<"}";

    }

    virtual void printPython(std::ostream &outStream) const {

        // std::cout<<"{";
        // for(int i = 0; i < myArrayList.size();i++){
        //     myArrayList[i]->printC(outStream);
        //     if(i!=myArrayList.size()-1){
        //         std::cout<<", ";
        //     }
        // }
        // std::cout<<"}";
    }


    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context myContext, std::vector<IntermediateRep> outStream) const {
        std::string exp_reg = myContext.findTemp();
        exp->convertIR(exp_reg, myContext, outStream);
        outStream<<"LW "<<exp_reg<<", "<<findLocalArrayElement(myContext.currentArrayName, myContext.currentArrayElement++)<<"(0)"<<std::endl;
        myContext.UnlockReg(exp_reg);

        if(myArrayList!=NULL){
            myArrayList->convertIR(dstreg, myContext,outStream);
        }
    }
};


class ProgList
    : public ASTNode
{
protected:
    nodePtr prog;
    nodePtr proglist;
public:
    ProgList(nodePtr _prog, nodePtr _proglist)
        : prog1(_prog)
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
    virtual void convertIR(std::string dstreg, Context myContext, std::ostream &outStream) const {

    }
};

#endif
