#include "../include/ast.hpp"
#include <string>
#include <stdio.h>

int main(int argc, char *argv[])
{

    nodePtr ast=parseAST();

    ast->printC(std::cout);
    std::cout<<std::endl;

    return 0;
}
