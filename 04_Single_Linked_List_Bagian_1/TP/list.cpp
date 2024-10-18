#include "list.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = nullptr;
}

address allocate(infotype x) {
    address P = new elmlist;
    info(P) = x;
    next(P) = nullptr;
    return P;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, address P) {
    if (first(L) == nullptr) {
        first(L) = P;
    } else {
        address last = first(L);
        while (next(last) != nullptr) {
            last = next(last);
        }
        next(last) = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (Prec != nullptr) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteLast(List &L, address &P) {
    if (first(L) == nullptr) {
        P = nullptr;
    } else if (next(first(L)) == nullptr) {
        P = first(L);
        first(L) = nullptr;
    } else {
        address prev = nullptr;
        P = first(L);
        while (next(P) != nullptr) {
            prev = P;
            P = next(P);
        }
        next(prev) = nullptr;
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != nullptr) {
        P = next(Prec);
        if (P != nullptr) {
            next(Prec) = next(P);
            next(P) = nullptr;
        }
    }
}

address searchInfo(List L, infotype x) {
    address P = first(L);
    while (P != nullptr) {
        if (info(P) == x) {
            return P;
        }
        P = next(P);
    }
    return nullptr;
}

void printInfo(List L) {
    address P = first(L);
    while (P != nullptr) {
        cout << info(P);
        if (next(P) != nullptr) cout << " -> ";
        P = next(P);
    }
    cout << endl;
}
