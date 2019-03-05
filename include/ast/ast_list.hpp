#ifndef ast_list_hpp
#define ast_list_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"

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
    virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {
        //detect return and end
        statement->convertIR(dstreg, myContext, IRlist);//make it so that statement only uses the dstreg if has return!
        if(myBranchList!=NULL){
            myBranchList->convertIR(dstreg, myContext, IRlist);//need to account for the case where return is in the statement and also in the statement list, u want the first return.
        }
    }
};

class ParamList : public ASTNode
{
protected:

    nodePtr param;
    nodePtr paramList;

public:
    ParamList(nodePtr _statement,nodePtr _myBranch)
        : param(_param)
        , paramList(_paramList)
    {}

    virtual void printC(std::ostream &outStream) const {

    }

    virtual void printPython(std::ostream &outStream) const {


    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {

    }
};

/*class ArrayList: public ASTNode
{
protected:

    std::vector<nodePtr> myArrayList;

public:


    BranchList(std::vector<nodePtr> _myArrayList)
    {
        myArrayList=_myArrayList;
    }

    virtual void printC(std::ostream &outStream) const {
        std::cout<<"{";
        for(int i = 0; i < myArrayList.size();i++){
            myArrayList[i]->printC(outStream);
            if(i!=myArrayList.size()-1){
                std::cout<<", "<<std::endl;
            }
        }
        std::cout<<"}";

    }

    virtual void printPython(std::ostream &outStream) const {

        std::cout<<"{";
        for(int i = 0; i < myArrayList.size();i++){
            myArrayList[i]->printC(outStream);
            if(i!=myArrayList.size()-1){
                std::cout<<", ";
            }
        }
        std::cout<<"}";
    }


    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> IRlist) const {

    }
};*/

#endif
