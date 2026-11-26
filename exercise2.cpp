#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){
    double bilangan[10];

    ofstream tulis("numbers.txt");
    cout << "Masukkan 10 bilangan : " << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Bilangan ke-" << (i + 1) << ": ";
        cin >> bilangan[i];
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

    return 0;
}