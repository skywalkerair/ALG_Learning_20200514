/*
    20200517:Day 1:交换算法;冒泡排序
    20200518:Day 2:选择排序,顺序查找（无序）;折半查找
    递归算法
*/
#include<iostream>
using namespace std;
void BubbleSort(int list[],const int n);
void SelectSort(int list[],const int n);
int SequentialSearch(int *a,const int n,const int x);
int BinarySearch(int *a,const int n,const int x);
long Factorial(int n);
int BinarySearch_I(int *a,const int n,const int x);
int BinarySearch_R(int *a,const int x,const int left,const int right);


int main()
{
//     int list[8] = {3,4,1,2,8,9,45,5};
//     BubbleSort(list,8);
//     //SelectSort(list,8);
//     //for(int i = 0;i < 8;i++)
//        //cout<<list[i]<<" ";
//    // cout << endl;
//     int result;
//     //result = SequentialSearch(list,8,4);
//     result = BinarySearch(list,8,7);

//     if(result < 0)
//         cout<<"没找到！"<<endl;
//     else
//         cout<<"数组中的第["<<result<<"] = "<<list[result]<<endl;
    long x =  Factorial(5);
    cout << "阶乘5="<<x<<endl;

    return 0;
}

//Day 1
void BubbleSort(int list[],const int n)
{
    cout<<"Enter BubbleSort..."<<endl;
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

//Day 2
void SelectSort(int list[],const int n)
{
    cout<<"Enter SelectSort..."<<endl;
    for(int i = 0;i<n;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(list[j]<list[min])
            {
                min = j;
            }
        }
        swap(list[i],list[min]);
    }
}

int SequentialSearch(int *a,const int n,const int x)
{
    int i;
    for(i = 0;i<n;i++)
    {
        if(a[i] == x)
            return i;
    }
    if(i == n) return -1;
}

int BinarySearch(int *a,const int n,const int x)
{
    int low,high,mid;
    low = 0;high = n-1;

    while(low <= high)
    {
        mid = (low + high)/2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] < x)
            low = mid+1;
        else if(a[mid] > x)
            high = mid -1;
    }
    return -1;
}

long Factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * Factorial(n-1);
}

int BinarySearch_I(int *a,const int n,const int x)
{
    int left = 0;int right = n-1;
    while(left <= right)
    {
        int middle = (left+right)/2;
        if(x<a[middle]) right = middle-1;
        else if(x>a[middle]) left = middle+1; 
        else return middle;
    }
    return -1;
}

int BinarySearch_R(int *a,const int x,const int left,const int right)
{
    if(left <= right)
    {
        int middle = (left+right)/2;
        if(x < a[middle]) return BinarySearch_R(a,x,left,middle-1);
        else if(x > a[middle]) return BinarySearch_R(a,x,middle+1,right);
        else return middle;
    }
    return -1;
}