#ifndef ast_list_hpp
#define ast_list_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"
#include "intermediate_rep.hpp"

class BranchList : public ASTNode
{
protected:

    nodePtr statement;
    nodePtr myBranch;

public:
    BranchList(nodePtr _statement,nodePtr _myBranch)
        : statement(_statement)
        , myBranch(_myBranch)
    {}

    virtual void printC(std::ostream &outStream) const {
        statement->printC(outStream);//make it so that statement only uses the dstreg if has return!
        outStream<<";"<<std::endl;
        if(myBranch!=NULL){
            myBranch->printC(outStream);//need to account for the case where return is in the statement and also in the statement list, u want the first return.
        }
    }

    virtual void printPython(std::ostream &outStream) const {
    
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {
        //detect return and end
        statement->convertIR(dstreg, myContext, IRlist);//make it so that statement only uses the dstreg if has return!
        if(myBranch!=NULL){
            myBranch->convertIR(dstreg, myContext, IRlist);//need to account for the case where return is in the statement and also in the statement list, u want the first return.
        }
    }
};

/*class ArrayList: public ASTNode
{
protected:

    std::vector<nodePtr> myArrayList;

public:


    ArrayList(std::vector<nodePtr> &_myArrayList)
    {
        myArrayList=_myArrayList;
    }

    virtual void printC(std::ostream &outStream) const {
        outStream<<"{";
        for(int i = 0; i < myArrayList.size();i++){
            myArrayList[i]->printC(outStream);
            if(i!=myArrayList.size()-1){
                outStream<<", "<<std::endl;
            }
        }
        outStream<<"}";
    }

    virtual void printPython(std::ostream &outStream) const {

        outStream<<"{";
        for(int i = 0; i < myArrayList.size();i++){
            myArrayList[i]->printC(outStream);
            if(i!=myArrayList.size()-1){
                outStream<<", ";
            }
        }
        outStream<<"}";
    }
  

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void convertIR(std::string dstreg, Context &myContext, std::vector<IntermediateRep> &IRlist) const {
        
    }
};*/

#endif