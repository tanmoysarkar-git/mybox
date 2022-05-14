#include<iostream>

enum VehicleDataStatus {
    /** Data was successfully retrieved */
    OK,
    /** There was error during data retrieval */
    Error,
    /** Implementation is not initialized/not connected and can't retrieve data */
    NotReady,
    /** Method is not implemented */
    NotImplemented,
    /** Requested resource was not found */
    NotFound
};
static const char* str[] = {"OK", "Error"};
int main()
{
    std::cout<<" VehicleDataStatus::"<<str[VehicleDataStatus::OK]<<std::endl;
}