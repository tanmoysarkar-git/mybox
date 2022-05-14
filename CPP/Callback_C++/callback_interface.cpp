#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

//interace
class IInterface
{
    public:
    virtual void result(int num) = 0;
};

//some thread to do asynchronous call back
void math_thread(IInterface* callPtr,int a,int b) 
{
  std::this_thread::sleep_for (std::chrono::seconds(5));
  callPtr->result(a+b);
  std::cout << "pause of " << 5 << " seconds ended\n";
}

// header file of core implementation
class Math
{
    private:
    IInterface* objRef;
    public:
    Math() = delete;
    Math(IInterface* callPtr);
    void add(int,int);
};

//source file of core implementation
Math::Math(IInterface* callPtr)
{
    objRef = callPtr;
}
void Math::add(int a , int b)
{
    std::thread (math_thread,objRef,a,b).detach();
    return;
}

//header file of realising client
class Client: public IInterface
{
    public:
    void result(int num){
        std::cout<<"print: "<<num<<std::endl;
    }
};

int main()
{
    Client objClient;
    Math objMath(&objClient);
    objMath.add(4,8);
    
    cout<<"Hello World";
    //wait until the add operation is complete
    std::this_thread::sleep_for (std::chrono::seconds(10));

    return 0;
}

// use option -std=c++11