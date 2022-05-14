#include <iostream>
#include <map>

#ifndef __DEBUG__
#define __DEBUG__
   std::string VehicleAbstractionService = "VehicleAbstractionService";
#endif


void converttovoid(void* map)
{
    auto _map = static_cast<std::map<int,int>*>(map);
    for(auto i: *_map)
    {
        std::cout<<"first: "<<i.first;
    }
}
int main()
{
    std::map<int,int> map1;
    map1.insert(std::pair<int,int>(1,2));
    converttovoid(static_cast<void*>(&map1));
return 0;
}