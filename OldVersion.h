#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "iostream"

template<class DataType>
class BinaryTree {
public:
    DataType num;
    BinaryTree<DataType> *left;
    BinaryTree<DataType> *right;
    BinaryTree<DataType> *root;

    static int length;

    BinaryTree();

    BinaryTree(int data) {
        num = data;
        root = nullptr;
        left = nullptr;
        right = nullptr;
    };

    bool isEmpty();

    void insert(DataType item);

    void MakeLeft(BinaryTree<DataType> &btn);

    void MakeRight(BinaryTree<DataType> &btn);

};

template<class DataType>
BinaryTree<DataType>::BinaryTree() {
    root = nullptr;
}

template<class DataType>
int BinaryTree<DataType>::length = 1;

template<class DataType>
bool BinaryTree<DataType>::isEmpty() {
    return root == nullptr;
}

template<class DataType>
void BinaryTree<DataType>::insert(DataType item) {
    if (root == nullptr)
        root = new BinaryTree<DataType>(item);
}

template<class DataType>
void BinaryTree<DataType>::MakeLeft(BinaryTree<DataType> &btn) {
    if (root != nullptr) {
        root->left = &btn;
        length++;
    }
}

template<class DataType>
void BinaryTree<DataType>::MakeRight(BinaryTree<DataType> &btn) {
    if (root != nullptr) {
        root->right = &btn;
        length++;
    }
}
#endif