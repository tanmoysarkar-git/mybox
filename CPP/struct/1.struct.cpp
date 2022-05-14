#include <iostream>
#include <string>
#include <vector>
struct ContainerEndpoint_t{
    std::string id;
    std::string path;
};
 struct ContainerData_t {
        std::string mUid;
        std::vector<ContainerEndpoint_t> mEndpoints;
};
int main()
{
    ContainerData_t data {"1234",{{"calender","/v1.0/calender"},{"notebook","/v1.0/notepad"}}};
    const auto &mID = data.mUid;
    std::cout <<"mID : "<<mID<<std::endl;
    const auto& endpoints=data.mEndpoints;
    std::cout<<"endpoint size : "<<endpoints.size();
    for(const auto& endpoint : endpoints)
        {
            std::cout<<"id: "<<endpoint.id<<std::endl;
            std::cout<<"path: "<<endpoint.path<<std::endl;
        }
}