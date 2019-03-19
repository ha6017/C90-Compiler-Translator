#include "../include/ast.hpp"
#include <string>
#include <stdio.h>

int main(int argc, char *argv[])
{

    const ASTNode* ast=parseAST();

    ast->printC(std::cout);
    std::cout<<std::endl;

    std::cout<<"PRINTING PYTHON"<<std::endl;
    
    IndentAdd tab;

    ast->printPython(std::cout, tab);
    std::cout<<std::endl;

    return 0;
}
