#ifndef ast_list_hpp
#define ast_list_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "ast_node.hpp"
#include "ast_context.hpp"

class BranchList: public ASTNode
{
protected:

    nodePtr statement;
    nodePtr myBranchList;

public:


    BranchList(nodePtr _statement,nodePtr _myBranchList)
        : statement(_statement)
        , myBranchList(_myBranchList)
    {}

    ~BranchList(){
        delete statement;
        if(myBranchList!=NULL){delete myBranchList;}
    }

    virtual void printC(std::ostream &outStream) const {
        
        if(myBranchList!=NULL){
            myBranchList->printC(outStream);//need to account for the case where return is in the statement and also in the statement list, u want the first return.
        }
        statement->printC(outStream);//make it so that statement only uses the dstreg if has return!
        outStream<<std::endl;
    }

    virtual void printPython(std::ostream &outStream , IndentAdd &tab) const {
        if(statement!=NULL){
            if(myBranchList!=NULL){
                    myBranchList->printPython(outStream, tab);
            }
            statement->printPython(outStream, tab);
            outStream<<std::endl;
        }
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        //detect return and end
        if(myBranchList!=NULL){
            myBranchList->printMips(dstreg, myContext, outStream);//need to account for the case where return is in the statement and also in the statement list, u want the first return.
        }
        statement->printMips(dstreg, myContext, outStream);//problem is with the
    }
};

// class ParamList : public ASTNode
// {
// protected:

//     nodePtr param;
//     nodePtr myParamList;

// public:
//     ParamList(nodePtr _param,nodePtr _myParamList)
//         : param(_param)
//         , myParamList(_myParamList)
//     {}

//     ~ParamList(){
//         delete param;
//         delete myParamList;
//     }

//     virtual void printC(std::ostream &outStream) const {
//         param->printC(outStream);
//         if(myParamList!=NULL){
//             outStream<<", ";
//             myParamList->printC(outStream);
//         }
//     }

//     virtual void printPython(std::ostream &outStream) const {

//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         std::string param_var=myContext.findParam();
//         param->printMips(param_var, myContext, outStream);
//         if(myParamList!=NULL){
//             myParamList->printMips(dstreg, myContext, outStream);
//         }
//     }
// };


// class NameList : public ASTNode
// {
// protected:

//     std::string name;
//     nodePtr myNameList;

// public:
//     NameList(std::string &_name,nodePtr _myNameList)
//         : name(_name)
//         , myNameList(_myNameList)
//     {}

//     ~NameList() {
//         delete myNameList;
//     }

//     virtual void printC(std::ostream &outStream) const {
//         outStream<<name<<", ";
//         if(myNameList!=NULL){
//             myNameList->printC(outStream);
//         }
//     }

//     virtual void printPython(std::ostream &outStream) const {

//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {

//         outStream<<"SW "<<myContext.retrieveParam()<<", "<<myContext.createLocalInt(name)<<"($0)"<<std::endl;

//         if(myNameList!=NULL){
//             myNameList->printMips(dstreg, myContext, outStream);//Does this list really nead the pointer
//         }
//     }
// };

// class ArrayList: public ASTNode
// {
// protected:

//     nodePtr exp;
//     nodePtr myArrayList;

// public:


//     ArrayList(nodePtr _exp,nodePtr _myArrayList)
//         :   exp(_exp)
//         ,   myArrayList(_myArrayList)
//         {}

//     ~ArrayList(){
//         delete exp;
//         delete myArrayList;
//     }

//     virtual void printC(std::ostream &outStream) const {
//         // std::cout<<"{";
//         // for(int i = 0; i < myArrayList.size();i++){
//         //     myArrayList[i]->printC(outStream);
//         //     if(i!=myArrayList.size()-1){
//         //         std::cout<<", "<<std::endl;
//         //     }
//         // }
//         // std::cout<<"}";

//     }

//     virtual void printPython(std::ostream &outStream) const {

//         // std::cout<<"{";
//         // for(int i = 0; i < myArrayList.size();i++){
//         //     myArrayList[i]->printC(outStream);
//         //     if(i!=myArrayList.size()-1){
//         //         std::cout<<", ";
//         //     }
//         // }
//         // std::cout<<"}";
//     }


//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         std::string exp_reg = myContext.findTemp();
//         exp->printMips(exp_reg, myContext, outStream);
//         outStream<<"LW "<<exp_reg<<", "<<myContext.findLocalArrayElement(myContext.currentArrayName, myContext.currentArrayElement++)<<"($0)"<<std::endl;
//         outStream<<"nop"<<std::endl;
//         myContext.UnlockReg(exp_reg);

//         if(myArrayList!=NULL){
//             myArrayList->printMips(dstreg, myContext,outStream);
//         }
//     }
// };


// class ProgList
//     : public ASTNode
// {
// protected:
//     nodePtr prog;
//     nodePtr proglist;
// public:
//     ProgList(nodePtr _prog, nodePtr _proglist)
//         : prog(_prog)
//         , proglist(_proglist)
//     {}

//     virtual ~ProgList()
//     { 
//         delete prog;
//         delete proglist;
//     }

