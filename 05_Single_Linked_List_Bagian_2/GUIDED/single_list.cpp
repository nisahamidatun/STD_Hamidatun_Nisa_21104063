#include <iostream>

using namespace std;

// Definisi tipe data elemen dan pointer ke elemen
struct Elemen
{
    int data;
    Elemen *next;
};

// Definisi tipe data untuk list
struct List
{
    Elemen *first;
};

// Fungsi untuk membuat list kosong
void createList(List &L)
{
    L.first = NULL;
}

// Fungsi untuk mengalokasikan elemen baru
Elemen *alokasi(int x)
{
    Elemen *P = new Elemen;
    if (P != NULL)
    {
        P->data = x;
        P->next = NULL;
    }

    return P;
}

// Fungsi untuk menambahkan elemen di awal list
void insertFirst(List &L, Elemen *P)
{
    P->next = L.first;
    L.first = P;
}

// Fungsi untuk mencetak semua elemen di list
void printInfo(List L)
{
    Elemen *P = L.first;
    while (P != NULL)
    {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

// Fungsi untuk mencari elemen dengan nilai x
Elemen *findElm(List L, int x)
{
    Elemen *P = L.first;
    while (P != NULL)
    {
        if (P->data == x)
        {
            return P; // Elemen ditemukan
        }
        P = P->next;
    }
    return NULL; // Elemen tidak ditemukan
}

// Fungsi untuk menghitung total nilai semua elemen dalam list
int sumAllElements(List L)
{
    int total = 0;
    Elemen *P = L.first;
    while (P != NULL)
    {
        total += P->data;
        P = P->next;
    }
    return total;
}