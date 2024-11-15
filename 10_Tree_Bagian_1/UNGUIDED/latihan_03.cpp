#include <iostream>
using namespace std;

struct Pohon
{
    int data;
    Pohon *left, *right;
};

Pohon *createNode(int data)
{
    return new Pohon{data, NULL, NULL};
}

// Fungsi rekursif menghitung jumlah simpul daun
int cari_simpul_daun(Pohon *node)
{
    if (node == NULL)
    {
        return 0;
    }
    // node apakah simpul daun
    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }

    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

void test_cari_simpul_daun()
{
    Pohon *root = createNode(9);
    root->left = createNode(6);
    root->right = createNode(12);
    root->left->left = createNode(3);
    root->left->right = createNode(8);
    root->right->right = createNode(18);

    cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
}

int main()
{
    test_cari_simpul_daun();
    return 0;
}
