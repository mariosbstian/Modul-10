#include <iostream>
#include "bstree3.h"

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
}

// cari node
NodePtr searchNode(DataType x, NodePtr &root) {
    if (root == EMPTY) {
        cout << "Tree kosong!" << endl;
        return EMPTY;
    }
    NodePtr current = root;
    NodePtr parent = EMPTY;
    bool found = false;

    while (current != EMPTY) {
        if (x < current->value) {
            parent = current;
            current = current->left;
        } else if (x > current->value) {
            parent = current;
            current = current->right;
        } else {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        cout << "Data ditemukan didalam tree!" << endl;
        cout << "Data: " << current->value << endl;
    }
    return current;
}

// traversal inorder
void traverseInOrder(NodePtr root) {
    if (root != EMPTY) {
        traverseInOrder(root->left);
        cout << root->value << " - ";
        traverseInOrder(root->right);
    }
}

// traversal preorder
void traversePreOrder(NodePtr root) {
    if (root == EMPTY) return;
    cout << root->value << " - ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

// traversal postorder
void traversePostOrder(NodePtr root) {
    if (root == EMPTY) return;
    traversePostOrder(root->left);
    traversePostOrder(root->right);
    cout << root->value << " - ";
}
