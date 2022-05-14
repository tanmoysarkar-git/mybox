#include <iostream>
#include <functional>
#include <string>

using F1Call = std::function<int(int)>;
using F2Call = std::function<int(int,int)>;
using F3Call = std::function<std::string()>;
int Addition(int x,int y)   {return x+y;}
int Subtraction(int x,int y)   {return x+y;}
class Function{
    public:
        std::string operator()() {return "called by std::func<>";}
};
int main()
{
    F2Call f1 = Addition; // function 
    F2Call f2 = &Subtraction; //function pointer
    F3Call f3 = Function() ; // function object or functor

    F2Call Remainderf4 = [](int x, int y) {
        if((x+y)/2)
            return 1;
        else
            return 0;
    };


    std::cout<<"Add(10,20) = "<<f1(10,20)<<std::endl;
    std::cout<<"Sub(10,20) = "<<f2(10,20)<<std::endl;
    std::cout<<"functor : "<<f3()<<std::endl;
    std::cout<<"Check Remainder (11+20)/2 : "<<Remainderf4(11,20)<<std::endl;
    

return 0;
}