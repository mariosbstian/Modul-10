#ifndef BSTREE2_H
#define BSTREE2_H

#define EMPTY nullptr

typedef int DataType;
struct TreeNode;
typedef TreeNode* NodePtr;

struct TreeNode {
    DataType value;
    NodePtr left;
    NodePtr right;
};

// deklarasi fungsi
NodePtr createNode(DataType x);
void addNode(NodePtr &root, DataType x);
void traverseInOrder(NodePtr root);

int countNodes(NodePtr root);
int sumNodes(NodePtr root);
int getDepth(NodePtr root, int level);

#endif
