#include <iostream>
#include <string>

using namespace std;

struct Buku {
    int IDBuku;
    string JudulBuku;
    string PenulisBuku;
    Buku* next;
    Buku* prev;
};

struct List {
    Buku* first;
    Buku* last;
};

void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

Buku* alokasi(int id, string judul, string penulis) {
    Buku* newElm = new Buku;
    newElm->IDBuku = id;
    newElm->JudulBuku = judul;
    newElm->PenulisBuku = penulis;
    newElm->next = nullptr;
    newElm->prev = nullptr;
    return newElm;
}

void insertLast(List &L, Buku* P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printFromFirst(List L) {
    if (L.first == nullptr) {
        cout << "Daftar buku kosong." << endl;
    } else {
        Buku* temp = L.first;
        while (temp != nullptr) {
            cout << "ID Buku: " << temp->IDBuku << ", Judul: " << temp->JudulBuku << ", Penulis: " << temp->PenulisBuku << endl;
            temp = temp->next;
        }
    }
}

void printFromLast(List L) {
    if (L.last == nullptr) {
        cout << "Daftar buku kosong." << endl;
    } else {
        Buku* temp = L.last;
        while (temp != nullptr) {
            cout << "ID Buku: " << temp->IDBuku << ", Judul: " << temp->JudulBuku << ", Penulis: " << temp->PenulisBuku << endl;
            temp = temp->prev;
        }
    }
}

int main() {
    List L;
    createList(L);
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Menampilkan Semua Buku dari Awal ke Akhir\n";
        cout << "3. Menampilkan semua Buku dari Akhir ke Awal\n";
        cout << "4. Selesai\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id;
            string judul, penulis;
            cout << "Masukkan ID Buku: ";
            cin >> id;
            cout << "Masukkan Judul Buku: ";
            cin.ignore();
            getline(cin, judul);
            cout << "Masukkan Penulis Buku: ";
            getline(cin, penulis);
            Buku* P = alokasi(id, judul, penulis);
            insertLast(L, P);
            cout << "Buku dengan ID " << id << " berhasil ditambahkan." << endl;
        } else if (pilihan == 2) {
            printFromFirst(L);
        } else if (pilihan == 3) {
            printFromLast(L);
        } else if (pilihan == 4) {
            cout << "Selesai." << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
