#ifndef intermediate_rep_hpp
#define intermediate_rep_hpp

#include <string>
#include <iostream>
#include <cmath>

struct IntermediateRep{
    std::string id;
    std::string outReg;
    std::string inRegA;
    std::string inRegB;
    //maybe can add a prefix on the id for global variables so we can deal with them appropriate 
    //id can maybe 
    IntermediateRep(std::string _id, std::string _outReg, std::string _inRegA, std::string _inRegB)
        :   id(_id)
        ,   outReg(_outReg)
        ,   inRegA(_inRegA)
        ,   inRegB(_inRegB)
    {}
}


#endif
