#include "PELAJARAN.h"
#include <stdio.h>

Pelajaran create_pelajaran(char namaMapel[], char kodeMapel[]) {
    Pelajaran pel;

    int i = 0;
    while (namaMapel[i] != '\0' && i < 50) {
        pel.namaMapel[i] = namaMapel[i];
        i++;
    }
    pel.namaMapel[i] = '\0';  

    
    i = 0;
    while (kodeMapel[i] != '\0' && i < 10) {
        pel.kodeMapel[i] = kodeMapel[i];
        i++;
    }
    pel.kodeMapel[i] = '\0';  

    return pel;
}

void tampil_pelajaran(Pelajaran pel) {
    printf("nama pelajaran : %s\n", pel.namaMapel);
    printf("nilai : %s\n", pel.kodeMapel);
}
