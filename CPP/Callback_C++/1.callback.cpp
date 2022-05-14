#include <iostream>
#include <functional>

    using cb1_t = std::function<void()>;
    using cb2_t = std::function<void(int)>;

    void foo1()
    {
        std::cout<<"i ma foo1"<<std::endl;
    }
    void foo2(int p)
    {
        std::cout<<"i am foo2("<<p<<")"<<std::endl;
    }
    int main()
    {
        cb1_t f1 = std::bind(&foo1);
        //or
        //cb1_t f1 = foo1;
        f1();

        cb1_t f2 = std::bind(&foo2,32);
        //but can't do this
        //cb1_t f2 = foo2(32);
        f2();

        cb2_t f3 = std::bind(&foo2,std::placeholders::_1);
        f3(41);

    }

//compile using  -std=c++0x option
