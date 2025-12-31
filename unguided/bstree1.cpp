#include <iostream>
#include "bstree1.h"

using namespace std;

// alokasi node baru
NodePtr createNode(DataType x) {
    NodePtr newNode = new TreeNode;
    if (newNode != NULLPTR) {
        newNode->value = x;
        newNode->leftChild = NULLPTR;
        newNode->rightChild = NULLPTR;
    }
    return newNode;
}

// insert node ke BST
void addNode(NodePtr &root, DataType x) {
    if (root == NULLPTR) {
        root = createNode(x);
    } else if (x < root->value) {
        addNode(root->leftChild, x);
    } else if (x > root->value) {
        addNode(root->rightChild, x);
    }
    // jika sama, tidak dimasukkan
}

// mencari node
NodePtr searchNode(DataType x, NodePtr root) {
    if (root == NULLPTR || root->value == x)
        return root;
    if (x < root->value)
        return searchNode(x, root->leftChild);
    return searchNode(x, root->rightChild);
}

// traversal inorder
void traverseInOrder(NodePtr root) {
    if (root != NULLPTR) {
        traverseInOrder(root->leftChild);
        cout << root->value << " ";
        traverseInOrder(root->rightChild);
    }
}
