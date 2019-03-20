#ifndef ast_variable_dec_hpp
#define ast_variable_dec_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "ast_node.hpp"
#include "ast_context.hpp"


/*class DecInt
    : public ASTNode
{
protected:
    std::string var;
public:
    DecInt(std::string _var)
        : var(_var)
    {}


    virtual void printC(std::ostream &outStream) const {
        outStream<<"int "<<var;
    }

    virtual void printPython(std::ostream &outStream) const {
        //nothing
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        outStream.push_back(IntermediateRep("ADDI", var, "$0", "0"));
    }
};*/

// class LocalInitInt
//     : public ASTNode
// {
// protected:
//     std::string type;
//     std::string var;
//     nodePtr exp;
// public:
//     LocalInitInt(std::string &_type, std::string &_var, nodePtr _exp)
//         :   var(_var)
//         ,   exp(_exp)
//         ,   type(_type)
//     {}

//     ~LocalInitInt()
//     {
//         if(exp!=NULL){
//             delete exp;
//         }   
//     }

//     virtual void printC(std::ostream &outStream) const {
//         outStream<<type<<" "<<var;
//         if(exp!=NULL){
//             outStream<<std::endl;
//             exp->printC(outStream);
//         }
//         outStream<<";"<<std::endl;
//     }

//     virtual void printPython(std::ostream &outStream) const {
//         outStream<<var<<" = ";
//         exp->printPython(outStream);
//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//      virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         std::string exp_reg = myContext.findTemp();
//         exp->printMips(exp_reg, myContext, outStream);
//         outStream<<"SW "<<exp_reg<<", "<<myContext.createLocalInt(var)<<" (reg_fp)"<<std::endl;

//         myContext.UnlockReg(exp_reg);
//     }
// };

class Dec_Var_List
    : public ASTNode
{
protected:
    nodePtr current_dec;
    nodePtr next_dec;
public:
    Dec_Var_List(nodePtr _current_dec, nodePtr _next_dec)
        :   current_dec(_current_dec)
        ,   next_dec(_next_dec)  
    {}

    ~Dec_Var_List()
    {
        if(next_dec!=NULL){
            delete next_dec;
        }   
        delete current_dec;
    }

    virtual void printC(std::ostream &outStream) const {
        if(next_dec!=NULL){
                next_dec->printC(outStream);
                outStream<<",";
            }
            current_dec->printC(outStream);
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const {
        if(next_dec!=NULL){
                next_dec->printPython(outStream, tab);
                outStream<<std::endl;
            }
            current_dec->printPython(outStream, tab);
    }

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
        current_dec->printMips(dstreg,myContext,outStream);
        if(next_dec!=NULL){
            next_dec->printMips(dstreg,myContext,outStream);
            outStream<<std::endl;
        }
    }
};


class GlobalDeclare
    : public ASTNode
{
    public:
        std::string id;
        double input;
        bool noInput;

        GlobalDeclare(std::string &_id, double _input):
        id(_id), input(_input), noInput(false){}
        GlobalDeclare(std::string &_id):
        id(_id), noInput(true){}

    ~GlobalDeclare(){}

    virtual void printC(std::ostream &outStream) const {
        outStream<<id;
            if(noInput==false){
                outStream<<"="<<input;
            }
    }

    virtual void printPython(std::ostream &outStream, IndentAdd &tab) const {
            tab.global_var.push_back(id);
            outStream<<id;
            if(noInput==false){
                outStream<<"="<<input;
            } else {
                outStream<<"=0";
            }
    }

    //! Evaluate the tree using the given mapping of variables to numbers
     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {

        std::string var_reg = myContext.findTemp();
        if(noInput){
            outStream<<"ADDI "<<var_reg<<", "<<"reg_0"<<", 0"<<std::endl;
        }else{
            outStream<<"ADDI "<<var_reg<<", "<<"reg_0"<<", "<<(int)input<<std::endl;
        }
        outStream<<"SW "<<var_reg<<", "<<myContext.createGlobalInt(id)<<"(0)"<<std::endl;
        myContext.UnlockReg(var_reg);
    }
};



