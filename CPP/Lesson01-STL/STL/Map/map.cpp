#include<map>
#include<iostream>
#include <string>

int main()
{
    int key = 1;
    std::map<int,std::string> m1;
    m1.insert({1,"One"});
    m1.insert({2,"Two"});

    auto value = [m1,key](){
        auto ret = m1.find(key);
        return ret->second;
    };
    std::cout<<value()<<std::endl;
    std::cout<<m1[1]<<std::endl;
}