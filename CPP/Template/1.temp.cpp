#include <iostream>

class TFacade{
    public:
        TFacade() = default;
        ~TFacade() = default;
        void notifyCallbacks()
        {
            std::cout<<__func__<<std::endl;
        }

};
class Client:public ::TFacade{
    public:
        Client() = default;
        ~Client() = default;
        void callCallBack()
        {
            ::TFacade::notifyCallbacks();
        }
};

int main()
{
    Client c1;
    c1.callCallBack();

return 0;
}