#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "iostream"

template<class DataType>
class BinaryTree {
public:
    enum character {
        null, Operand, Operator
    };
    character Node;
    DataType num;
    BinaryTree<DataType> *left;
    BinaryTree<DataType> *right;

    static int length;

    BinaryTree();

    BinaryTree(int data) {
//        if (isdigit(data)) {
        Node = Operand;
//        } else {
//            Node = Operator;
//        }
        num = data;
        right = left = nullptr;
    };

    bool isEmpty();

    void insert(DataType item);

    void MakeLeft(BinaryTree<DataType> &btn);

    void MakeRight(BinaryTree<DataType> &btn);

};

template<class DataType>
BinaryTree<DataType>::BinaryTree() {
    Node = null;
    right = left = nullptr;
}

template<class DataType>
int BinaryTree<DataType>::length = 1;

template<class DataType>
bool BinaryTree<DataType>::isEmpty() {
    return Node == null;
}


template<class DataType>
void BinaryTree<DataType>::insert(DataType item) {
    if (Node == null) {
        Node = Operand;
        num = item;
    } else {
        BinaryTree<DataType> *temp = this;
        BinaryTree<DataType> *rot = this;
        while (temp != nullptr) {
            if (item < temp->num) {
                rot = temp;
                temp = temp->left;
            } else if (item > temp->num) {
                rot = temp;
                temp = temp->right;
            } else temp = nullptr;
        }
        if (item < rot->num)
            rot->left = new BinaryTree<DataType>(item);
        else if (item > rot->num)
            rot->right = new BinaryTree<DataType>(item);
    }
}

template<class DataType>
void BinaryTree<DataType>::MakeLeft(BinaryTree<DataType> &btn) {
    if (Node != null)
        left = &btn;
}

template<class DataType>
void BinaryTree<DataType>::MakeRight(BinaryTree<DataType> &btn) {
    if (Node != null)
        right = &btn;
}

#endif