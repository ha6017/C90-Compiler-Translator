#ifndef ast_program_hpp
#define ast_program_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"
#include "ast_context.hpp"

class ProgramList : public ASTNode
{
    public:
	nodePtr SingleProgram;
    nodePtr ListofProgram;
	
    ProgramList(nodePtr _SingleProgram, nodePtr _ListofProgram) :
        SingleProgram(_SingleProgram),
        ListofProgram(_ListofProgram) {}

    ~ProgramList()
    {
        delete SingleProgram;
        delete ListofProgram;
    }
	
	virtual void printC(std::ostream &dst) const override{
		
	}

    virtual void printPython(std::ostream &dst) const override
    {
       
    }
   
	virtual void printMips(std::ostream &dst, Context &cont, int RegisterLock) const {
		
	}

};

class Program : public ASTNode
{
public:
	public:
	nodePtr SingleProgram;
 
	
    Program(nodePtr _SingleProgram) :
        SingleProgram(_SingleProgram) {}

    ~Program()
    {
        delete SingleProgram;

    }
	
	virtual void printC(std::ostream &dst) const override{
		
	}

    virtual void printPython(std::ostream &dst) const override
    {
        
    }
   
	virtual void printMips(std::ostream &dst, Context &cont, int RegisterLock) const {
		
	}

};


#endif
