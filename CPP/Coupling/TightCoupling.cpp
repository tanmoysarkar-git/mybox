/**
 * @file TightCoupling.cpp
 * @author your name (you@domain.com)
 * @brief means one class is dependent on another class.There are hard-coded dependency declared in methods.
 *           the degree of dependency between two components is very High
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) @TanmoySarkar 2021
 * 
 */
#include <iostream>
#include <memory>
#include "GenerateOutput.hpp"

class Output1{
    public:
        void generateOutput( )
        {
          std::unique_ptr<IOutputGenerator> output = std::make_unique<CSVOutputGenerator>();
          output->generateOutput();
        }
};

class Output2{
    public:
        void generateOutput( )
        {
          std::unique_ptr<IOutputGenerator> output = std::make_unique<JSONOutputGenerator>();
          output->generateOutput();  
        }
};
//Here to generate two different output format, we need to create two different class 
//because both class is hard-coded and high level of dependency
int main()
{
    Output1 OP1;
    Output2 OP2;
    OP1.generateOutput();
    OP2.generateOutput();
return 0;
}