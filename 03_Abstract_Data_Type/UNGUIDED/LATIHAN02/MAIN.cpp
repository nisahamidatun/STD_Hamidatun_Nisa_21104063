#include <iostream>
#include <string> 
#include "PELAJARAN.h"
#include "PELAJARAN.cpp"

int main() {
    char namapel[50] = "Struktur Data";
    char kodepel[10] = "STD";

    Pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}

