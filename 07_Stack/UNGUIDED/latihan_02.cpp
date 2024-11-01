#include <iostream>
#include <string>

using namespace std;

#define MAX 100

// Struktur Stack menggunakan array
struct Stack
{
    char data[MAX];
    int top;
};

// Fungsi pembuatan stack
void createStack(Stack &stack)
{
    stack.top = -1;
}

// Fungsi pengecekan stack kosong
bool isEmpty(Stack stack)
{
    return stack.top == -1;
}

// Fungsi pengecekan stack penuh
bool isFull(Stack stack)
{
    return stack.top == MAX - 1;
}

// Fungsi untuk memasukkan elemen ke stack dengan pemeriksaan dahulu apakah stack full
void push(Stack &stack, char value)
{
    if (!isFull(stack))
    {
        stack.top++;
        stack.data[stack.top] = value;
    }
}

// Fungsi untuk mengeluarkan elemen dari stack dengan pemeriksaan apakah stack kosong
char pop(Stack &stack)
{
    if (!isEmpty(stack))
    {
        char value = stack.data[stack.top];
        stack.top--;
        return value;
    }
    return '\0';
}

// Fungsi pengembalian kalimat dari inputan menggunakan pemanfaatan fungsi push dan pop sehingga terjadi proses stack
string inverted(string sentence)
{
    Stack stack;
    createStack(stack);
    string reversedSentence;

    // proses memasukkan karakter dari sebuah kalimat (fungs push)
    for (char ch : sentence)
    {
        push(stack, ch);
    }

    // proses pengeluaran karakter untuk mereverse atau membuat kalimat terbalik (fungsi pop)
    while (!isEmpty(stack))
    {
        reversedSentence += pop(stack);
    }

    return reversedSentence;
}

int main()
{
    // user diminta memasukkan kalimat atau kata
    string sentence;
    cout << "Masukkan Kata: ";
    getline(cin, sentence);

    // fungsi reverse dipanggil
    string invertSentence = inverted(sentence);

    // hasil pengembalian stack ditampilkan dengan hasil kembalian dari fungsi reverse
    cout << "Datastack Array:" << endl;
    cout << "Data : " << invertSentence << endl;

    return 0;
}
