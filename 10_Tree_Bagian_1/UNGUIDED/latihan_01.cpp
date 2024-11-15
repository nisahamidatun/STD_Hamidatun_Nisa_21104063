#include <iostream>
#include <queue> 
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

Pohon* insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

void tampilkanChild(Pohon *node) {
    if (!node) {
        cout << "\nNode tidak ditemukan!" << endl;
        return;
    }
    cout << "\nNode: " << node->data;
    if (node->left) {
        cout << "\nChild kiri: " << node->left->data;
    } else {
        cout << "\nChild kiri: (tidak ada)";
    }
    if (node->right) {
        cout << "\nChild kanan: " << node->right->data;
    } else {
        cout << "\nChild kanan: (tidak ada)";
    }
    cout << endl;
}

void tampilkanDescendant(Pohon *node) {
    if (!node) {
        cout << "\nNode tidak ditemukan!" << endl;
        return;
    }
    cout << "\nDescendant dari node " << node->data << ": ";
    queue<Pohon*> q;
    q.push(node);
    while (!q.empty()) {
        Pohon *current = q.front();
        q.pop();
        if (current != node) {
            cout << current->data << " ";
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

int main() {
    init();
    char choice, data, parentData;
    Pohon *node = nullptr;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Tampilkan Child Node\n";
        cout << "5. Tampilkan Descendant Node\n";
        cout << "6. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Masukkan data untuk root: ";
                cin >> data;
                buatNode(data);
                break;
            case '2':
                cout << "Masukkan data node parent: ";
                cin >> parentData;
                cout << "Masukkan data node kiri baru: ";
                cin >> data;
                node = (root->data == parentData) ? root : nullptr; 
                if (node) insertLeft(data, node);
                else cout << "\nParent tidak ditemukan!\n";
                break;
            case '3':
                cout << "Masukkan data node parent: ";
                cin >> parentData;
                cout << "Masukkan data node kanan baru: ";
                cin >> data;
                node = (root->data == parentData) ? root : nullptr; 
                if (node) insertRight(data, node);
                else cout << "\nParent tidak ditemukan!\n";
                break;
            case '4':
                cout << "Masukkan data node untuk melihat child: ";
                cin >> parentData;
                node = (root->data == parentData) ? root : nullptr; 
                tampilkanChild(node);
                break;
            case '5':
                cout << "Masukkan data node untuk melihat descendant: ";
                cin >> parentData;
                node = (root->data == parentData) ? root : nullptr; 
                tampilkanDescendant(node);
                break;
            case '6':
                cout << "Keluar dari program.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
}
