#ifndef ast_context_hpp
#define ast_context_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

static int label_counter=0;



class Context
{

public:
    unsigned int currentGlobalPointer;
    unsigned int currentLocalPointer;
    int scopeCountPerScope;

    std::map<std::string, unsigned int>globals;
    std::map<std::string, unsigned int>locals;
    std::map<std::string, std::string>funcNameToLabel;
    int funcLabelCounter;
    unsigned int stackOffset;
    bool freeRegs[32]; //0 is locked, 1 is unlocked
    int scope_counter;
    int currentArrayElement;    //used for array init
    std::string currentArrayName;   //used for array init


    Context(){
        scope_counter=0;
        funcLabelCounter=0;
        stackOffset =0x20000000;
        currentGlobalPointer=0x20000000;
        currentLocalPointer=0x20400000;
        currentArrayElement=0; //this is for arraylist
        scopeCountPerScope=0;

        //CREATE FOR LOOP TO FREE THE TEMPS

    }
    Context(const Context &inContext){
        //I NEED TO CREATE COPY CONSTRUCTOR AND CHANGE EVERYTHING TO PASS BY REFERENCE. THEN FIGURE OUT FUNCTION LABEL MAPPINGS
        globals=inContext.globals;
        globals=inContext.locals;
        funcNameToLabel=inContext.funcNameToLabel;
        funcLabelCounter=inContext.funcLabelCounter;
        funcLabelCounter=inContext.funcLabelCounter;
        for(int i=0;i<32;i++){
            freeRegs[i]=inContext.freeRegs[i];
        }
        scope_counter=inContext.scope_counter;
        currentArrayElement=inContext.currentArrayElement;
        currentArrayName=inContext.currentArrayName;
        currentGlobalPointer=inContext.currentGlobalPointer;
        currentLocalPointer=inContext.currentLocalPointer;
        scopeCountPerScope=inContext.scopeCountPerScope;
    }

    std::string makeLabelName(){
        return "L_"+ std::to_string(label_counter++); //need to make label_counter global
    }
    std::string makeScopedLabelID(){
        return std::to_string(scope_counter)+"_"+std::to_string(scopeCountPerScope);
    }
    void enterScope(){
        scope_counter++;
        //set number of labels in scope  =0 
    }
    // void exitScope(){
    //     scope_counter--;
    // }

    std::string findTemp(){
        for(int i=8;i<16;i++){
            if(freeRegs[i]==1){
                freeRegs[i]=0;
                return "reg_"+std::to_string(i);
            }
        }
        for(int i=24;i<26;i++){
            if(freeRegs[i]==1){
                freeRegs[i]=0;
                return "reg_"+std::to_string(i);
            }
        }
    }

    std::string findParam(){
        for(int i=4;i<8;i++){
            if(freeRegs[i]==1){
                freeRegs[i]=0;
                return "reg_"+std::to_string(i);
            }
        }
    }
    void UnlockReg(std::string RegName){
        int index=std::stoi(RegName.substr(4));
        freeRegs[index]=1;
    }
    std::string retrieveParam(){
        for(int i=4;i<8;i++){
            if(freeRegs[i]==0){
                freeRegs[i]=1;
                return "reg_"+std::to_string(i);
            }
        }
    }
    unsigned int createGlobalInt(std::string name){
        globals[name]=currentGlobalPointer;
        currentGlobalPointer=currentGlobalPointer+4;
        return currentGlobalPointer-4;
    }
    unsigned int createLocalInt(std::string name){
        locals[name]=currentLocalPointer;
        currentLocalPointer=currentLocalPointer+4;
        return currentLocalPointer-4;
    }
    unsigned int findGlobalInt(std::string name){
        return globals[name];
    }
    unsigned int findLocalInt(std::string name){
        if(locals[name]>=stackOffset){
            return locals[name];
        }else{
            throw "Variable "+name+" has not yet been declared.\n";
        }
    }
    void updateStackOffset(){
        stackOffset=currentLocalPointer;
    }

    unsigned int createGlobalArray(std::string name, int size){
        globals[name]=currentGlobalPointer;
        currentGlobalPointer=currentGlobalPointer+4*size;
        return currentGlobalPointer-4*size;
    }
    unsigned int createLocalArray(std::string name, int size){
        locals[name]=currentLocalPointer;
        currentLocalPointer=currentLocalPointer+4*size;
        return currentLocalPointer-4*size;
    }
    unsigned int findLocalArrayElement(std::string name, int index){
        return globals[name]+4*index;
    }
    unsigned int findGlobalArrayElement(std::string name, int index){
        return locals[name]+4*index;
    }
    void addFunction(std::string funcName){
        funcNameToLabel[funcName]="Func_"+funcLabelCounter++;
    }

    std::string findFuncLabel(std::string funcName){
        return funcNameToLabel[funcName]; 
    }

};


#endif
