#include<iostream>
#include<vector>
using namespace std;

class Vector{

};

int main()
{
    const std::vector<int> v1 = {1,2,3,4};
    std::vector<int> v1temp{v1};
    for(auto& v1tempIt: v1temp)
    {
        v1tempIt +=1;
    }
     for(auto& v1tempIt: v1temp)
    {
        std::cout<<v1tempIt<<std::endl;
    }

return 0;
}