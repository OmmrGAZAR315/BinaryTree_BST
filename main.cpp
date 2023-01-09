#include <iostream>

using namespace std;

#include "BinaryTree.h"


template<class DataType>
void PreOrder(BinaryTree<DataType> *btn) {
    if (btn != nullptr) {
        cout << btn->num << ", ";
        PreOrder(btn->left);
        PreOrder(btn->right);
    }
}

template<class DataType>
void InOrder(BinaryTree<DataType> *btn) {
    if (btn != nullptr) {
        InOrder(btn->left);
        cout << btn->num << ", ";
        InOrder(btn->right);
    }
}

template<class DataType>
void PostOrder(BinaryTree<DataType> *btn) {
    if (btn != nullptr) {
        PostOrder(btn->left);
        PostOrder(btn->right);
        cout << btn->num << ", ";
    }
}

int main() {
    BinaryTree<int> bt1;
    bt1.insert(90);
    BinaryTree<int> bt2;
    bt2.insert(80);
    BinaryTree<int> bt3;

    bt1.MakeLeft(bt2);
    bt1.MakeRight(bt3);

    bt3.insert(70);
    BinaryTree<int> bt4;
    bt4.insert(60);
    BinaryTree<int> bt5;
    bt5.insert(95);

    bt3.MakeLeft(bt4);
    bt3.MakeRight(bt5);

    BinaryTree<int> bt6;
    bt6.insert(30);
    BinaryTree<int> bt7;
    bt7.insert(120);

    bt2.MakeLeft(bt6);
    bt2.MakeRight(bt7);

    BinaryTree<int> bt8;
    bt8.insert(69);
    bt4.MakeRight(bt8);

    BinaryTree<int> binaryTree;
    binaryTree.insert(20);
    binaryTree.insert(17);
    binaryTree.insert(15);
    binaryTree.insert(19);
    binaryTree.insert(30);
    binaryTree.insert(25);
    binaryTree.insert(29);
    binaryTree.insert(35);
    binaryTree.insert(36);
    binaryTree.insert(34);

    BinaryTree<int> binaryTree1;
    binaryTree1.insert(100);
    binaryTree1.insert(117);
    binaryTree1.insert(115);
    binaryTree1.insert(119);
    binaryTree1.insert(130);
    binaryTree1.insert(125);
    binaryTree1.insert(129);
    binaryTree1.insert(135);
    binaryTree1.insert(136);
    binaryTree1.insert(134);

    binaryTree1.MakeLeft(bt1);
    BinaryTree<int> binaryTree2(50);
    binaryTree2.MakeLeft(binaryTree);
    binaryTree2.MakeRight(binaryTree1);

    cout << "PreOrder :";
    PreOrder(&binaryTree2);
    cout << "\nInOrder :";
    InOrder(&binaryTree2);
    cout << "\nPostOrder :";
    PostOrder(&binaryTree2);

    return 0;

}