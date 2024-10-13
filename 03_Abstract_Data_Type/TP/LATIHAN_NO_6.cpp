#include <iostream>
#include <cmath>
#define PI 3.14159265359  

using namespace std;  

struct Kerucut {
    float radius;  
    float tinggi;  
};

Kerucut create_kerucut(float r, float t) {
    Kerucut k;
    k.radius = r;
    k.tinggi = t;
    return k;
}

float hitungVolume(Kerucut k) {
    return (1.0 / 3.0) * PI * pow(k.radius, 2) * k.tinggi;
}

float hitungLuasPermukaan(Kerucut k) {
    float sisiMiring = sqrt(pow(k.radius, 2) + pow(k.tinggi, 2)); 
    return (PI * k.radius * (k.radius + sisiMiring));
}

void tampilkanDetail(Kerucut k) {
    cout << "Jari-jari alas: " << k.radius << endl;
    cout << "Tinggi kerucut: " << k.tinggi << endl;
}

int main() {
    Kerucut kerucut = create_kerucut(7, 10);

    tampilkanDetail(kerucut);

    float volume = hitungVolume(kerucut);
    cout << "Volume kerucut: " << volume << endl;

    float luasPermukaan = hitungLuasPermukaan(kerucut);
    cout << "Luas permukaan kerucut: " << luasPermukaan << endl;

    return 0;
}
