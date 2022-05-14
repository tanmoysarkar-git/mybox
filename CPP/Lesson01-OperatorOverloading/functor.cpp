//Operator() is also commonly overloaded to implement functors (or function object), which are classes that operate like functions.
#include <iostream>

class Functor{
    private:
        int m_var{1};
    public:
        int operator() (int _x)
        {
            return (m_var+=_x);
        }  
};
int main()
{
    Functor f1,f2;
    std::cout<<"Increment the functor"<<std::endl;
    std::cout<<f1(10)<<std::endl;
    std::cout<<f1(20)<<std::endl;
    std::cout<<f2(10)<<std::endl;

}