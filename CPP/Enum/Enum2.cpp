/**
 * @file Enum2.cpp
 * @author your name (you@domain.com)
 * @brief Enum Class vs Enum Datatype
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 */
#include <iostream>

enum class Person1 { Masculine1, Feminine1, Transgender1 };
enum class Person2 { Feminine2, Masculine2, Transgender2 };
int main()
{
    Person1 John = Person1::Masculine1;
    Person2 Jeny = Person2::Feminine2;

    // if( John == Jeny ) //type-safe // Implicit coversion error
    //     std::cout<<"John and Jeny are same person\n";
    // else
    //     std::cout <<"John and Jeny are different person\n";
    
    std::cout <<"Integer value of John Enum class data: "<<int(John)<<std::endl;
}