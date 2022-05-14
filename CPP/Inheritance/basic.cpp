#include<iostream>
using namespace std;

class Base{
    public:
        Base()  =default;
        ~Base() =default;
};
class Derived:public Base{
    public:
        Derived()=default;
        ~Derived()=default;
};
int main()
{
    return 0;
}