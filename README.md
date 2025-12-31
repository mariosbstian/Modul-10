# <h1 align="center">Laporan Praktikum Modul (10)</h1>
<p align="center">Mario Sebastian Barus</p>

## Dasar Teori
Binary Search Tree atau BST adalah struktur data berbentuk pohon yang digunakan untuk menyimpan data secara terstruktur. Setiap simpul dalam BST bisa memiliki maksimal dua anak, yaitu anak kiri dan anak kanan. Aturannya, nilai anak kiri selalu lebih kecil daripada induknya, sedangkan nilai anak kanan selalu lebih besar. Dengan aturan ini, BST memudahkan kita dalam melakukan pencarian, penambahan, maupun penghapusan data secara cepat dibandingkan struktur data biasa seperti array atau linked list.

Selain itu, BST juga mendukung beberapa cara untuk menelusuri seluruh isi pohon, yang dikenal sebagai traversal. Tiga metode traversal yang sering digunakan adalah:

Inorder: mengunjungi anak kiri, lalu simpul induk, kemudian anak kanan; biasanya dipakai untuk menampilkan data secara urut.

Preorder: mengunjungi simpul induk terlebih dahulu, kemudian anak kiri dan anak kanan; cocok untuk menyalin atau menyimpan struktur pohon.

Postorder: mengunjungi anak kiri, anak kanan, lalu simpul induk; berguna untuk menghapus seluruh node atau melakukan evaluasi ekspresi.

BST juga bisa dianalisis lebih jauh, misalnya menghitung jumlah simpul, tinggi pohon, nilai maksimum dan minimum, hingga total semua nilai node. Karena sifatnya yang terstruktur, operasi di BST rata-rata bisa dilakukan dengan cepat, membuatnya efektif untuk berbagai kebutuhan pemrograman dan pengolahan data.
## Guided 

### bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; 

struct BST {
    int angka;
    node left;
    node right;
};

typedef node BinTree; 

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```
### bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(BinTree tree) {
    return tree == Nil;
}

void createTree(BinTree &tree) {
    tree = Nil;
}

node alokasi(int angkaInput) {
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus) {
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru) {
    if (tree == Nil) {
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan!" << endl;
    } else if (nodeBaru->angka < tree->angka) {
        insertNode(tree->left, nodeBaru);
    } else if (nodeBaru->angka > tree->angka) {
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari) {
    if (isEmpty(tree)) {
        cout << "Tree kosong!" << endl;
        return;
    }
    node nodeBantu = tree;
    node parent = Nil;
    bool ketemu = false;
    while (nodeBantu != Nil) {
        if (angkaCari < nodeBantu->angka) {
            parent = nodeBantu;
            nodeBantu = nodeBantu->left;
        } else if (angkaCari > nodeBantu->angka) {
            parent = nodeBantu;
            nodeBantu = nodeBantu->right;
        } else {
            ketemu = true;
            break;
        }
    }
    if (!ketemu) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        cout << "Data ditemukan!" << endl;
        cout << "Parent: " << (parent ? to_string(parent->angka) : "- (Root)") << endl;
        cout << "Child kiri: " << (nodeBantu->left ? to_string(nodeBantu->left->angka) : "-") << endl;
        cout << "Child kanan: " << (nodeBantu->right ? to_string(nodeBantu->right->angka) : "-") << endl;
    }
}

void preOrder(BinTree tree) {
    if (tree != Nil) {
        cout << tree->angka << " - ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(BinTree tree) {
    if (tree != Nil) {
        inOrder(tree->left);
        cout << tree->angka << " - ";
        inOrder(tree->right);
    }
}

void postOrder(BinTree tree) {
    if (tree != Nil) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->angka << " - ";
    }
}

node mostLeft(BinTree tree) {
    while (tree && tree->left != Nil) tree = tree->left;
    return tree;
}

node mostRight(BinTree tree) {
    while (tree && tree->right != Nil) tree = tree->right;
    return tree;
}

bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) return false;
    if (angka < tree->angka) return deleteNode(tree->left, angka);
    if (angka > tree->angka) return deleteNode(tree->right, angka);
    
    node tmp = tree;
    if (tree->left == Nil) {
        tree = tree->right;
        dealokasi(tmp);
    } else if (tree->right == Nil) {
        tree = tree->left;
        dealokasi(tmp);
    } else {
        node successor = mostLeft(tree->right);
        tree->angka = successor->angka;
        return deleteNode(tree->right, successor->angka);
    }
    return true;
}

void deleteTree(BinTree &tree) {
    if (tree != Nil) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree) {
    return (tree == Nil) ? 0 : 1 + size(tree->left) + size(tree->right);
}

int height(BinTree tree) {
    if (tree == Nil) return -1;
    return 1 + max(height(tree->left), height(tree->right));
}
```
### main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);
    int pilih, angka;

    do {
        cout << "\n========= MENU BST =========" << endl;
        cout << "1. Insert | 2. Delete | 3. Search | 4. PreOrder | 5. InOrder | 6. PostOrder" << endl;
        cout << "7. Size   | 8. Height | 9. MostRight | 10. MostLeft | 11. Clear | 0. Exit" << endl;
        cout << "Pilihan: "; cin >> pilih;

        switch (pilih) {
            case 1: cout << "Angka: "; cin >> angka; insertNode(tree, alokasi(angka)); break;
            case 2: cout << "Hapus: "; cin >> angka; deleteNode(tree, angka); break;
            case 3: cout << "Cari: "; cin >> angka; searchByData(tree, angka); break;
            case 4: preOrder(tree); break;
            case 5: inOrder(tree); break;
            case 6: postOrder(tree); break;
            case 7: cout << "Size: " << size(tree); break;
            case 8: cout << "Height: " << height(tree); break;
            case 9: if(tree) cout << "MostRight: " << mostRight(tree)->angka; break;
            case 10: if(tree) cout << "MostLeft: " << mostLeft(tree)->angka; break;
            case 11: deleteTree(tree); break;
        }
    } while (pilih != 0);
    return 0;
}
   
