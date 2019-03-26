#ifndef ast_context_hpp
#define ast_context_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include <memory>

static int label_counter=0;



class Context
{

public:
    unsigned int currentGlobalPointer;
    int currentLocalPointer;
    int scopeCountPerScope;
    int paramCount;
    // std::map<std::string, unsigned int>globals;
    std::vector<std::string> globals;
    std::map<std::string, int>locals;
    // std::map<std::string, std::string>funcNameToLabel;
    // int funcLabelCounter;
    // unsigned int stackOffset;
    bool freeRegs[32]; //0 is locked, 1 is unlocked
    int scope_counter;
    int currentArrayElement;    //used for array init
    std::string currentArrayName;   //used for array init
    int prevEnumVal;



    Context(){
        scope_counter=0;
        paramCount=0;
        
        // funcLabelCounter=0;
        // stackOffset =0;
        // currentGlobalPointer=0x2000;
        currentLocalPointer=0;
        currentArrayElement=0; //this is for arraylist
        scopeCountPerScope=0;

        //CREATE FOR LOOP TO FREE THE TEMPS
        for(int i=0;i<32;i++){
            freeRegs[i]=1;
        }
    }
    
    Context(const Context &inContext){
        //I NEED TO CREATE COPY CONSTRUCTOR AND CHANGE EVERYTHING TO PASS BY REFERENCE. THEN FIGURE OUT FUNCTION LABEL MAPPINGS
        globals=inContext.globals;
        locals=inContext.locals;
        // funcNameToLabel=inContext.funcNameToLabel;
        // funcLabelCounter=inContext.funcLabelCounter;
        for(int i=0;i<32;i++){
            freeRegs[i]=inContext.freeRegs[i];
        }
        
        scope_counter=inContext.scope_counter;
        currentArrayElement=inContext.currentArrayElement;
        currentArrayName=inContext.currentArrayName;
        paramCount=inContext.paramCount;
        // currentGlobalPointer=inContext.currentGlobalPointer;
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
    void enterFunction(){
        currentLocalPointer=0;
        locals.clear();
        // paramCount=0;
    }
    // void exitScope(){
    //     scope_counter--;
    // }

    std::string findTemp(){
        for(int i=8;i<26;i++){
            if(freeRegs[i]==1){
                freeRegs[i]=0;
                return "$"+std::to_string(i);
            }
        }
        throw "Ran out of registers";
    }
    
    // std::string findParam(){
    //     for(int i=4;i<8;i++){
    //         if(freeRegs[i]==1){
    //             freeRegs[i]=0;
    //             return "$"+std::to_string(i);
    //         }
    //     }
    // }
    void UnlockReg(std::string RegName){
        int index=std::stoi(RegName.substr(1));
        freeRegs[index]=1;
    }
    // std::string retrieveParam(){
    //     for(int i=4;i<8;i++){
    //         if(freeRegs[i]==0){
    //             freeRegs[i]=1;
    //             return "$"+std::to_string(i);
    //         }
    //     }
    //     throw "Incorrect number of parameters.";
    // }
    // unsigned int createGlobalInt(std::string name){
    //     globals[name]=currentGlobalPointer;
    //     currentGlobalPointer=currentGlobalPointer+4;
    //     return currentGlobalPointer-4;
    // }
    int createLocalInt(std::string name){
        locals[name]=currentLocalPointer;
        currentLocalPointer=currentLocalPointer-4;
        return currentLocalPointer+4;
    }
//    unsigned int findGlobalInt(std::string name){
//         return globals[name];
//     }

    int findLocalInt(std::string name){
        return locals[name];
        
    }
    bool globalIntExists(std::string name){
        for(int i=0;i<globals.size();i++){
            if(globals[i]==name){
                return 1;
            }
        }
        return 0;
    }
    bool localIntExists(std::string name){
        if(locals.count(name)>0){
            return 1;
        }else{
            return 0;;
        }
    }


    void createGlobal(std::string name){
        globals.push_back(name);
    }
    int createLocalArray(std::string name, int size){
        locals[name]=currentLocalPointer;
        currentLocalPointer=currentLocalPointer-4*size;
        return currentLocalPointer+4*size;
    }
    int findLocalArrayElement(std::string name, int index){
        return (locals[name]-4*index);
    }
    // unsigned int findGlobalArrayElement(std::string name, int index){
    //     return locals[name]+4*index;
    // }
    // void addFunction(std::string funcName){
    //     funcNameToLabel[funcName]="Func_"+funcLabelCounter++;
    // }

    // std::string findFuncLabel(std::string funcName){
    //     return funcNameToLabel[funcName]; 
    // }

};


#endif
