#include <iostream>
#include <climits>
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
bool is_valid_bst(Pohon *node, int min_val, int max_val)
{
    // Valid jika node kosong
    if (node == NULL)
        return true;

    // pemeriksaan node yang di dalam rentang apakah valid
    if (node->data <= min_val || node->data >= max_val)
        return false;

    // pemeriksaan subtree
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

// fungsi pengujian valid BST
void test_is_valid_bst()
{
    Pohon *valid_bst = createNode(9);         // Root = 9
    valid_bst->left = createNode(6);          // Left child = 6
    valid_bst->right = createNode(12);        // Right child = 12
    valid_bst->left->left = createNode(3);    // Left-left child = 3
    valid_bst->left->right = createNode(8);   // Left-right child = 8
    valid_bst->right->left = createNode(11);  // Right-left child = 11
    valid_bst->right->right = createNode(15); // Right-right child = 15

    Pohon *invalid_bst = createNode(9);         // Root = 9
    invalid_bst->left = createNode(6);          // Left child = 6
    invalid_bst->right = createNode(12);        // Right child = 12
    invalid_bst->left->left = createNode(3);    // Left-left child = 3
    invalid_bst->left->right = createNode(8);   // Left-right child = 8
    invalid_bst->right->right = createNode(18); // Right-right child = 18
    invalid_bst->right->left = createNode(10);  // Tidak valid karena 10 < 12, jadi salah posisi

    cout << "Uji Valid BST:" << endl;
    if (is_valid_bst(valid_bst, INT_MIN, INT_MAX))
        cout << "Valid BST" << endl;
    else
        cout << "Invalid BST" << endl;

    cout << "\nUji Invalid BST:" << endl;
    if (is_valid_bst(invalid_bst, INT_MIN, INT_MAX))
        cout << "Valid BST" << endl;
    else
        cout << "Invalid BST" << endl;
}

int main()
{
    test_is_valid_bst();
    return 0;
}
