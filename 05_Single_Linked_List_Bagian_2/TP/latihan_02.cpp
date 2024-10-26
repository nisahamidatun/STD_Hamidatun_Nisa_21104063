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

void inputElements_21104063(List &L) {
    for (int i = 1; i <= 5; i++) {
        int value;
        cout << "Masukkan elemen ke-" << i << " = ";
        cin >> value;
        Node* newNode = alokasi_21104063(value);
        insertLast_21104063(L, newNode);
    }
}

int main() {
    List L;
    createList_21104063(L);
    inputElements_21104063(L);

    cout << "\nList sebelum diurutkan: ";
    printListFromHead_21104063(L);

    bubbleSortList_21104063(L);

    cout << "\nList setelah diurutkan: ";
    printListFromHead_21104063(L);

    return 0;
}
