/**
 * @file LooseCoupling.cpp
 * @author your name (you@domain.com)
 * @brief means one class is dependent on interface rather than class. we must pass dependency externally at runtime instead of hard-coded.
 *        (Loose couple systems use interface for decreased dependency with class.)
 *           the degree of dependency between two components is very low.
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) @TanmoySarkar 2021
 * 
 */
#include <iostream>
#include <memory>
#include "GenerateOutput.hpp"

class Output{
    public:
        void generateOutput( IOutputGenerator& whichOPGen )
        {
           whichOPGen.generateOutput();
        }
};
//Here to generate to different Output we only need one class.
// hence low dependency . Here we use interface to reduce the dependency.
int main()
{
    CSVOutputGenerator csv;
    JSONOutputGenerator json;
   Output OP1,OP2;
   OP1.generateOutput(csv) ;
   OP1.generateOutput(json) ;
}