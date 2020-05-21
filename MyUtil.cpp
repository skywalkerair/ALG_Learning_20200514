#include "MyUtil.h"
#include<iostream>
using namespace std;

template<class T>
void ChangeSize1D(T* &Data,const int oldSize,const int newSize)
{
    if(newSize < 0)
    {
        throw "New length must be >= 0";
    }

    T *tmp = new T[newSize];
    int number = min(oldSize,newSize);
    std::copy(Data,Data+number,tmp);
    delete[] Data;
    Data = tmp;
}