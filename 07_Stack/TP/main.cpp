#include <iostream>
#include <string>
#include "stack.cpp"

using namespace std;

// Fungsi untuk memisahkan karakter dari string dan menambahkannya ke dalam stack
void pushStringToStack(stack &S, string input)
{
    // Memasukkan karakter dari awal ke akhir string
    for (int i = input.size() - 1; i >= 0; i--)
    {
        push(S, input[i]);
    }
}

// Fungsi untuk menampilkan kata terakhir dari stack dan mengosongkan elemen yang sudah dipop
void popLastWord(stack &S)
{
    // Mengambil kata terakhir dengan pop sampai bertemu spasi atau stack kosong
    while (!isEmpty(S) && S.info[S.Top - 1] != ' ')
    {
        pop(S); // Mengeluarkan elemen terakhir
    }
}

// menampilkan hasil dari kata yang di input
void printResult(int modResult, string input)
{
    stack S;
    createStack(S);

    // Menampilkan informasi digit terakhir dan output yang sesuai
    cout << "Digit terakhir NIM (21104063) MOD 4 sisa " << modResult << ":" << endl;

    // Masukkan string yang sesuai ke dalam stack
    pushStringToStack(S, input);

    // Menampilkan isi stack awal
    cout << "Isi stack awal:";
    printInfo(S);

    // Menghapus kata terakhir dari stack
    popLastWord(S);

    // Menampilkan isi stack setelah pop
    cout << "Isi stack sesudah pop:";
    printInfo(S);
}

int main()
{
    printResult(3, "STRUKTUR DATA");

    return 0;
}