```

## Unguided 

### 1. [main1.cpp]

```C++
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


```
Program ini membangun BST dengan memasukkan beberapa angka, kemudian menampilkan semua nilai secara berurutan menggunakan traversal inorder, sementara nilai duplikat diabaikan.
#### Full code Screenshot:
<img width="500" height="482" alt="image" src="https://github.com/user-attachments/assets/0ab21896-f202-4bc8-869a-5d701c8dd20d" />

### [bstree1.cpp]

```C++
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

```

Program ini menangani Binary Search Tree, termasuk membuat simpul baru, menambahkan nilai ke tree dengan aturan BST, mencari simpul tertentu, dan menampilkan semua nilai secara terurut menggunakan traversal inorder.
#### Full code Screenshot:
<img width="361" height="593" alt="image" src="https://github.com/user-attachments/assets/e4d93f3c-c68a-4d7e-9b5c-5ad8e388f2c5" />


### [bstree1.h]

```C++
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

```

#### Output:
<img width="314" height="52" alt="image" src="https://github.com/user-attachments/assets/01bf6dc3-0505-4a99-8cc0-38fafbe3545c" />

Header ini menyusun BST dengan simpul yang memiliki anak kiri dan kanan, serta menyediakan fungsi-fungsi untuk membuat simpul, menambah nilai ke tree, mencari simpul tertentu, dan menampilkan nilai tree secara berurutan dengan traversal inorder.
#### Full code Screenshot:
<img width="366" height="371" alt="image" src="https://github.com/user-attachments/assets/e53620db-198b-4073-8200-3f447b7406d8" />

### 2. [main2.cpp]

```C++
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


```
Program ini membuat BST, menambahkan beberapa angka, menampilkan nilai secara berurutan, serta memberikan informasi tambahan tentang tree, termasuk kedalaman, jumlah simpul, dan total nilai seluruh simpul.
#### Full code Screenshot:
<img width="425" height="331" alt="image" src="https://github.com/user-attachments/assets/2875e9f8-3109-4816-8a4a-1d981a04b598" />

### [bstree2.cpp]

```C++
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

