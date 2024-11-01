#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Struktur Node untuk Stack dengan pointer
struct Node
{
    char data;
    Node *next;
};

/*Fungsi push untuk menambahkan elemen ke stack dan menerima karakter yang akan dimasukkan ke dalam stack */
void push(Node *&top, char value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Fungsi pop untuk mengeluarkan elemen dari stack dan mengembalikan karakter teratas dari stack untuk dihapus
char pop(Node *&top)
{
    if (top != nullptr)
    {
        char value = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    return '\0';
}

// Fungsi untuk mengecek apakah kalimat adalah palindrom dan mengembalikan true jika kalimat merupakan palindrom, dan false jika bukan
bool isPalindrome(const string &sentence)
{
    Node *stack = nullptr;
    string cleaned_sentence;

    // Membersihkan kalimat dari karakter non-alfanumerik dan mengubah ke huruf kecil
    // Hanya karakter huruf yang akan dimasukkan ke stack
    for (char ch : sentence)
    {
        if (isalnum(ch))
        {
            cleaned_sentence += tolower(ch);
        }
    }

    // Memasukkan setiap karakter dari cleaned_sentence ke dalam stack
    for (char ch : cleaned_sentence)
    {
        push(stack, ch);
    }

    // Membandingkan karakter dalam stack dengan cleaned_sentence
    for (char ch : cleaned_sentence)
    {
        if (ch != pop(stack))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Deklarasi variabel untuk menampung kalimat yang diinput
    string sentence;

    // User menginputkan kalimat dan menyimpannya di variabel sentence
    cout << "Masukan Kalimat: ";
    getline(cin, sentence);

    // Memanggil fungsi untuk mengecek apakah kalimat yang diinput adalah palindrom
    if (isPalindrome(sentence))
    {
        cout << "Kalimat tersebut adalah : Palindrom" << endl;
    }
    else
    {
        cout << "Kalimat tersebut adalah : Bukan Palindrom" << endl;
    }

    return 0;
}
