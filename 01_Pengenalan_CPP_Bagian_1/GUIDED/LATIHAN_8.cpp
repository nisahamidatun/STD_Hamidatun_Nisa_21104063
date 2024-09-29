#include <iostream>
#include <conio.h>
#define MAX 5

using namespace std;

int main() {
    int i;

    struct data {
        char nama[40];
        int nilai;
    };

    data siswa[MAX];

    for (i = 0; i < MAX; i++) {
        cout << "masukkan data ke-" << i + 1 << endl;
        cout << "nama = ";
        cin >> siswa[i].nama;
        cout << "nilai = ";
        cin >> siswa[i].nilai;
    }

    cout << "\ndata siswa\n";
    for (i = 0; i < MAX; i++) {
        cout << "Nama: " << siswa[i].nama << ", Nilai: " << siswa[i].nilai << endl;
    }

    getch(); // Menunggu input dari pengguna sebelum menutup program
    return 0;
}
