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
    void InOrder(TreeNode<T>* currentNode);
    void PreOrder();
    void PostOrder();
    void LevelOrder();
    void Visit(TreeNode<T>* currentNode);

public:
    TreeNode<T> *root;

};


template<class T>
void BinaryTree<T>::InOrder()
{
    InOrder(root);
    //Visit(root);
}

template<class T>
void BinaryTree<T>::Visit(TreeNode<T>* currentNode)
{
    std::cout<<currentNode->data;
}


template<class T>
void BinaryTree<T>::InOrder(TreeNode<T>* currentNode)
{
    if(currentNode)
    {
        InOrder(currentNode->leftChild);
        Visit(currentNode);
        InOrder(currentNode->rightChild);
    }
}

#endif