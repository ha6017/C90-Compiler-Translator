#include "../include/ast.hpp"
#include <string>
#include <stdio.h>

int main(int argc, char *argv[])
{
<<<<<<< HEAD
    //Context cont= new Context(); 
=======
>>>>>>> 7142eddc3dec562c19e92735dde9696afd88320d

    nodePtr ast=parseAST();

    ast->printC(std::cout);
    std::cout<<std::endl;

    return 0;
}
