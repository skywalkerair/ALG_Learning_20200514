#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree<char> tree;
    TreeNode<char> add,subtract,multi,divide,a,b,c,d,e;

    add.data = '+';
    subtract.data = '-';
    multi.data = '*';
    divide.data = '/';

    a.data = 'A';
    b.data = 'B';
    c.data = 'C';
    d.data = 'D';
    e.data = 'E';

    tree.root = &add;
    add.leftChild = &b;
    add.rightChild = &e;

    subtract.leftChild = &multi;
    subtract.rightChild = &d;

    multi.leftChild = &divide;
    multi.rightChild = &c;

    divide.leftChild = &a;
    divide.rightChild = &b;



    return 0;
}
