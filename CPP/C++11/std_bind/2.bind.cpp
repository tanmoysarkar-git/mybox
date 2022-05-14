#include <iostream>
#include <functional> //std::bind()
#include <string>


void fun(int x, std::string str)
{
    while(x-- >0)
        std::cout<<str<<std::endl;
}
class Base{
    public:
        int Compute(int x,int y, int z)
        {
            return x+y-z;
        }

};

int main()
{
    using Examplefunc = std::function<int(int, int, int)>;

    Base instance;

    Examplefunc f1 = std::bind(&Base::Compute,&instance,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);
    std::cout<< f1(10,2,3)<<std::endl;
    
    auto f2 = std::bind(&Base::Compute,&instance,std::placeholders::_1,10,std::placeholders::_2);
    std::cout<<f2(10,2)<<std::endl;

    auto f3 = std::bind(fun,std::placeholders::_1,std::placeholders::_2);
    f3(3,"Hello");

    auto f4 = std::bind(fun,2,std::placeholders::_1);
    std::string str = "Hello Again";
    f4(str);   

    //Lambda
    
        auto lambda = [](std::string str, int x)
        {
            while(x-- > 0)
                std::cout<<str<<std::endl;
        };

        std::function<void(std::string, int)> f5 = std::bind(&decltype(lambda)::operator(),&lambda,
            std::placeholders::_1, std::placeholders::_2);

            f5("calling Lambda",3);

}