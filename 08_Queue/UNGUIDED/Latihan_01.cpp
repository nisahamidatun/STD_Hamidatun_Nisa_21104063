#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued: " << data << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
        
        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeue();
    }
    cout << "Antrian telah dikosongkan" << endl;
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        cout << "Data antrian teller:" << endl;
        int pos = 1;
        while (temp != nullptr) {
            cout << pos << ". " << temp->data << endl;
            temp = temp->next;
            pos++;
        }
    }
}

int main() {
    enqueue("Andi");
    enqueue("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
