#include <iostream>
using namespace std;

// Program Binary Tree

// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
bool isEmpty()
{
    return root == NULL;
}

// Buat Node baru
void createNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Tambah kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat Tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
        return NULL;
    }
    if (node->right != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Ubah data Tree
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node)
    {
        cout << "\nNode yang ingin diganti tidak ada!" << endl;
        return;
    }
    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}

// Lihat isi data tree
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData Node: " << node->data << endl;
}

// Cari data tree
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat Tree terlebih dahulu!" << endl;
        return;
    }
    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData Node: " << node->data << endl;
    cout << "Root: " << root->data << endl;
    cout << "Parent: " << (node->parent ? node->parent->data : '(tidak punya parent)') << endl;

    if (node->parent)
    {
        if (node->parent->left == node && node->parent->right)
            cout << "Sibling: " << node->parent->right->data << endl;
        else if (node->parent->right == node && node->parent->left)
            cout << "Sibling: " << node->parent->left->data << endl;
        else
            cout << "Sibling: (tidak ada sibling)" << endl;
    }
}

// Fungsi main
int main()
{
    init();
    createNode('A');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeC = insertRight('A', root);
    insertLeft('D', nodeB);
    insertRight('E', nodeB);
    insertLeft('F', nodeC);
    insertRight('G', nodeC);

    cout << "\n== Pemanggilan Retrieve";
    retrieve(root);
    retrieve(nodeB);
    retrieve(nodeC);

    cout << "\n== Pemanggilan Find (Node B)";
    find(nodeB);

    cout << "\n== Pemanggilan Find (Node C)";
    find(nodeC);

    cout << "\n== Pemanggilan Update (Mengubah Node B menjadi Z)";
    update('Z', nodeB);

    cout << "\n== Pemanggilan Retrieve setelah Update";
    retrieve(nodeB);

    return 0;
}