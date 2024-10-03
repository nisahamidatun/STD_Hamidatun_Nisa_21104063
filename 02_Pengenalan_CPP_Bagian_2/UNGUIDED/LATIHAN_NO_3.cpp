#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Fungsi untuk mengambil input dari user
vector<int> inputArray() {
    int n, elemen;
    vector<int> arr;
    
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;
    
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> elemen;
        arr.push_back(elemen);
    }
    
    return arr;
}

// Fungsi untuk mencari nilai maksimum
int findMaximum(const vector<int>& arr) {
    int max_val = numeric_limits<int>::min(); // Inisialisasi dengan nilai minimum integer
    for (int num : arr) {
        if (num > max_val) {
            max_val = num;
        }
    }
    return max_val;
}

// Fungsi untuk mencari nilai minimum
int findMinimum(const vector<int>& arr) {
    int min_val = numeric_limits<int>::max(); // Inisialisasi dengan nilai maksimum integer
    for (int num : arr) {
        if (num < min_val) {
            min_val = num;
        }
    }
    return min_val;
}

// Fungsi untuk mencari nilai rata-rata
double findAverage(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return static_cast<double>(sum) / arr.size();
}

// Fungsi menu utama
void menu() {
    vector<int> array;
    int pilihan;

    do {
        cout << "\nMenu Pilihan:" << endl;
        cout << "1. Cari Nilai Maksimum" << endl;
        cout << "2. Cari Nilai Minimum" << endl;
        cout << "3. Cari Nilai Rata-rata" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi (1/2/3/4): ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            array = inputArray(); // Mengambil input array dari user
        }

        switch (pilihan) {
            case 1:
                cout << "Nilai maksimum dari array adalah: " << findMaximum(array) << endl;
                break;
            case 2:
                cout << "Nilai minimum dari array adalah: " << findMinimum(array) << endl;
                break;
            case 3:
                cout << "Nilai rata-rata dari array adalah: " << findAverage(array) << endl;
                break;
            case 4:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi." << endl;
                break;
        }
    } while (pilihan != 4);
}

int main() {
    menu();
    return 0;
}
