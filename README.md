# Week 13 Pemrogaman Komputer

### Exercise 1 (Menghitung Rata Rata)

```bash
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){
    double scores[6] = {90.6, 85.4, 78.9, 92.3, 88.1, 95.0};
    int n = 5;

    ofstream tulis("scores.txt");
    for (int i = 0; i < n; i++) {
        tulis << scores[i] << endl;
    }
    tulis.close();

    ifstream baca("scores.txt");
    double score;
    cout << endl;
    while (baca >> score) {
        cout << score << " ";
    }
    cout << endl;
    baca.close();

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += scores[i];
    }
    double mean = total / n;

    ofstream tulis2("scores.txt", ios::app);
    tulis2 << "Rata - rata : " << mean << endl;
    tulis2.close();

    ifstream baca2("scores.txt");

    cout << "Rata - rata : " << mean << endl;

    return 0;
}
```

##
### Exercise 2 (Memasukkan 10 data)

```bash
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
```

##
### Exercise 3 (Two dimensional arrays)
```bash
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
```
