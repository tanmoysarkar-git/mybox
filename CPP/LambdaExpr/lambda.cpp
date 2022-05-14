#include <iostream>

class Base{
    public:
        void IsBase()   {std::cout<<"Base"<<std::endl;}
};
class Derived: public Base{
    public:
    void callBase(){
        IsBase();
        auto lambda = [this](){
            IsBase();
        };
        lambda();
    }
    
};

int main()
{
    Derived ob;
    ob.callBase();
return 0;
}