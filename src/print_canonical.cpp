#include "../include/ast.hpp"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{

    const ASTNode* ast=parseAST();

    // ast->printC(std::cout);
    // std::cout<<std::endl;

    std::cout<<"PRINTING PYTHON"<<std::endl;
    
    IndentAdd tab;

    ast->printPython(std::cout, tab);
    std::cout<<std::endl;
    std::cout<<"PRINTING MIPS"<<std::endl;
    Context initContext;
    ast->printMips("I SHOULDNT BE SHOWN, IM IN PRINT CANONICAL.",initContext,std::cout);


    return 0;
}
