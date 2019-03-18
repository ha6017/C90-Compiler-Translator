#include "../include/ast.hpp"
#include <string>
#include <stdio.h>

int main(int argc, char *argv[])
{

    const ASTNode* ast=parseAST();

    ast->printC(std::cout);
    std::cout<<std::endl;

    std::cout<<"PRINTING PYTHON"<<std::endl;

    ast->printPython(std::cout);
    std::cout<<std::endl;

    return 0;
}
