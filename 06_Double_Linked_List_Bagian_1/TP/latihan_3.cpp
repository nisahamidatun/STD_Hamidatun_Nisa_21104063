#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct List {
    Node* head;
    Node* tail;
};

void createList_21104063(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

Node* alokasi_21104063(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertFirst_21104063(List &L, Node* P) {
    if (L.head == nullptr) {
        L.head = P;
        L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast_21104063(List &L, Node* P) {
    if (L.tail == nullptr) {
        L.head = P;
        L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void deleteFirst_21104063(List &L) {
    if (L.head == nullptr) {
        cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
    } else if (L.head == L.tail) {
        delete L.head;
        L.head = nullptr;
        L.tail = nullptr;
    } else {
        Node* temp = L.head;
        L.head = L.head->next;
        L.head->prev = nullptr;
        delete temp;
    }
}

void deleteLast_21104063(List &L) {
    if (L.tail == nullptr) {
        cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
    } else if (L.head == L.tail) {
        delete L.tail;
        L.head = nullptr;
        L.tail = nullptr;
    } else {
        Node* temp = L.tail;
        L.tail = L.tail->prev;
        L.tail->next = nullptr;
        delete temp;
    }
}

void printListFromHead_21104063(List L) {
    if (L.head == nullptr) {
        cout << "List kosong." << endl;
    } else {
        Node* temp = L.head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}

void printListFromTail_21104063(List L) {
    if (L.tail == nullptr) {
        cout << "List kosong." << endl;
    } else {
        Node* temp = L.tail;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->prev != nullptr) {
                cout << " <-> ";
            }
            temp = temp->prev;
        }
        cout << endl;
    }
}

int main() {
    List L;
    createList_21104063(L);

    int value;
    
    // Input empat elemen secara berurutan
    for (int i = 1; i <= 4; i++) {
        cout << "Masukkan elemen ke-" << i << " = ";
        cin >> value;
        Node* newNode = alokasi_21104063(value);
        insertLast_21104063(L, newNode);
    }

    // Cetak list dari depan ke belakang
    cout << "\nDaftar elemen dari depan ke belakang: ";
    printListFromHead_21104063(L);

    // Cetak list dari belakang ke depan
    cout << "\nDaftar elemen dari belakang ke depan: ";
    printListFromTail_21104063(L);

    return 0;
}
