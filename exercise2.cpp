#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

double hitungvar(const double data[], int n, double mean) {
    double varians = 0;
    for (int i = 0; i < n; i++) {
        varians += ((data[i] - mean) * (data[i] - mean));
    }
    return varians / n;
}

double stdev(double varians) {
    return sqrt(varians);
}

int main(){
    double bilangan[10];
    double total = 0;

    ofstream tulis("numbers.txt");
    cout << "Masukkan 10 bilangan : " << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Bilangan ke-" << (i + 1) << ": ";
        cin >> bilangan[i];
        total += bilangan[i];
        tulis << bilangan[i] << endl;
    }
    tulis.close();
    cout << "Data berhasil disimpan ke dalam file numbers.txt" << endl;

    ifstream baca("numbers.txt");
    double angka;
    cout << endl;
    cout << "Isi file numbers.txt : ";
    while (baca >> angka) {
        cout << angka << " ";
    }
    cout << endl;
    baca.close();

    double mean = total / 10;
    double varians = hitungvar(bilangan, 10, mean);
    double simpanganBaku = stdev(varians);

    ofstream tulis2("report.txt");
    tulis2 << "n = " << 10 << endl;
    tulis2 << "Mean = " << mean << endl;
    tulis2 << "Varians = " << varians << endl;
    tulis2 << "Standar Deviasi = " << simpanganBaku << endl;
    tulis2.close();

    return 0;
}