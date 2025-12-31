#ifndef BSTREE1_H
#define BSTREE1_H

#define NULLPTR nullptr

typedef int DataType;
struct TreeNode;
typedef TreeNode* NodePtr;

struct TreeNode {
    DataType value;
    NodePtr leftChild;
    NodePtr rightChild;
};

// alokasi node baru
NodePtr createNode(DataType x);

// memasukkan node ke BST
void addNode(NodePtr &root, DataType x);

// mencari node di BST
NodePtr searchNode(DataType x, NodePtr root);

// traversal inorder
void traverseInOrder(NodePtr root);

#endif
