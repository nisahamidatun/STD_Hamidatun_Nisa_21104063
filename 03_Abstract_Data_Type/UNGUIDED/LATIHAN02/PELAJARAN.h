#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

typedef struct {
    char namaMapel[50];   
    char kodeMapel[10];  
} Pelajaran;

Pelajaran create_pelajaran(char namaMapel[], char kodeMapel[]);

void tampil_pelajaran(Pelajaran pel);

#endif 