// class LocalInitArray
//     : public ASTNode
// {
// protected:
//     std::string var;
//     int size;
//     nodePtr myArrayList;
// public:
//     LocalInitArray(std::string &_var, int _size, nodePtr _myArrayList)
//         :   var(_var)
//         ,   size(_size)
//         ,   myArrayList(_myArrayList)
//     {}

//     ~LocalInitArray(){
//         delete myArrayList;
//     }

//     virtual void printC(std::ostream &outStream) const {
//         outStream<<"int "<<var<<"["<<size<<"] = {";
//         myArrayList->printC(outStream);
//         outStream<<"}";
//     }

//     virtual void printPython(std::ostream &outStream) const {
//         //nothing
//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         unsigned int arrayLocation=myContext.createLocalArray(var,size);
//         if(myArrayList!=NULL){
//             myContext.currentArrayElement=0;
//             myContext.currentArrayName=var;
//             myArrayList->printMips(dstreg, myContext, outStream);
//         }else{
//             for(int i=0;i<size;i++){
//                 outStream<<"LW "<<"$0"<<", "<<(arrayLocation+i*4)<<"($fp)"<<std::endl; 
//             }
//         }
//     }
// };

// class GlobalInitInt
//     : public ASTNode
// {
// protected:
//     std::string type;
//     std::string var;
//     nodePtr exp;
// public:
//     GlobalInitInt(std::string &_type, std::string &_var, nodePtr _exp)
//         :  type(_type)
//         , var(_var)
//         ,   exp(_exp)   
//     {}

//     virtual ~GlobalInitInt()
//     {
//         if(exp!=NULL)
//         {
//                delete exp;
//         }
        
//     }

//     virtual void printC(std::ostream &outStream) const {
//         outStream<<type<<" "<<var<<" = ";
//         if(exp!=NULL){
//             exp->printC(outStream);
//         }
        
//     }

//     virtual void printPython(std::ostream &outStream) const {
//         outStream<<var<<" = ";
//         exp->printPython(outStream);
//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//      virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         std::string exp_reg = myContext.findTemp();
//         exp->printMips(exp_reg, myContext, outStream);
//         std::string var_reg = myContext.findTemp();
//         outStream<<"ADDU "<<var_reg<<", "<<"reg_0"<<", "<< exp_reg<<std::endl;
//         outStream<<"SW "<<var_reg<<", "<<myContext.createGlobalInt(var)<<"(0)"<<std::endl;
//         myContext.UnlockReg(var_reg);
//         myContext.UnlockReg(exp_reg);
//     }
// };

// class GlobalInitArray
//     : public ASTNode
// {
// protected:
//     std::string var;
//     int size;
//     nodePtr myArrayList;
// public:
//     GlobalInitArray(std::string &_var, int _size, nodePtr _myArrayList)
//         :   var(_var)
//         ,   size(_size)
//         ,   myArrayList(_myArrayList)
//     {}

//     ~GlobalInitArray(){
//         delete myArrayList;
//     }

//     virtual void printC(std::ostream &outStream) const {
//         outStream<<"int "<<var<<"["<<size<<"] = {";
//         myArrayList->printC(outStream);
//         outStream<<"}";
//     }

//     virtual void printPython(std::ostream &outStream) const {
//         //nothing
//     }

//     //! Evaluate the tree using the given mapping of variables to numbers
//     virtual void printMips(std::string dstreg, Context &myContext, std::ostream &outStream) const {
//         unsigned int arrayLocation=myContext.createGlobalArray(var,size);
//         if(myArrayList!=NULL){
//             myContext.currentArrayElement=0;
//             myContext.currentArrayName=var;
//             myArrayList->printMips(dstreg, myContext, outStream);
//         }else{
//             for(int i=0;i<size;i++){
//                 outStream<<"LW "<<"$0"<<", "<<(arrayLocation+i*4)<<"(0)"<<std::endl; 
//             }
//         }
//     }
// };



#endif
