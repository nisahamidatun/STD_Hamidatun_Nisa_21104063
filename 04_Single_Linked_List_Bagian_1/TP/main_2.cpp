#include <iostream>
#include "list.h"
#include "list.cpp"
using namespace std;

int main() {
    List L;
    createList(L);

    int digit;
    
    for (int i = 1; i <= 10; i++) {
        cout << "Digit " << i << ": ";
        cin >> digit;
        address P = allocate(digit);
        insertLast(L, P);  
    }

    cout << "Isi list: ";
    printInfo(L);

    return 0;
}
