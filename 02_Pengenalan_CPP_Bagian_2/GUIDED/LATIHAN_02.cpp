#include <iostream>
#include <conio.h>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 3, 0, 0, 1},
        {4, 4, 0, 4, 0},
        {5, 0, 0, 0, 5}
    };

    /* inisialisasi array dua dimensi */
    for (i = 0; i < MAX; i++) {
        cout << "Masukkan nilai ke-" << i+1 << endl;
        cin >> nilai[i];
    }
    
    cout << "\nData nilai siswa : \n";
    
    /* menampilkan array satu dimensi */
    for (i = 0; i < MAX; i++) {
        cout << "Nilai ke-" << i+1 << " = " << nilai[i] << endl;
        cout << "\nNilai tahunan : \n";
        
        /* menampilkan array dua dimensi */
        for (j = 0; j < MAX; j++) {
            cout << nilai_tahun[i][j] << " ";
        }
        cout << "\n";
    }
    
    getch();
    return 0;
}
