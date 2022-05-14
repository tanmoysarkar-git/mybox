#include <iostream>

class Abstract{
    private:
        int x;
    public:
        Abstract(int _x) {}
};
class UseAbstract:public Abstract{
    public:
        UseAbstract(int _x):Abstract(_x)   {}
};

int main()
{
    return 0;
}