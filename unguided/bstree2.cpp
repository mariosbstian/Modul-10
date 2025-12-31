#include <iostream>
#include "bstree2.h"

using namespace std;

// alokasi node baru
NodePtr createNode(DataType x) {
    NodePtr node = new TreeNode;
    if (node != EMPTY) {
        node->value = x;
        node->left = EMPTY;
        node->right = EMPTY;
    }
    return node;
}

// insert node ke BST
void addNode(NodePtr &root, DataType x) {
    if (root == EMPTY)
        root = createNode(x);
    else if (x < root->value)
        addNode(root->left, x);
    else if (x > root->value)
        addNode(root->right, x);
    // jika sama, tidak dimasukkan
}

// traversal inorder
void traverseInOrder(NodePtr root) {
    if (root != EMPTY) {
        traverseInOrder(root->left);
        cout << root->value << " ";
        traverseInOrder(root->right);
    }
}

// hitung jumlah node
int countNodes(NodePtr root) {
    if (root == EMPTY) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// hitung total semua node
int sumNodes(NodePtr root) {
    if (root == EMPTY) return 0;
    return root->value + sumNodes(root->left) + sumNodes(root->right);
}

// hitung kedalaman tree
int getDepth(NodePtr root, int level) {
    if (root == EMPTY) return level;
    int leftDepth = getDepth(root->left, level + 1);
    int rightDepth = getDepth(root->right, level + 1);
    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
}
