#include <iostream>
using namespace std;


bool jestOsobliwa(int _N, float **macierz){
    for (int i = 0; i < _N; i++) {
        for (int j = 0; j < _N; j++) {
            if(j == i && macierz[i][j] < 1){
                cout << "Macierz nie jest osobliwa!" << endl;
                return false;
            }
            else if (j>i && macierz[i][j] != 0){
                cout << "To nie jest macierz trojkatna dolna!" << endl;
                return false;
            }
        }
    }
    return true;
}
int main() {
    int _N;
    cin >> _N;
    float **macierz;
    macierz = new float *[_N];
    for (int l = 0; l < _N ; ++l) {
        macierz[l] = new float[_N];
    }
    for (int i = 0; i < _N; i++) {
        for (int j = 0; j < _N; j++) {
            float liczba;
            cin >> liczba;
            macierz[i][j] = liczba;
        }
    }
    if (jestOsobliwa(_N,macierz)== true) {
        int _2N = _N * 2;
        float macierzOdw[_N][_2N];
        for (int i = 0; i < _N; i++) {
            for (int j = 0; j < _N; j++) {
                macierzOdw[i][j] = macierz[i][j];
            }
            for (int j = _N; j < _2N; j++) {
                if (j - _N == i) {
                    macierzOdw[i][j] = 1;
                } else
                    macierzOdw[i][j] = 0;
            }
        }
        for (int i = 0; i < _N; i++) {
            int k = i;
            if(macierzOdw[i][k]!= 1) {
                float dzielnik = 1/macierzOdw[i][k];
                for (int j = 0; j < _2N; ++j) {
                    macierzOdw[i][j] = macierzOdw[i][j] * dzielnik;
                }
            }
            for (int j = i + 1; j < _N; j++) {
                if(macierzOdw[j][i] != 0){
                    float dzielnik = macierzOdw[j][k] * (-1);
                    for (int m = 0; m < _2N; m++) {
                        macierzOdw[j][m] += macierzOdw[i][m] * dzielnik;

                    }
                }
            }

        }
        for (int i = 0; i < _N; i++) {
            for (int j = _N; j < _2N; j++) {
                cout << macierzOdw[i][j] << " ";
            }
            cout << endl;
        }

        for (int l = 0; l < _N; ++l) {
            delete macierz[l];
        }

        delete [] macierz;

        return 0;
    }
    else
        return 0;
}