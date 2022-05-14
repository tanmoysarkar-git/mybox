#include <iostream>
class Base{
    public:
        void print()    {std::cout<<"Base"<<std::endl;}
};
class Derived:public Base   {
    public:
    void print() {std::cout<<"Derived"<<std::endl;}
};
int main()
{
    //Implicit cast
    Derived d1;
    Base *bp = &d1; // upcasting(Derived -> Base) here Implicit conversion is done by the compiler
    d1.print();
    bp->print();

    //Explicit cast : It's requires when you try to do downcasting
    Base b1;
    //Derived *d2=&b1; //Fail
    Derived *d2=(Derived*)&b1;
    b1.print();
    d2->print();


    return 0;
}