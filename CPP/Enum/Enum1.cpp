/**
 * @file Enum.cpp
 * @author your name (you@domain.com)
 * @brief Enum Class vs Enum Datatype
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
/*
enum Person { Masculine, Feminine, Transgender };

int main()
{
    Person John = Person::Masculine;
    std::cout<<"Size of enum datatype : "<<sizeof(Person)<<std::endl;
    std::cout<<"Size of enum datatype : "<<sizeof(John)<<std::endl;
return 0;
}
*/

//-----------------------

//1. Two enumerations cannot share the same names: 
/*
enum Person { Masculine, Feminine};
enum AnotherPerson {Feminine, Transgender };

int main()
{

return 0;
}
*/

//------------------------

//2. No variable can have a name which is already in some enumeration:
/*
int main()
{
    enum Person { Masculine, Feminine};
    int Masculine;
return 0;
}
*/

//-------------------------------

//3. Enums are not type-safe:
enum Person { Masculine, Feminine};
enum AnotherPerson {Feminine_2, Transgender };

int main()
{
    Person John = Person::Masculine;
    AnotherPerson Jeny = AnotherPerson::Feminine_2;

    if(John == Jeny)
        std::cout <<"John and Jeny are same person"<<std::endl;
    else   
        std::cout <<"John and Jeny are different person"<<std::endl;

return 0;
}