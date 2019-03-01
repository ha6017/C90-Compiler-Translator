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

public:
    Context(){
        reg_counter=0;
        scope_counter=0;
    }
    std::string makeRegName(){
        return "reg_"+reg_counter++;
    }
    std::string makeVarName(std::string inName){
        return inName+scope_counter;
    }

    void enterScope(){
        scope_counter++;
    }
    void exitScope(){
        scope_counter--;
    }


};


#endif
