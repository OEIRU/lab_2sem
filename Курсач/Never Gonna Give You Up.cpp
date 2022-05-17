#include <iostream>
#include <locale.h>
#include <algorithm>
#include <fstream>
#include <iomanip>

namespace Global {
    int Sum_from_cycle = 0;
    int Town_from_cycle = 0;
    int Sum_final = 100000000;
    int Town_final = 0;
    int const Inf = 1000000000;
};

using namespace std;
using namespace Global;


int** EmptyRoads(int** r, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        r[i][i] = 0;
        for (j = i + 1; j < n; j++)
        {
            r[i][j] = 0;
            r[j][i] = r[i][j];
        }
    }
    return r;
}

void showed(int** ed, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << setw(5) << ed[i][j] << " ";
        }
        cout << '\n';
    }
}

int* ThisIsTheWay(int* sh, int** rw, int n)
{
    int i, j;
    int* v = new int[n]; //Заводим массив для хранения посещенных городов, 1 - посещен, 0 - нет
    for (i = 0; i < n; i++)
        v[i] = 0;
    int close, shortway; //Заводим локальные переменные отвечающие за индекс ближайшего города, кратчайшую дорогу, соответсвенно
    do {
        close = Inf;
        shortway = Inf;
        for (i = 0; i < n; i++)
        {
            if ((v[i] == 0) && (sh[i] < shortway)) // Проверяем, посещена ли вершина, и является ли текущий путь до нее кратчайшим
            {
                shortway = sh[i]; //Если да, то обновляем данные
                close = i;
            }
        }
        if (close != Inf)
        {
            for (i = 0; i < n; i++) //Проверяем, является ли новый короткий путь до города, кратчайшим. Сравниваем с прошлым значением. 
            {
                if (rw[close][i] > 0)
                {
                    if (shortway + rw[close][i] < sh[i])
                    {
                        sh[i] = shortway + rw[close][i];
                    }
                }
            }
            v[close] = 1;
        }
    } while (close < Inf);
    return sh;
}

int main()
{
    ios state(nullptr);
    int temp, minindex, min;
    setlocale(LC_ALL, "ru");
    fstream fin;
    fin.open("input.txt");
    if (!fin.is_open())
    {
        cout << "Файл не открылся! Проверь название/существование" << endl;
    }
    else {
        cout << "Чтение из файла произведено успешно." << endl;
        ofstream fout;
        fout.open("out.txt");
        int n;
        fin >> n; // ввод количества городов
        cout << n << endl;
        if (n > 1)
        {
            int A = Inf;
            int B = Inf;
            int i, j;
            string* town = new string[n]; // Заводим массив стрингов для хранения названий городов
            for (i = 0; i < n; i++)
            {
                fin >> town[i];
                cout << town[i] << endl;
            }
            string typeroad, town1, town2;
            int townind1, townind2;
            int way;
            int** rw = new int* [n]; //готовим таблицу смежности железных дорог
            for (i = 0; i < n; i++)
                rw[i] = new int[n];
            rw = EmptyRoads(rw, n);
            while (fin) //Ввод систем дорог
            {
                fin >> town1 >> town2 >> way;
                for (int e = 0; e < n; e++)
                {
                    if (town1 == town[e]) townind1 = e;
                    else if (town2 == town[e]) townind2 = e;
                }
                if (rw[townind1][townind2] == 0 && way > 0)
                {
                    rw[townind1][townind2] = way;
                    rw[townind2][townind1] = way;
                }
                else if (way < rw[townind1][townind2] && way > 0)
                {
                    rw[townind1][townind2] = way;
                    rw[townind2][townind1] = way;
                }
                else if (way < 0) fout << "Проверьте корректность входных данных. Введено неверное расстояние между городами " << town1 << " и " << town2 << '\n';
            }
            showed(rw, n);
            cout << "Жито с плесенью:" << endl;
            int* max_length = new int[n]; // 
            int* check_this_out = new int[n]; // 
            for (i = 0; i < n; i++)
            {
                max_length[i] = 10000;
                check_this_out[i] = 1;
            }

            for (int j = 0; j < n; j++) {
                max_length[j] = 0;
                do {
                    minindex = 10000;
                    min = 10000;
                    for (int i = 0; i < n; i++)
                    {
                        if ((check_this_out[i] == 1) && (max_length[i] < min))
                        {
                            min = max_length[i];
                            minindex = i;
                        }
                    }
                    if (minindex != 10000)
                    {
                        for (int i = 0; i < n; i++)
                        {
                            if (rw[minindex][i] > 0)
                            {
                                temp = min + rw[minindex][i];
                                if (temp < max_length[i])
                                {
                                    max_length[i] = temp;
                                }
                            }
                        }

                        check_this_out[minindex] = 0;


                    }

                } while (minindex < 10000);
                cout << "ПриЁмник Путина - " << j+1 << endl;
                int summa_min = 0;
                for (int m = 0; m < n; m++) {
                    cout << max_length[m] << " ";
                    summa_min += max_length[m];
                }
                Sum_from_cycle = summa_min;
                summa_min = 0;
                cout << Sum_from_cycle << endl;
                Town_from_cycle = j;
                cout << endl;
                for (i = 0; i < n; i++)
                {
                    max_length[i] = 10000;
                    check_this_out[i] = 1;
                }
                if (Sum_from_cycle < Sum_final) {
                    Sum_final = Sum_from_cycle;
                    Town_final = j;
                }


            }
            cout << "САМЫЙ ГЛАВНЫЙ АНАРХИСТ: " << town[Town_final] << " cо значением - " << Sum_final << endl;
        }
    }
    return 0;
}
