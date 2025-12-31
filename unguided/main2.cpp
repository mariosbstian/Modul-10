#include <iostream>
#include "bstree2.h"

using namespace std;

int main() {
    NodePtr root = EMPTY;

    addNode(root, 1);
    addNode(root, 2);
    addNode(root, 6);
    addNode(root, 4);
    addNode(root, 5);
    addNode(root, 3);
    addNode(root, 7);

    traverseInOrder(root);
    cout << "\n";

    cout << "kedalaman : " << getDepth(root, 0) << endl;
    cout << "jumlah Node : " << countNodes(root) << endl;
    cout << "total : " << sumNodes(root) << endl;

    return 0;
}
