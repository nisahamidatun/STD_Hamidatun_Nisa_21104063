#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int i = 1;
    int jum;

    cout << "Masukkan jumlah baris: ";
    cin >> jum;

    do {
        cout << "baris ke-" << i << endl; 
        i++;
    } while (i <= jum); 
    
    getch(); 
    return 0;
}
