#include <iostream>
using namespace std;

struct Node
{
    string nama;
    string nim;
    Node *next;
};

Node *front = nullptr;
Node *rear = nullptr;

bool isEmpty()
{
    return front == nullptr;
}

void enqueue()
{
    Node *newNode = new Node();

    cout << "Masukkan Nama Mahasiswa: ";
    cin >> newNode->nama;

    cout << "Masukkan NIM Mahasiswa: ";
    cin >> newNode->nim;

    newNode->next = nullptr;

    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued: " << newNode->nama << " (NIM: " << newNode->nim << ")" << endl;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        cout << "Dequeued: " << temp->nama << " (NIM: " << temp->nim << ")" << endl;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
        }
    }
}

int countQueue()
{
    int count = 0;
    Node *temp = front;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue()
{
    while (!isEmpty())
    {
        dequeue();
    }
    cout << "Antrian telah dikosongkan" << endl;
}

void viewQueue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        cout << "Data antrian mahasiswa:" << endl;
        int pos = 1;
        while (temp != nullptr)
        {
            cout << pos << ". Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
            pos++;
        }
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue (Tambahkan Mahasiswa)\n";
        cout << "2. Dequeue (Hapus Mahasiswa)\n";
        cout << "3. View Queue (Lihat Semua Mahasiswa dalam Antrian)\n";
        cout << "4. Clear Queue (Kosongkan Antrian)\n";
        cout << "0. Exit\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            viewQueue();
            break;
        case 4:
            clearQueue();
            break;
        case 0:
            cout << "Selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak ada, coba lagi." << endl;
        }
    } while (choice != 0);

    return 0;
}