//     virtual void printC(std::ostream &outStream) const {
//         prog->printC(outStream);
//         outStream<<std::endl;
//         proglist->printC(outStream);
//     }

//     virtual void printPython(std::ostream &outStream) const 
//     {
//         // throw std::runtime_error("No python Impl");
        
//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         Context newContext(myContext);
//         prog->printMips(dstreg,newContext,outStream);
//         if(proglist!=NULL){
//             proglist->printMips(dstreg,myContext,outStream);
//         }
//     }
// };

// class Program : public ASTNode
// {
// public:
// 	public:
// 	nodePtr SingleProgram;
 
	
//     Program(nodePtr _SingleProgram) :
//         SingleProgram(_SingleProgram) {}

//     ~Program()
//     {
//         delete SingleProgram;
//     }
	
// 	virtual void printC(std::ostream &outStream) const override{
		
//         SingleProgram->printC(outStream);
//         outStream<<std::endl;
// 	}

//     virtual void printPython(std::ostream &dst) const override
//     {
        
//     }
   
// 	virtual void printMips(std::ostream &dst, Context &cont, int RegisterLock) const {
		
// 	}

// };

class Argument: public ASTNode
{
    protected: 
        std::string argType;
        std::string argId;
        nodePtr nextArguments;
    public:
        Argument(std::string &_argType, std::string &_argId, nodePtr _nextArguments):
            argType(_argType), argId(_argId), nextArguments(_nextArguments){}

    ~Argument()
    {
        if(nextArguments!=NULL){delete nextArguments;}
    }
	
	virtual void printC(std::ostream &outStream) const {
		if(nextArguments!=NULL){
            nextArguments->printC(outStream);
            outStream<<",";
        }
        outStream<<argType<<" "<<argId;
	}

    virtual void printPython(std::ostream &dst, IndentAdd &tab) const 
    {
        if(nextArguments!=NULL){
            nextArguments->printPython(dst, tab);
            dst<<",";
        }
        dst<<argId;
    }
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        if(nextArguments!=NULL){
            nextArguments->printMips(dstreg, myContext, outStream);
        }
        outStream<<"SW "<<"$"<<std::to_string(4+myContext.paramCount++)<<", "<<myContext.createLocalInt(argId)<<"($fp)"<<std::endl;

    }
};

class ArgumentNoType : public ASTNode
{
    public:
        nodePtr arg;
        nodePtr nextArguments;
    
    ArgumentNoType( nodePtr _arg, nodePtr _nextArguments):
            arg(_arg), nextArguments(_nextArguments){}

    ~ArgumentNoType()
    {
        if(nextArguments!=NULL){delete nextArguments;}
    }
	
	virtual void printC(std::ostream &outStream) const override{
		 if(arg!=NULL){
                if(nextArguments!=NULL){
                    nextArguments->printC(outStream);
                    outStream<<",";
                }
                arg->printC(outStream);
            }
	}

    virtual void printPython(std::ostream &dst, IndentAdd &tab) const override
    {
        if(arg!=NULL){
            if(nextArguments!=NULL){
                nextArguments->printPython(dst, tab);
                dst<<",";
            }
            arg->printPython(dst, tab);
        }
    }
   
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        //nextarguments is a list
        if(nextArguments!=NULL){
            nextArguments->printMips("HELELELWKRLWENRKNEWKRNWEKLNKLRENKLNEWR", myContext, outStream);
        }
        std::string param_var="$"+std::to_string(4+myContext.paramCount);
        myContext.paramCount++;
        arg->printMips(param_var, myContext, outStream);

    }
};


// class ParamList : public ASTNode
// {
// protected:

//     nodePtr param;
//     nodePtr myParamList;

// public:
//     ParamList(nodePtr _param,nodePtr _myParamList)
//         : param(_param)
//         , myParamList(_myParamList)
//     {}

//     ~ParamList(){
//         delete param;
//         delete myParamList;
//     }

//     virtual void printC(std::ostream &outStream) const {
//         param->printC(outStream);
//         if(myParamList!=NULL){
//             outStream<<", ";
//             myParamList->printC(outStream);
//         }
//     }

//     virtual void printPython(std::ostream &outStream) const {

//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         std::string param_var=myContext.findParam();
//         param->printMips(param_var, myContext, outStream);
//         if(myParamList!=NULL){
//             myParamList->printMips(dstreg, myContext, outStream);
//         }
//     }
// };


// class NameList : public ASTNode
// {
// protected:

//     std::string name;
//     nodePtr myNameList;

// public:
//     NameList(std::string &_name,nodePtr _myNameList)
//         : name(_name)
//         , myNameList(_myNameList)
//     {}

//     ~NameList() {
//         delete myNameList;
//     }

//     virtual void printC(std::ostream &outStream) const {
//         outStream<<name<<", ";
//         if(myNameList!=NULL){
//             myNameList->printC(outStream);
//         }
//     }

//     virtual void printPython(std::ostream &outStream) const {

//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {

//         outStream<<"SW "<<myContext.retrieveParam()<<", "<<myContext.createLocalInt(name)<<"(0)"<<std::endl;

