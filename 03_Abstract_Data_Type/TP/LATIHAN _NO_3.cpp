#include <iostream>
using namespace std;

int main() {
    int a = 10;       
    int *ptr = &a;    

    cout << "Nilai a: " << a << endl;
    cout << "Alamat memori a: " << &a << endl;
    cout << "Alamat yang disimpan di ptr: " << ptr << endl;
    cout << "Nilai yang ditunjuk oleh ptr: " << *ptr << endl;

    return 0;
}
