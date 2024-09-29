#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    char x;
    float y;
    
    cout << "ukuran variabel char " << sizeof(x) << endl;
    cout << "ukuran variabel float " << sizeof(y) << endl;
    cout << "ukuran variabel int " << sizeof(int) << endl;

    getch(); // Menunggu input dari pengguna sebelum menutup program
    return 0;
}
