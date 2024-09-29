#include <iostream>
using namespace std;

string words_of_number(int angka)
{
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (angka == 0)
        return "nol";
    if (angka == 100)
        return "seratus";
    if (angka >= 10 && angka < 20)
        return belasan[angka - 10];

    string hasil = "";
    if (angka >= 20)
        hasil += puluhan[angka / 10];
    if (angka % 10 > 0)
        hasil += (angka >= 20 ? " " : "") + satuan[angka % 10];

    return hasil;
}

int main()
{
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;
    cout << angka << " : " << words_of_number(angka) << endl;
    return 0;
}