//         if(myNameList!=NULL){
//             myNameList->printMips(dstreg, myContext, outStream);//Does this list really nead the pointer
//         }
//     }
// };

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

    ~ArrayList(){
        if(exp!=NULL){delete exp;}
        if(myArrayList!=NULL){ delete myArrayList;}
    }

    virtual void printC(std::ostream &outStream) const {
        if(exp!=NULL){
            if(myArrayList!=NULL){
                myArrayList->printC(outStream);
                outStream<<",";
            }
            exp->printC(outStream);
        }
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const {
        if(exp!=NULL){
            if(myArrayList!=NULL){
                myArrayList->printPython(outStream, tab);
                outStream<<",";
            }
            exp->printPython(outStream, tab);
        }
    }


    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        
        std::string exp_reg = myContext.findTemp();
        exp->printMips(exp_reg, myContext, outStream);

        outStream<<"SW "<<exp_reg<<", "<<myContext.findLocalArrayElement(myContext.currentArrayName, myContext.currentArrayElement)<<"($fp)"<<std::endl;
        myContext.currentArrayElement++;
        myContext.UnlockReg(exp_reg);

        if(myArrayList!=NULL){
            myArrayList->printMips(dstreg, myContext,outStream);
        }
        
    }
};


class GlobalArrayList: public ASTNode
{
protected:

    int num;
    nodePtr next_num;

public:


    GlobalArrayList(nodePtr _next_num,int _num)
        :   num(_num)
        ,   next_num(_next_num)
        {}

    ~GlobalArrayList(){
        if(next_num!=NULL){delete next_num;}
    }

    virtual void printC(std::ostream &outStream) const {
            if(next_num!=NULL){
                next_num->printC(outStream);
                outStream<<",";
            }
            //exp->printC(outStream);
            outStream<<num;
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const {
        // if(exp!=NULL){
        //     if(myArrayList!=NULL){
        //         myArrayList->printPython(outStream, tab);
        //         outStream<<",";
        //     }
        //     exp->printPython(outStream, tab);
        // }
        if(next_num!=NULL){
                next_num->printPython(outStream, tab);
                outStream<<",";
            }
            //exp->printC(outStream);
            outStream<<num;
    }


    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        outStream<<".word "<<num<<std::endl;      
        if(next_num!=NULL){
            next_num->printMips(dstreg, myContext,outStream);
        }
    }
};

class EnumList : public ASTNode 
{
protected:
    nodePtr myEnumList;
    std::string name;
    int val;
public:
    EnumList(nodePtr _myEnumList, std::string &_name, int _val)
        :   myEnumList(_myEnumList)
        ,   name(_name)
        ,   val(_val)
        {}

    ~EnumList(){
        if(myEnumList!=NULL){delete myEnumList;}
    }
    virtual void printC(std::ostream &outStream) const {

    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const {

    }


    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        if(myEnumList!=NULL){
            myEnumList->printMips(dstreg, myContext, outStream);
        }
        std::string exp_reg = myContext.findTemp();
        if(val==-293){
            int currentVal=++myContext.prevEnumVal;
            outStream<<"ADDI "<<exp_reg<<", $0, "<<currentVal<<std::endl;
        }else{
            myContext.prevEnumVal=val;
            outStream<<"ADDI "<<exp_reg<<", $0, "<<val<<std::endl;
        }
        outStream<<"SW "<<exp_reg<<", "<<myContext.createLocalInt(name)<<" ($fp)"<<std::endl;
        myContext.UnlockReg(exp_reg);



    }


};
// class ProgList
//     : public ASTNode
// {
// protected:
//     nodePtr prog;
//     nodePtr proglist;
// public:
//     ProgList(nodePtr _prog, nodePtr _proglist)
//         : prog(_prog)
//         , proglist(_proglist)
//     {}

//     virtual ~ProgList()
//     { 
//         delete prog;
//         delete proglist;
//     }

//     virtual void printC(std::ostream &outStream) const {
//         prog->printC(outStream);
//         outStream<<std::endl;
//         proglist->printC(outStream);
//     }

//     virtual void printPython(std::ostream &outStream) const 
//     {
//         throw std::runtime_error("No python Impl");
        
//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         Context newContext(myContext);
//         prog->printMips(dstreg,newContext,outStream);
//         if(proglist!=NULL){
//             proglist->printMips(dstreg,myContext,outStream);
//         }
//     }
// };

// class Program : public ASTNode
// {
// public:
// 	public:
// 	nodePtr SingleProgram;
 
	
//     Program(nodePtr _SingleProgram) :
//         SingleProgram(_SingleProgram) {}

//     ~Program()
//     {
//         delete SingleProgram;
//     }
	
// 	virtual void printC(std::ostream &outStream) const override{
		
//         SingleProgram->printC(outStream);
//         outStream<<std::endl;
// 	}

//     virtual void printPython(std::ostream &dst) const override
//     {
        
//     }
   
// 	virtual void printMips(std::ostream &dst, Context &cont, int RegisterLock) const {
		
// 	}

// };


#endif
