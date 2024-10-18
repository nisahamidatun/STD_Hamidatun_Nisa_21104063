#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Membuat list kosong
struct List {
    Node* head;
};

// Inisialisasi list kosong
void createList(List &L) {
    L.head = nullptr;
}

// Alokasi memori untuk node baru
Node* allocate(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

// Menambah node di depan
void insertFirst(List &L, int x) {
    Node* newNode = allocate(x);
    newNode->next = L.head;
    L.head = newNode;
}

// Menambah node di belakang
void insertLast(List &L, int x) {
    Node* newNode = allocate(x);
    if (L.head == nullptr) {
        L.head = newNode;
    } else {
        Node* temp = L.head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Menghapus node berdasarkan nilai
void deleteNode(List &L, int x) {
    Node* temp = L.head;
    Node* prev = nullptr;

    // Jika node pertama yang akan dihapus
    if (temp != nullptr && temp->data == x) {
        L.head = temp->next;  // Head berubah menjadi node berikutnya
        delete temp;          // Hapus node lama
        return;
    }

    // Cari node yang memiliki nilai x
    while (temp != nullptr && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    // Jika tidak ditemukan
    if (temp == nullptr) return;

    // Node ditemukan, hapus node
    prev->next = temp->next;
    delete temp;
}

// Mencetak seluruh isi linked list
void printList(List L) {
    Node* temp = L.head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    List L;
    createList(L);

    int value;

    cout << "Tambah node di depan (masukkan nilai): ";
    cin >> value;
    insertFirst(L, value); 

    cout << "Tambah node di belakang (masukkan nilai): ";
    cin >> value;
    insertLast(L, value); 

    cout << "Tambah node di depan (masukkan nilai): ";
    cin >> value;
    insertFirst(L, value); 

    cout << "Hapus node dengan nilai (masukkan nilai): ";
    cin >> value;
    deleteNode(L, value); 

    cout << "Isi linked list: ";
    printList(L);

    return 0;
}
