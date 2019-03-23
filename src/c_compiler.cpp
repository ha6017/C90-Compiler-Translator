#include "../include/ast.hpp"
#include <string>
#include <stdio.h>
#include <exception>

int main(int argc = 4, char *argv[] = NULL)
{
  std::cout<< "START " << std::endl;          
  freopen (argv[2],"r",stdin);

  const ASTNode *ast=parseAST();
  IndentAdd tab;
  
  std::cout<< std::endl;    

  freopen (argv[4],"w",stdout);
  std::string test = argv[1];
  if (test == "--translate") {
    //std::cout<< "The Python Equivalent: " << std::endl;
    ast->printPython(std::cout, tab);
    std::cout<<std::endl;

            std::cout<<std::endl;
            std::cout<<"# Boilerplat"<<std::endl;
            std::cout<<"if __name__ == \"__main__\":"<<std::endl;
            std::cout<<"    import sys"<<std::endl;
            std::cout<<"    ret=main()"<<std::endl;
            std::cout<<"    sys.exit(ret)"<<std::endl;

  } 
  else if (test == "-S") {
    // std::cout<<"J main"<<std::endl;
    // std::cout<<"nop"<<std::endl;

    Context initContext;
    // try{
      ast->printMips("I SHOULDNT BE SHOWN, IM IN PRINT CANONICAL.",initContext,std::cout);
    // }catch(const std::exception &e){
    //   std::cout<<e.what()<<std::endl;
    // }
  }


  return 0;
}
