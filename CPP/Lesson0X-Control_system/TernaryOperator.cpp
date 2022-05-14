/**
 * @file TernaryOperator.cpp
 * @author Tanmoy Sarkar <tanmoysarkarself@yahoo.co.in>
 * @brief Conditional Operator
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
int main()
{
    int32_t Input;
    std::cout<<"Enter Input(range 0-9): ";
    std::cin>>Input;
    std::cout<< ((Input >= 0 && Input <=9) ? "Pass" : "Out-Of-Range");
return 0;
}