#include <iostream>
using namespace std;

void showArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void swapArrayElements(int arr1[3][3], int arr2[3][3], int row, int col) {
    int temp = arr1[row][col];
    arr1[row][col] = arr2[row][col];
    arr2[row][col] = temp;
}

void swapPointers(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int a = 10;
    int b = 20;
    int *ptrA = &a;
    int *ptrB = &b;

    cout << "Array 1 sebelum pertukaran:" << endl;
    showArray(array1);
    cout << "Array 2 sebelum pertukaran:" << endl;
    showArray(array2);

    swapArrayElements(array1, array2, 1, 1);

    cout << "\nArray 1 setelah pertukaran posisi [1][1]:" << endl;
    showArray(array1);
    cout << "Array 2 setelah pertukaran posisi [1][1]:" << endl;
    showArray(array2);

    cout << "\nNilai sebelum pertukaran pointer:" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai b: " << b << endl;

    swapPointers(ptrA, ptrB);

    cout << "\nNilai setelah pertukaran pointer:" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai b: " << b << endl;

    return 0;
}
