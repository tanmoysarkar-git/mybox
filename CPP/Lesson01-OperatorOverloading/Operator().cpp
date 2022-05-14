//Overloading Operator paranthesis 

#include <iostream>
#include <cassert>

class Matrix{
    private:
        int matrix[4][4];
    public:
        Matrix()
        {
            for(auto int i=0;i<4;i++)
            {
                for(auto int j=0;j<4;j++ )
                {
                    matrix[i][j]=i*j;
                }
            }
        }
        int operator() (const int& _row,const int& _col)
        {
           assert(_row>=0 && _col >=0); 
           
           return matrix[_row][_col];
        }
};

int main()
{
    Matrix m_data;
    std::cout<<"m_data[1][2] : "<<m_data(1,2)<<std::endl;
}