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

bool searchNode(List L, int x) {
    Node* temp = L.head;
    while (temp != nullptr) {
        if (temp->data == x) {
            return true;  
        }
        temp = temp->next;
    }
    return false;  
}

int length(List L) {
    int count = 0;
    Node* temp = L.head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
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

    int value, searchValue;

    cout << "Tambah node di depan (masukkan nilai): ";
    cin >> value;
    insertFirst(L, value);

    cout << "Tambah node di belakang (masukkan nilai): ";
    cin >> value;
    insertLast(L, value);

    cout << "Tambah node di depan (masukkan nilai): ";
    cin >> value;
    insertFirst(L, value);

    cout << "Cari node dengan nilai (masukkan nilai): ";
    cin >> searchValue;
    if (searchNode(L, searchValue)) {
        cout << "Node dengan nilai " << searchValue << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << searchValue << " tidak ditemukan." << endl;
    }

    cout << "Panjang linked list: " << length(L) << endl;

    return 0;
}
