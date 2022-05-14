#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class IObserver{
    public:
        virtual void update( std::string ) = 0;
};
class Subscriber1 : public IObserver{
    public:
        void update( std::string content) 
        {
            std::cout<<"New video uploaded"<<std::endl;
        }

};
class Subscriber2 : public IObserver{
    public:
        void update( std::string content ) 
        {
            std::cout<<"New video uploaded"<<std::endl;
        }
};
class ISubject{
    public:
        ISubject()=default;
        virtual void Register( const IObserver& ) = 0 ;
        virtual void Unregister ( const IObserver& ) = 0 ;
        virtual void Notify();
};
class Publisher : public ISubject{
    private:
        std::vector<IObserver> observers;
    public:
        void Register(const IObserver& ob) override
        {
            //observers.push_back(ob);
        }
        void Unregister( const IObserver& ob) override
        {
            //observers.erase(std::find(observers.begin(),observers.end(),ob));
        }
        void Notify()
        {

        }
};

int main()
{
    Publisher channel;
    //ISubject& youtube = channel;

    // Subscriber1 Mihiraan{};
    // youtube.Register(Mihiraan);

    // Subscriber2 Trilochini{};
    // youtube.Register(Trilochini);

    //youtube.Notify();

}
