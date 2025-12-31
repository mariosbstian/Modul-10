#ifndef BSTREE3_H
#define BSTREE3_H

#define EMPTY nullptr

typedef int DataType;

struct TreeNode {
    DataType value;
    TreeNode* left;
    TreeNode* right;
};

typedef TreeNode* NodePtr;

NodePtr createNode(DataType x);
void addNode(NodePtr &root, DataType x);
NodePtr searchNode(DataType x, NodePtr &root);

void traverseInOrder(NodePtr root);
void traversePreOrder(NodePtr root);
void traversePostOrder(NodePtr root);

#endif