```

Program ini menangani BST, termasuk membuat dan menambahkan simpul, menampilkan nilai secara terurut dengan inorder traversal, menghitung jumlah simpul, menjumlahkan semua nilai, dan menghitung kedalaman tree untuk analisis strukturnya.
#### Full code Screenshot:
<img width="451" height="542" alt="image" src="https://github.com/user-attachments/assets/3af582e2-6922-481c-975d-d7223c371d99" />
<img width="515" height="381" alt="image" src="https://github.com/user-attachments/assets/8cb99c44-e855-4468-b50f-f9b113544508" />


### [bstree2.h]

```C++
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

```

#### Output:
<img width="345" height="77" alt="image" src="https://github.com/user-attachments/assets/2ed38759-fb7c-483b-b602-f00fcba2c476" />

Header ini menyusun BST dengan simpul yang memiliki anak kiri dan kanan, serta menyediakan fungsi-fungsi untuk membuat dan menambahkan simpul, menampilkan nilai secara berurutan, menghitung jumlah dan total nilai simpul, serta mengukur kedalaman tree.

#### Full code Screenshot:
<img width="354" height="332" alt="image" src="https://github.com/user-attachments/assets/a8cb8c9f-b562-41c5-b995-799692cff5f0" />

### 3. [main3.cpp]

```C++
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

```
Program ini membangun BST, menambahkan sejumlah angka, dan menampilkan isi tree dari berbagai urutan dengan metode preorder dan postorder.
#### Full code Screenshot:
<img width="380" height="370" alt="image" src="https://github.com/user-attachments/assets/becf61d2-4f16-41be-9c32-1af6d382832e" />

### [bstree3.cpp]

```C++
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


```

Program ini menangani BST, termasuk membuat dan menambahkan simpul, mencari nilai tertentu, serta menampilkan isi tree dengan traversal inorder, preorder, dan postorder untuk eksplorasi data dari berbagai sudut.
#### Full code Screenshot:
<img width="392" height="633" alt="image" src="https://github.com/user-attachments/assets/21fabba0-6ff2-4599-ab0d-744e915b87c4" />
<img width="383" height="192" alt="image" src="https://github.com/user-attachments/assets/f79e593e-b8a7-4dc4-918d-1462dfc46f89" />


### [bstree3.h]

```C++
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


```

#### Output:
<img width="523" height="89" alt="image" src="https://github.com/user-attachments/assets/fff2a6e3-f8ca-43f8-9ea4-476b688cde1d" />

Kode ini mendefinisikan Binary Search Tree (BST) dengan simpul (TreeNode) yang memiliki anak kiri dan kanan. Di dalamnya terdapat deklarasi fungsi untuk membuat simpul baru, menambahkan simpul ke BST, mencari simpul berdasarkan nilai, serta menelusuri tree menggunakan tiga metode traversal: inorder, preorder, dan postorder.
#### Full code Screenshot:
<img width="320" height="263" alt="image" src="https://github.com/user-attachments/assets/bde8cbe2-6ab3-4635-83b1-d3518d18c370" />


## Kesimpulan
BST adalah struktur data pohon dengan aturan anak kiri lebih kecil dan anak kanan lebih besar dari induk, memudahkan operasi pencarian, penambahan, dan penghapusan data. Traversal inorder, preorder, dan postorder memungkinkan eksplorasi tree untuk berbagai kebutuhan, termasuk pengurutan, penyalinan, dan penghapusan node secara sistematis.
## Referensi
[1] Malau, E., & Sirait, H. P. (2021). Implementasi teknik Binary Search Tree pada pencarian data penduduk.
[2] Khese, M. C. S., & Priyadarshi, A. (2015). Binary Search Tree and Its Applications: A Survey.
[3] Ahlswede, R., Aigner, M., & Bayer, P. J. (1993). On binary search trees.
