#include <iostream>
#include <functional>

//partial function application using std::bind()
/*
-> https://www.youtube.com/watch?v=1hpVHPSGlJ8

std::placeholders::_1, std::placeholders::_2, ..., std::placeholders::_N

C++ Utilities library Function objects 

Defined in header <functional>

std::placeholders namespace contains the placeholder objects [_1, ..., _N] 
where N is an implementation defined maximum number.
When used as an argument in a std::bind expression, the placeholder objects are stored in the generated function object, and when that function object is invoked with unbound arguments, 
each placeholder _N is replaced by the corresponding Nth unbound argument.

*/

void fun(int x,int y, int z)
{
    std::cout<<(x+y-z)<<std::endl;
}

int main()
{
    // x = std::placeholders::_1
    // y = std::placeholders::_2
    // z = std::placeholders::_3

    auto f1 = std::bind(fun,std::placeholders::_1,10,5);
    int futureVal = 20;
    f1(futureVal);
    //suppose placeholder::_1 i.e x is such value which will be received by computation of thread
    // in such case y=10,z=5 should be kept intact  

    //if u define as std::function type
    std::function<void (int, int, int)> f2 = std::bind(fun,10,std::placeholders::_1,5);
    f2(1,2,3);
    //Here f2(10,1,5) is called but f2(1) we can't call it will give error. So it's better
    // Not to use std:function . Only use when below example

    std::function<void (int, int, int)> f3 = std::bind(fun,std::placeholders::_2,std::placeholders::_1
    ,std::placeholders::_3);
    //fun(x=20,y=5,z=10)
    //fun(x=20,y=10,z=5)
    f3(10,20,5);

}