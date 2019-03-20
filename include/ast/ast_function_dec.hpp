#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>


#include "ast_node.hpp"
#include "ast_context.hpp"

// class FuncProto: public ASTNode
// {
// protected:
//     std::string type;
//     std::string id;
// public:
//     FuncProto(const std::string &_type, std::string &_id)
//         : type(_type)
//         , id(_id)
//     {}

//     ~FuncProto()
//     { }

//     virtual void printC(std::ostream &outStream) const {
//         outStream<<type<<" ";
//         outStream<<id;
//         outStream<<"();"<<std::endl; 
//     }

//     virtual void printPython(std::ostream &outStream) const 
//     {
//         //throw std::runtime_error("No python Impl");
        
//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        
//     }
// };

class FuncDef: public ASTNode
{
public:
    std::string type;
    std::string id;
    nodePtr myNameList;  //<---- subject to change 
    nodePtr myBranch;

    FuncDef(const std::string &_type, const std::string &_id, nodePtr _myNameList, nodePtr _myBranch )
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

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
        outStream<<"def "<<id<<"(";
        if (myNameList != NULL){
            myNameList->printPython(outStream, tab);
        }
            outStream<<"):"<<std::endl;
            tab.indent++;
        for(int i=0;i<tab.global_var.size();i++){
            for(int i=tab.indent;i!=0;i--){
                outStream<<"\t";
            }
            outStream<<"global "<<tab.global_var[i]<<std::endl;
        }
            myBranch->printPython(outStream, tab);
            tab.indent--;

        // if(id=="main"){
        //     std::cout<<std::endl;
        //     std::cout<<"# Boilerplat"<<std::endl;
        //     std::cout<<"if __name__ == \"__main__\":"<<std::endl;
        //     std::cout<<"    import sys"<<std::endl;
        //     std::cout<<"    ret=main()"<<std::endl;
        //     std::cout<<"    sys.exit(ret)"<<std::endl;
        // }

    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {

        outStream<<id<<":"<<std::endl;
        if(myNameList!=NULL){
            myNameList->printMips(dstreg,myContext,outStream);
        }
        if(myBranch!=NULL){
            myBranch->printMips(dstreg, myContext, outStream);
        }
        outStream<<"LW "<<"$fp"<<", "<<"0"<<" ($fp)"<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"JR $31"<<std::endl;
        outStream<<"nop"<<std::endl;
    }
};

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
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {

        if(nextfunc!=NULL){
            nextfunc->printPython(outStream, tab);
            outStream<<std::endl;
        }
        func->printPython(outStream, tab);   
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        if(nextfunc!=NULL){
            //may have to consider putting a new context 
            nextfunc->printMips(dstreg,myContext,outStream);
            outStream<<std::endl;
        }
        func->printMips(dstreg,myContext,outStream);  
    }

};

class FuncCall: public ASTNode
{
protected:
    std::string type;
    std::string id;
    nodePtr myParamList;  //<---- subject to change 

public:
    FuncCall(const std::string &_type,const std::string &_id, nodePtr _myParamList)
        : type(_type)
        , id(_id)
        , myParamList(_myParamList)
    {}

    ~FuncCall()
    {
        if(myParamList!=NULL)   {delete myParamList;}
    }

    virtual void printC(std::ostream &outStream) const {
        // outStream<<type<<" "<<id<<"(";
        //  if(myParamList!=NULL){
        //      myParamList->printC(outStream);
        //  }
        // outStream<<");"<<std::endl;
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const 
    {
        outStream<<"def "<<id<<"("; //this is wrong, this is for a definition not a call
        if(myParamList!=NULL){
             myParamList->printPython(outStream, tab);
        }
        outStream<<")"<<std::endl; 
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        Context newContext(myContext);
        myParamList->printMips(dstreg, newContext, outStream);
        
        outStream<<"ADDI "<<"$sp, "<<"$fp, "<<newContext.currentLocalPointer<<std::endl;
        newContext.enterFunction();

        // newContext.updateStackOffset();
        // outStream<<"SW "<<"$fp"<<", "<<"$fp"<<myContext.createLocalInt(id)<<std::endl;
        // outStream<<"SW "<<"$fp, "<<"$sp, "<<"$0"<<std::endl;
        outStream<<"SW "<<"$fp"<<", "<<myContext.createLocalInt("framePointer")<<" ($sp)"<<std::endl;
        outStream<<"ADDI "<<"$fp, "<<"$sp, "<<" 0"<<std::endl;
        outStream<<"JAL "<<id<<std::endl;
        outStream<<"nop"<<std::endl;
        outStream<<"ADDU "<<dstreg<<"$2, "<<"$0"<<std::endl;
    }
};

#endif
