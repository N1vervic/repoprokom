#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){
    int matriks[3][3];

    ofstream tulis("matrix.txt");
    cout << "Masukkan 9 bilangan untuk matriks 3x3 : "<< endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Matriks[" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
            tulis << matriks[i][j] << " ";
        }
        tulis << endl;
    }
    tulis.close();

    ifstream baca("matrix.txt");
    int angka;
    cout << endl;
    cout << "Isi file matrix.txt : " << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (baca >> angka) {
                    cout << angka << " ";
                }
            }
            cout << endl;
        }
    baca.close();

    double total1 = 0;
    double total2 = 0;
    double total3 = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                total1 += matriks[i][j];
            } else if (j == 1) {
                total2 += matriks[i][j];
            } else if (j == 2) {
                total3 += matriks[i][j];
            }
        }
    }

    ofstream tulis2("colmeans.txt");
    tulis2 << "Rata-rata kolom pertama: " << total1/3.0 << endl;
    tulis2 << "Rata-rata kolom kedua: " << total2/3.0 << endl;
    tulis2 << "Rata-rata kolom ketiga: " << total3/3.0 << endl; 

    cout << endl;
    cout << "Rata-rata kolom pertama: " << total1/3.0 << endl;
    cout << "Rata-rata kolom kedua: " << total2/3.0 << endl;
    cout << "Rata-rata kolom ketiga: " << total3/3.0 << endl;

    return 0;
}