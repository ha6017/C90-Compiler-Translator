#ifndef ast_context_hpp
#define ast_context_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>



class Context
{
private:
    int reg_counter;
    int scope_counter;
    int label_counter;

public:
    Context(){
        reg_counter=1; //cus R0 is always 0
        scope_counter=0;
        label_counter=0;
    }
    std::string makeRegName(){
        return "reg_"+ std::to_string(reg_counter++);
    }
    std::string makeVarName(std::string inName){
        return inName + std::to_string(scope_counter);
    }
    std::string makeLabelName(){
        return "L_"+ std::to_string(label_counter++);
    }
    void enterScope(){
        scope_counter++;
    }
    void exitScope(){
        scope_counter--;
    }


};


#endif
