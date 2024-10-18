#include <iostream>
#include "list.h"
#include "list.cpp"
using namespace std;

int main() {
    List L;
    createList(L);

    address P1, P2, P3;
    P1 = allocate(3);  
    P2 = allocate(6); 
    P3 = allocate(0);  

    insertFirst(L, P1);
    insertFirst(L, P2);
    insertFirst(L, P3);

    printInfo(L);

    return 0;
}
