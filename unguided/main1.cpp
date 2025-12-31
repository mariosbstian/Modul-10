#include <iostream>
#include "bstree1.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    NodePtr root = NULLPTR;
    addNode(root, 1);
    addNode(root, 2);
    addNode(root, 6);
    addNode(root, 4);
    addNode(root, 5);
    addNode(root, 3);
    addNode(root, 6);
    addNode(root, 7);

    traverseInOrder(root);
    return 0;
}
