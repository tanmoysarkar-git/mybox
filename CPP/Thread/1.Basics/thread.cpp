#include <iostream>
#include <thread>

void foo()
{
    std::cout<<__func__<<std::endl;
}
int main()
{
    std::thread first (foo);
    first.join();
}

//use option -std=c++11