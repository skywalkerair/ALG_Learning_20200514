#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T> class BinaryTree;


template<class T> 
class TreeNode
{
public:
    TreeNode()
    {
        leftChild = NULL;
        rightChild = NULL;
    }

    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;

};


template<class T> 
class BinaryTree
{
public:
    //可以对二插树进行的操作
    void InOrder();
    void PreOrder();
    void PostOrder();
    void LevelOrder();

public:
    TreeNode<T> *root;

};

#endif