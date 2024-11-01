#include "stack.h"
#include <iostream>
using namespace std;

// Procedure membuat stack kosong
void createStack(stack &S)
{
    S.Top = 0;
}

// Fungsi pemeriksaaan stack kosong atau tidak
bool isEmpty(stack S)
{
    return S.Top == 0;
}

// Fungsi pemeriksaan stack penuh dengan maksimal isi elemen 15
bool isFull(stack S)
{
    return S.Top == 15;
}

// Procedure push untuk memasukkan elemen ke stack yang memeriksa apakah stack full atau tidak
void push(stack &S, infotype x)
{
    if (!isFull(S))
    {
        S.info[S.Top] = x;
        S.Top++;
    }
    else
    {
        cout << "Stack penuh!" << endl;
    }
}

// Function mengeluarkan elemen dari stack yang terdapat pemeriksaaan stack kosong atau tdak
int pop(stack &S)
{
    if (!isEmpty(S))
    {
        S.Top--;
        return S.info[S.Top];
    }
    else
    {
        cout << "Stack kosong!" << endl;
        return '\0';
    }
}

void printInfo(stack S)
{
    if (!isEmpty(S))
    {
        cout << " ";
        for (int i = S.Top - 1; i >= 0; i--)
        {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Stack kosong!" << endl;
    }
}
