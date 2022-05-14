#include <iostream>
#include <memory>

enum class DataStatus{
    Init,
    Ready
};
void updateCacheValue(const DataStatus& value);
auto callback = [&]()
        {
            updateCacheValue(DataStatus::Ready);
        };

class DataClient{
    private:
        DataStatus datastatus;
    public:
        DataClient();
        DataStatus getDataStatus();
        friend void updateCacheValue(const DataStatus& value);
        
};
DataClient::DataClient():datastatus(DataStatus::Init)
{

}
DataStatus DataClient::getDataStatus()
{
    return datastatus;
}
int main()
{
    std::shared_ptr<DataClient> dataclient = std::make_shared<DataClient>();
    int ret = (int)dataclient->getDataStatus();
    std::cout<<"DataStatus is " << ((ret == 0) ? "Init" : "Ready" )<<std::endl;
}