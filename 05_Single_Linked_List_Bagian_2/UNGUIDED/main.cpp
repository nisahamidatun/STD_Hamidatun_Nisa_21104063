#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    int NIM;
    string Nama;
    Mahasiswa* next;
};

struct List {
    Mahasiswa* first;
};

void createList(List &L) {
    L.first = nullptr;
}

Mahasiswa* alokasi(int nim, string nama) {
    Mahasiswa* newElm = new Mahasiswa;
    newElm->NIM = nim;
    newElm->Nama = nama;
    newElm->next = nullptr;
    return newElm;
}

void insertLast(List &L, Mahasiswa* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        Mahasiswa* temp = L.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = P;
    }
}

Mahasiswa* findElm(List L, int nim) {
    Mahasiswa* temp = L.first;
    while (temp != nullptr) {
        if (temp->NIM == nim) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void printInfo(List L) {
    if (L.first == nullptr) {
        cout << "Data mahasiswa kosong." << endl;
    } else {
        Mahasiswa* temp = L.first;
        while (temp != nullptr) {
            cout << "NIM: " << temp->NIM << ", Nama: " << temp->Nama << endl;
            temp = temp->next;
        }
    }
}

int main() {
    List L;
    createList(L);
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Cari Mahasiswa\n";
        cout << "3. Cetak Semua Mahasiswa\n";
        cout << "4. Selesai\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int nim;
            string nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            Mahasiswa* P = alokasi(nim, nama);
            insertLast(L, P);
            cout << "Mahasiswa dengan NIM " << nim << " berhasil ditambahkan." << endl;
        } else if (pilihan == 2) {
            int nim;
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> nim;
            Mahasiswa* P = findElm(L, nim);
            if (P != nullptr) {
                cout << "Mahasiswa ditemukan: " << P->Nama << endl;
            } else {
                cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
            }
        } else if (pilihan == 3) {
            printInfo(L);
        } else if (pilihan == 4) {
            cout << "Selesai." << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
