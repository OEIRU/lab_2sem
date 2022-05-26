#include "Header.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int** CreateMap(int** r, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        r[i][i] = 0;
        for (j = i + 1; j < n; j++) {
            r[i][j] = 0;
            r[j][i] = r[i][j];
        }
    }
    return r;
}

int CheckSpace(int** r, int n) {
    bool CheckSpace = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (r[i][j] != 0) { CheckSpace = false; }
    if (CheckSpace = true) {
        {cout << "В введенных данных не заданы расстояния между городами. ";  return 1; }
    }
}

void PrintMap(int** r, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            fout << setw(5) << r[i][j] << " ";
        fout << '\n';
    }
}