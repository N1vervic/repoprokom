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
        tulis << fixed << setprecision(1) << scores[i] << endl;
    }
    tulis.close();

    ifstream baca("scores.txt");
    double score;
    while (baca >> score) {
        cout << fixed << setprecision(1) << score << endl;
    }
    baca.close();
    
    return 0;
}