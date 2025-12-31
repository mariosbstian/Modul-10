#include <iostream>
#include "bstree3.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    NodePtr root = EMPTY;

    addNode(root, 6);
    addNode(root, 7);
    addNode(root, 4);
    addNode(root, 5);
    addNode(root, 2);
    addNode(root, 3);
    addNode(root, 1);

    cout << "Tampilkan preOrder : ";
    traversePreOrder(root);
    cout << endl;

    cout << "Tampilkan postOrder : ";
    traversePostOrder(root);
    cout << endl;

    return 0;
}
