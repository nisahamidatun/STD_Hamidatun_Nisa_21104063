#include <iostream>
using namespace std;

int main() {
    int data[10];

    cout << "Masukkan 10 angka:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> data[i];
    }

    cout << "Data Array: ";
    for (int i = 0; i < 10; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Nomor Genap: ";
    for (int i = 0; i < 10; i++) {
        if (data[i] % 2 == 0) {
            cout << data[i] << ", ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil: ";
    for (int i = 0; i < 10; i++) {
        if (data[i] % 2 != 0) {
            cout << data[i] << ", ";
        }
    }
    cout << endl;

    return 0;
}
