/*
    Day 1:交换算法;冒泡排序
*/
#include<iostream>
using namespace std;
void BubbleSort(int list[],int n);

int main()
{
    int list[8] = {3,4,1,2,8,9,45,5};
    BubbleSort(list,8);
    for(int i = 0;i < 8;i++)
        cout<<list[i]<<" ";
    cout << endl;
    return 0;
}


void BubbleSort(int list[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j<n-i-1 ;j++)
        {
            if(list[j] > list[j+1])
            {
                swap(list[j],list[j+1]);
            }
        }
    }
}
