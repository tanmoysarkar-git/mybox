//----------------------------------------------Example 1-------------------------------------------------//
/*Example 1
** It performs Implicit type conversion
** e.g. int <-> float, int <-> char etc
** It's "compile time" casting
*/
/*
#include <iostream>
int main()
{
    int a;
    float f=1.5;
    //a=f; //Here complier will do implicit cast from float to int but our intension is not clear
    a=static_cast<int>(f);
    std::cout<<"a: "<<a<<std::endl;
    return 0;
}
*/
//----------------------------------------------Example 2-------------------------------------------------//
/*
/*Example 2
** Use static_cast when conversion is provided through conversion operation or conversion constructor
*/
/*
#include <iostream>
#include <string>

class Int{
    private:
        int x;
    public:
        Int(int _x):x{_x}    {std::cout<<"Conversion Constructor"<<std::endl;}
        //explicit Int(int _x):x{_x}    {std::cout<<"Explicit Constructor"<<std::endl;}
        friend std::ostream& operator <<(std::ostream& out, const Int& ob)
        {
            out<<ob.x;
        }
        operator std::string()  // Conversion Operator
        {
            std::cout<<"Conversion Operator"<<std::endl;
            return std::to_string(x);
        }

};
int main()
{
    //Int obj = 10; // Here Conversion Constructor is called : here int -> Int class
    //To avoid implicit conversion by the constructor, we can use explicit keyword and then
    //Int obj(10) or Int obj = obj(10) we have to use to initialize :  Hence no conversion
    //std::cout<<"Obj: "<<obj<<std::endl;

    //#45 : may create confusion in later part. Hence best to use static_cast
    Int obj = static_cast<Int>(10); // works for both conversion and explicit constructor
    
    //std::string str = obj; // Convertion operator is called but it may create confusion later point of time
    std::string str = static_cast<std::string>(obj);

    return 0;
}
*/

//----------------------------------------------Example 3-------------------------------------------------//
/*
/*Example 3
** static_cast is more restrictive than c-style cast
** e.g. char* -> int* i.e 1byte of data you are trying to cast in 4byte of data which is allowed in c-style cast but not with static_cast
*/
/*
#include <iostream>
 
int main()
{
    char c;
    // int *p = (int*)&c; // This is allowed in c-style cast. Pass Compile time but may fail in runtime
    // *p=300; // any no greated than 255 is dangerous and can cause run-time failure

    int *p = static_cast<int*>(&c); // Not allowed. Fail in Compile time
    std::cout<<"*p : "<< *(p)<<std::endl;
}
*/

//----------------------------------------------Example 4-------------------------------------------------//
/*
/*Example 4
** static_cast avoids casting derived to private base type
*/
/*
class Base{};
class Derived:private Base{};
//class Derived:public Base{};

#include <iostream>

int main()
{
    Derived dobj;
    Base *bobj = (Base*)&dobj; // Allowed in c-style cast but may fail at runtime
    Base *bobj1 = static_cast<Base*>(&dobj); // Fail : compile time error as Base is inherited privately. If Base was inherited publicly the it passes
    return 0;
}
*/
//----------------------------------------------Example 5-------------------------------------------------//
/*
/*Example 5
** Use for all up cast ( Derived -> Base ) but never to confused down cast
*/
/*
#include <iostream>
class Base{};
class Derived1:public Base{};
class Derived2:public Base{};
int main()
{
    Derived1 d1;
    Derived2 d2;

    Base *bp1 = static_cast<Base*>(&d1);
    Base *bp2 = static_cast<Base*>(&d2);

// Use should use below Down casting as intension is confusing . Usually dynamic_cast is being used in case of downcasting
//    Derived1 *dp1 = static_cast<Derived1*>(bp1);
//    Derived2 *dp2 = static_cast<Derived2*>(bp2);

    return 0;
}
*/

//----------------------------------------------Example 6-------------------------------------------------//
/*
/*Example 6
** use static_cast while casting "to (void*)" or "from (void*)""
*/
#include <iostream>
int main()
{
    int i = 10;
    void* vp = static_cast<void*>(&i);
    std::cout<<"*vp: "<<*(static_cast<int*>(vp))<<std::endl;

    int* ip = static_cast<int*>(vp);
    std::cout<<"*ip: "<<*ip<<std::endl;

}



























//----------------------------------------------Example 4-------------------------------------------------//
























//----------------------------------------------Example 5-------------------------------------------------//