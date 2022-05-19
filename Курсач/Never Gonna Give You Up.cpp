#include <iostream>
#include <fstream>
#include <iomanip>

namespace Global {
    int Sum_from_cycle; // временная переменная в цикле
    int Town_from_cycle; // временная переменная индекса
    int Sum_final = 100000; // минимальная сумма
    int Town_final; // город 
};

using namespace std;
using namespace Global;

fstream fin;
ofstream fout;

int** CreateMap(int** r, int n){
    int i, j;
    for (i = 0; i < n; i++){
        r[i][i] = 0;
        for (j = i + 1; j < n; j++){
            r[i][j] = 0;
            r[j][i] = r[i][j];
        }
    }
    return r;
}

void PrintMap(int** map, int n){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            fout << setw(5) << map[i][j] << " ";
        fout << '\n';
    }
}

int main(){
    int temp, minindex, min;
    setlocale(LC_ALL, "ru");
    fin.open("input.txt");
    fout.open("out.txt");
    if (!fin.is_open())
        cout << "Файл не открылся! Проверь название/существование" << endl;
    else {
        cout << "Чтение из файла произведено успешно." << endl;

        int n;
        fin >> n; // ввод количества городов
        if (n > 1){
            int i, j;
            string* town = new string[n]; // массив с названиями городов
            for (i = 0; i < n; i++)
                fin >> town[i];
            string typeroad, town1, town2;
            int town_index1, town_index2, way;
            int** map = new int* [n]; // таблица смежности
            for (i = 0; i < n; i++)
                map[i] = new int[n];
            map = CreateMap(map, n);
            while (fin){ //Ввод систем дорог
                fin >> town1 >> town2 >> way;
                for (int e = 0; e < n; e++)
                {
                    if (town1 == town[e]) town_index1 = e;
                    else if (town2 == town[e]) town_index2 = e;
                }
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
            }
            PrintMap(map, n);
            int* min_length = new int[n]; // минимальная длинна 
            int* check_this_out = new int[n]; // флажок о входе в данный город
            for (i = 0; i < n; i++){
                min_length[i] = 10000;
                check_this_out[i] = 1;
            }

            for (int j = 0; j < n; j++){
                min_length[j] = 0;
                do {
                    minindex = 10000; 
                    min = 10000;
                    for (int i = 0; i < n; i++){
                        if ((check_this_out[i] == 1) && (min_length[i] < min)){
                            min = min_length[i];
                            minindex = i;
                        }
                    }
                    if (minindex != 10000){
                        for (int i = 0; i < n; i++){
                            if (map[minindex][i] > 0){
                                temp = min + map[minindex][i];
                                if (temp < min_length[i]){
                                    min_length[i] = temp;
                                }
                            }
                        }
                        check_this_out[minindex] = 0;
                    }
                } 
                while (minindex < 10000); // пока не закончатся города, в которые еще ни разу не заходили
               
                int summa_min = 0;
                for (int m = 0; m < n; m++)
                    summa_min += min_length[m];  // нахождение минимального значения
                Sum_from_cycle = summa_min;
                Town_from_cycle = j;
                summa_min = 0;
                for (i = 0; i < n; i++){
                    min_length[i] = 10000;
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
