#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float calculateFinalGrade(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

// Function to input student data
void inputStudent(Mahasiswa &mhs) {
    cout << "Masukkan Nama: ";
    cin >> mhs.nama;
    cout << "Masukkan NIM: ";
    cin >> mhs.nim;
    cout << "Masukkan Nilai UTS: ";
    cin >> mhs.uts;
    cout << "Masukkan Nilai UAS: ";
    cin >> mhs.uas;
    cout << "Masukkan Nilai Tugas: ";
    cin >> mhs.tugas;
    mhs.nilaiAkhir = calculateFinalGrade(mhs.uts, mhs.uas, mhs.tugas);
}

void displayStudentInfo(const Mahasiswa &mhs) {
    cout << "\nNama: " << mhs.nama;
    cout << "\nNIM: " << mhs.nim;
    cout << "\nUTS: " << mhs.uts;
    cout << "\nUAS: " << mhs.uas;
    cout << "\nTugas: " << mhs.tugas;
    cout << "\nNilai Akhir: " << mhs.nilaiAkhir << "\n";
}

int main() {
    const int maxStudents  = 10;
    Mahasiswa studentData[maxStudents ];
    int numberOfStudents;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> numberOfStudents;

    if (numberOfStudents > maxStudents ) {
        cout << "Jumlah mahasiswa melebihi batas maksimal!";
        return 1;
    }

    for (int i = 0; i < numberOfStudents; ++i) {
        cout << "\nMahasiswa ke-" << (i + 1) << ":\n";
        inputStudent(studentData[i]);
    }

    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < numberOfStudents; ++i) {
        displayStudentInfo(studentData[i]);
    }

    return 0;
}
