/*
    20200517:Day 1:交换算法;冒泡排序
    20200518:Day 2:选择排序,顺序查找（无序）;折半查找
    递归算法
    20200519:Day 3:Permutations;插入排序;快速排序
    20200520:Day 4:归并排序迭代的方式;
*/
#include<iostream>
#include"MyStack.h"
#include"MyUtil.h"
using namespace std;
void BubbleSort(int list[],const int n);
void SelectSort(int list[],const int n);
int SequentialSearch(int *a,const int n,const int x);
int BinarySearch(int *a,const int n,const int x);
long Factorial(int n);
int BinarySearch_I(int *a,const int n,const int x);
int BinarySearch_R(int *a,const int x,const int left,const int right);
void Permutations(char *p,const int k,const int m);

/*插入排序：
    低级： 冒泡、选择、插入
    高级：
*/
template<class T>
void InsertionSort(T *a,int n);
template<class T>
void InsertionSort_2(T *a,int n);

//快速排序算法
template<class T>
void QuickSort(T *a,const int left,const int right);

template<class T>
void Merge(T *initList,T *mergedList,const int l,const int m,const int n);

//栈 -顺序栈 :先进后出



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
//    long x =  Factorial(5);
  //  cout << "阶乘5="<<x<<endl;

    // char s[] = "abc";
    // Permutations(s,0,2);
    //int x[] = {0,2,1,4,1,5,3,1,5,8,7,9,6,5};
    //int y[14] = {0};
    //Merge(x,y,1,4,13);
    //InsertionSort(x,13);

    // for(int i = 0;i<13;i++)
    // {
    //     cout<<x[i]<< " ";
    // }

    MyStack<int> st;

    st.Push(999);
    cout<<"Hello"<<endl;
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

void Permutations(char *p,const int k,const int m)
{
    if(k == m)
    {
        for(int i = 0;i<=m;i++)
            cout<<p[i];
        cout<<endl;
    }
    else
    {
        for(int i = k;i<=m;i++)
        {
            swap(p[k],p[i]);
            Permutations(p,k+1,m);
            swap(p[k],p[i]);
        }
    }
}

template<class T>
void InsertionSort(T *a,int n)
{
    T in,out;
    for(out = 1;out<n;out++)
    {
        T tmp = a[out];
        in = out;
        while(in>0 && a[in-1]>=tmp)
        {
            a[in] = a[in-1];
            --in;
        }
        a[in] = tmp;
    }
}

template<class T>
void InsertionSort_2(T *a,int n)
{
    //a[0]用来保存排序使用，不能保存原始的数据
    for(int j = 2;j<=n;j++)
    {
        T temp = a[j];
        a[0] = temp;
        int i = j-1;
        while(temp < a[i])
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = temp;
    }
}

//快速排序算法
template<class T>
void QuickSort(T *a,const int left,const int right)
{
    if(left < right)
    {
        //选枢轴进行划分
        int i = left;
        int j = right+1;//为什么要 +1
        int pivot = a[left];
        
        do{
            do i++;while(a[i]<pivot);
            do j--;while(a[j]>pivot);
            if(i<j) swap(a[i],a[j]);
        }while(i<j);
        swap(a[left],a[j]);

        QuickSort(a,left,j-1);
        QuickSort(a,j+1,right);
    }
}


template<class T>
void Merge(T mi,T mj)
{
    if(mi == mj) return;

    Merge(mi,(mi+mj)/2);
    Merge((mi+mj)/2+1,mi);

    int i = mi,j = (mi + mj)/2+1,arrt[1001];
    for(int k = mi;k <= mj;k++)
    {
        if(i <= (mi+mj)/2 && arrt[i]<=arrt[j]|| j> mj) arrt[k]=arrt[i++];
        else arrt[k] = arrt[j++];
    }
    for(int k =mi;k<=mj;k++) arrt[k]=arrt[k];

}


