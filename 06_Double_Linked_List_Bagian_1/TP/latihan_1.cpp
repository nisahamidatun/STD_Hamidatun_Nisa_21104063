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

void insertSorted_21104063(List &L, Node* P) {
    if (L.head == nullptr || L.head->data >= P->data) {
        P->next = L.head;
        if (L.head != nullptr) {
            L.head->prev = P;
        }
        L.head = P;
        if (L.tail == nullptr) {
            L.tail = P;
        }
    } else {
        Node* current = L.head;
        while (current->next != nullptr && current->next->data < P->data) {
            current = current->next;
        }
        P->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = P;
        } else {
            L.tail = P;
        }
        current->next = P;
        P->prev = current;
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

void bubbleSortList_21104063(List &L) {
    if (L.head == nullptr || L.head->next == nullptr) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = L.head;

        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
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

int main() {
    List L;
    createList_21104063(L);

    int value;
    
    cout << "Masukkan elemen pertama = ";
    cin >> value;
    Node* newNode = alokasi_21104063(value);
    insertLast_21104063(L, newNode);

    cout << "Masukkan elemen kedua di awal = ";
    cin >> value;
    newNode = alokasi_21104063(value);
    insertFirst_21104063(L, newNode);

    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> value;
    newNode = alokasi_21104063(value);
    insertLast_21104063(L, newNode);

    cout << "\nDAFTAR ANGGOTA LIST: ";
    printListFromHead_21104063(L);

    return 0;
}
