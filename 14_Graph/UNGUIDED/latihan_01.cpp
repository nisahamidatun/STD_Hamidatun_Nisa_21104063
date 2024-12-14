#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int jumlahSimpul;

    // Input jumlah simpul (kota)
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> namaSimpul(jumlahSimpul);          // Simpan nama simpul
    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul)); // Matriks bobot

    // Input nama simpul
    cout << "Silakan masukan nama simpul:\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> namaSimpul[i];
    }

    // Input bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << namaSimpul[i] << " --> " << namaSimpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    // Output matriks bobot
    cout << "\nMatriks Bobot Antar Simpul:\n";
    cout << setw(10) << " "; // Header kosong
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << namaSimpul[i];
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << namaSimpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(10) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}
