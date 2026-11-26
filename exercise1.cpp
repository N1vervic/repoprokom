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