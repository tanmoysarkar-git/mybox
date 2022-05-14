#include <iostream>
#include <vector>
#include <map>

enum class DataState{
    OK,
    Error
};

template <class value>
class MCacheValue{
    private:
        std::map<int noofentries, value val> mCmplxValue;
        value mValue;
        DataState CacheValue;

    public:
        void updateValue(const value& v)
        {
            mValue = v;
            CacheValue = DataState::OK;
        }
        value getvalue() const
        {
            if( this->CacheValue == DataState::OK )
                return mValue;
        }

};
int main()
{
    
}