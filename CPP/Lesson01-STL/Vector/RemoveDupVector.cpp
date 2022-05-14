#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> vecstr{"UID:1234", "UID:abcd", "UID:4321", "UID:1234", "UID:a1b2"};
    std::cout<<"Original Vector "<<std::endl;
    for(auto eachv : vecstr)
        std::cout<<eachv<<std::endl;
    std::sort(vecstr.begin(),vecstr.end());
    vecstr.erase(std::unique(vecstr.begin(),vecstr.end()),vecstr.end());
    std::cout<<"Unique vector "<<std::endl;
    for(auto eachv : vecstr)
        std::cout<<eachv<<std::endl;
}

