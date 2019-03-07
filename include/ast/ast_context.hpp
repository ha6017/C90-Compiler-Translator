#ifndef ast_context_hpp
#define ast_context_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>



class Context
{
private:
    int label_counter;
    unsigned int currentGlobalPointer;
    unsigned int currentLocalPointer;
public:


    std::map<std::string, unsigned int>globals;
    std::map<std::string, unsigned int>locals;
    std::map<std::string, std::string>funcNameToLabel;
    int funcLabelCounter;

    bool freeRegs[32]; //0 is locked, 1 is unlocked
    int scope_counter;
    int currentArrayElement;
    std::string currentArrayName;


    Context(){
        scope_counter=0;
        label_counter=0;
        funcLabelCounter=0;
        currentGlobalPointer=0x20000000;
        currentLocalPointer=0x20400000;
        currentArrayElement=0; //this is for arraylist
    }

    std::string makeVarName(std::string inName){
        return inName + std::to_string(scope_counter); // BIG WORRIES HERE in a local scope i should be able stuff outside! but i wont be able to outside variables like this!!
        //ive removed all uses of this function but kept it for future use.
    }
    std::string makeLabelName(){
        return "L_"+ std::to_string(label_counter++);
    }
    void enterScope(){
        scope_counter++;
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

    void UnlockReg(std::string RegName){
        int index=std::stoi(RegName.substr(4));
        freeRegs[index]=1;
    }
    unsigned int createGlobalInt(std::string name){ //will have another 4 functions for arrays
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
        return locals[name];
    }

    unsigned int createGlobalArray(std::string name, int size){ //will have another 4 functions for arrays
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
        return funcNameToLabel[funcName]; // GREAT NEXT STEP IS ADDING THIS TO THE FUNCTIONS AND YOURE GOOD! dont forget enter scope.
    }

    //need to make a 
};


#endif
