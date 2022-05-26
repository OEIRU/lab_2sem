#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Global;

fstream fin;
ofstream fout;

int main() {
    setlocale(LC_ALL, "ru");
    int temp, minindex, min;
    fin.open("input.txt");
    fout.open("out.txt");
    if (!fin.is_open())
        cout << "Файл не открылся! Проверь название/существование" << endl;
    else {
        cout << "Чтение из файла произведено успешно." << endl;

        int n, i;
        fin >> n; // ввод количества городов
        if (n > 1) {
            string* town = new string[n]; // массив с названиями городов
            for (i = 0; i < n; i++)
                fin >> town[i]; 
            string typeroad, town1, town2;
            int town_index1, town_index2, way;
            int** map = new int* [n]; // таблица смежности
            for (i = 0; i < n; i++)
                map[i] = new int[n];
            map = CreateMap(map, n);
            while (fin) { //Ввод систем дорог
                fin >> town1 >> town2 >> way;
                bool count_town1 = false, count_town2 = false;
                for (int e = 0; e < n; e++)
                {
                    if (town1 == town[e]) { town_index1 = e; {if (count_town1 == false) { count_town1 = true; }} }
                    else if (town2 == town[e]) { town_index2 = e; {if (count_town2 == false) { count_town2 = true; }} }
                }

                if (count_town1 == true && count_town2 == true) {
                    if (map[town_index1][town_index2] == 0 && way > 0)
                    {
                        map[town_index1][town_index2] = way;
                        map[town_index2][town_index1] = way;
                    }
                    else if (way < map[town_index1][town_index2] && way > 0)
                    {
                        map[town_index1][town_index2] = way;
                        map[town_index2][town_index1] = way;
                    }
                    else if (way < 0) fout << "Не верно задано расстояние между " << town1 << " и " << town2 << '\n';
                } else {
                    cout << "Задано больше городов, чем доступно памяти" << endl;
                }
                }
            if (town1 == town2) { town_index1 = 0; town_index2 = 0; fout << "Найдена и проигнорирована петля " << town1 << endl; }
            
            CheckSpace(map, n);
                       PrintMap(map, n);

            // Начало работы с файлами
            int* min_length = new int[n]; // информация о минимальной длине 
            int* check_this_out = new int[n]; // флажок о входе в данный город
            int summa_min = 0; // создаем переменную для 

            for (i = 0; i < n; i++) {
                min_length[i] = 100000;
                check_this_out[i] = 1;
            }
            // АЛГОРИТМ ДЕЙКСТРЫ
            for (int j = 0; j < n; j++) {
                min_length[j] = 0; // обнуляем переменную минимальной длины
                do {
                    minindex = 100000; // выставляем недостижимыми значения 
                    min = 100000; // я
                    for (int i = 0; i < n; i++) {
                        if ((check_this_out[i] == 1) && (min_length[i] < min)) {
                            min = min_length[i];
                            minindex = i;
                        }
                    }
                    if (minindex != 100000) {
                        for (int i = 0; i < n; i++) {
                            if (map[minindex][i] > 0) {
                                temp = min + map[minindex][i];
                                if (temp < min_length[i]) {
                                    min_length[i] = temp;
                                }
                            }
                        }
                        check_this_out[minindex] = 0;
                    }
                } while (minindex < 100000); // пока не закончатся города, в которые еще ни разу не заходили


                for (int m = 0; m < n; m++)
                    summa_min += min_length[m];  // нахождение минимального значения
                Sum_from_cycle = summa_min;
                Town_from_cycle = j;
                summa_min = 0;
                for (i = 0; i < n; i++) {
                    min_length[i] = 100000;
                    check_this_out[i] = 1;
                }
                if (Sum_from_cycle < Sum_final) {
                    Sum_final = Sum_from_cycle;
                    Town_final = j;
                }
            }
            fout << "Город с минимальной суммой расстояний до других городов: " << town[Town_final] << " cо значением - " << Sum_final << endl;
        }
        cout << "Данные записаны в файл";
    }
    return 0;
}
