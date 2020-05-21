#ifndef MYSTACK_H
#define MYSTACK_H
#include "MyUtil.h"
#include "MyUtil.cpp"
template<class T>
class MyStack
{
public:
    MyStack(int stackCapacity =10);
    ~MyStack();

    bool IsEmpty() const;
    T& Top() const;
    void Push(const T& item);
    void Pop();

private:
    T *stack; //指针
    int top; //记录栈顶在哪
    int capacity;

};

template<class T>
MyStack<T>::MyStack(int stackCapacity):capacity(stackCapacity)
{
    if(capacity < 1) throw "stack capacity must be > 0";
    stack = new T[capacity];
    top = -1;
}

template<class T>
MyStack<T>::~MyStack()
{
    delete[] stack;
}

template<class T>
void MyStack<T>::Push(const T& item)
{
    if(top == capacity-1)
    {
        ChangeSize1D(stack,capacity,2*capacity);
        capacity *= 2;
    }
    stack[++top] = item;
}



#endif