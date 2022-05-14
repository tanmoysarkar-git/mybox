#include <iostream>
#include <memory>

class IProject{
    public:

        virtual void setWorkStatus() = 0;
};
class Project1:public IProject{

};

int main()
{
   auto P1=std::make_shared<Project1>();
return 0;
}