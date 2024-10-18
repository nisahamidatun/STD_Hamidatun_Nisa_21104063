#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
};

void createList(List &L) {
    L.head = nullptr;
}

Node* allocate(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void insertFirst(List &L, int x) {
    Node* newNode = allocate(x);
    newNode->next = L.head;
    L.head = newNode;
}

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

    cout << "1. Tambah node di depan (masukkan nilai): ";
    cin >> value;
    insertFirst(L, value);

    cout << "2. Tambah node di belakang (masukkan nilai): ";
    cin >> value;
    insertLast(L, value);

    cout << "3. Tambah node di depan (masukkan nilai): ";
    cin >> value;
    insertFirst(L, value);

    cout << "Cetak linked list: ";
    printList(L);

    cout << "Program selesai." << endl;

    return 0;
}
