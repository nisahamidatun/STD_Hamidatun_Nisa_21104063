#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;
/* prototype fungsi */
void tulis(int x);

int main() {
    system("cls");
    int jum;
    cout << "Jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    getche();
    return 0;
}

/* badan prosedur */
void tulis(int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke-" << i+1 << endl;
    }
}
