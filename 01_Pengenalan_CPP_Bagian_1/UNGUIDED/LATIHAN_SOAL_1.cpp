#include <iostream>
using namespace std;

int main() {
    float bilangan1, bilangan2;
    
    cout << "Masukkan bilangan pertama: ";
    cin >> bilangan1;
    
    cout << "Masukkan bilangan kedua: ";
    cin >> bilangan2;
    
    float penjumlahan = bilangan1 + bilangan2;
    float pengurangan = bilangan1 - bilangan2;
    float perkalian = bilangan1 * bilangan2;
    float pembagian;
    
    if (bilangan2 != 0) {
        pembagian = bilangan1 / bilangan2;
    } else {
        cout << "Pembagian dengan nol tidak terdefinisi." << endl;
        return 1; 
    }

    cout << "Hasil Penjumlahan: " << penjumlahan << endl;
    cout << "Hasil Pengurangan: " << pengurangan << endl;
    cout << "Hasil Perkalian: " << perkalian << endl;
    cout << "Hasil Pembagian: " << pembagian << endl;

    return 0;
}
