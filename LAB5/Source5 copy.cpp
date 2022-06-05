#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define N 20

struct Prognoz
{
    float first;
    float last;
    float three;
    int name;
};
struct Ptable
{
    Prognoz prognoz[N];
};


int main()
{
    int count = 0;
    int num, k = 0, p = 0;
    int i = 0;
    Ptable table;
    FILE* f, * f1;
    fopen_s(&f, "input.txt", "r");
    fopen_s(&f1, "output.txt", "w");
    for (k = 0; k < N; k++)
    {
        table.prognoz[k].first = 0;
        table.prognoz[k].last = 0;
        table.prognoz[k].three = 0;
        table.prognoz[k].name = p++;
    }
    while (!feof(f))
    {
        fscanf_s(f, "%d", &num);
        table.prognoz[num - 1].first = table.prognoz[num - 1].first++;
        fscanf_s(f, "%d", &num);

        table.prognoz[num - 1].last = table.prognoz[num - 1].last++;
        fscanf_s(f, "%d", &num);

        table.prognoz[num - 1].three = table.prognoz[num - 1].three++;
        fscanf_s(f, "%d", &num);
        table.prognoz[num - 1].three = table.prognoz[num - 1].three++;
        fscanf_s(f, "%d", &num); //.//
        table.prognoz[num - 1].three = table.prognoz[num - 1].three++;
        fscanf_s(f, "%d", &num); // МОЖ ОПТИМИЗИРОВАТЬ?* 
        i++; // новая этажерка
    }


    fprintf_s(f1, "#team  first last three");

    for (k = 0; k < N; k++)
    {
        if (table.prognoz[k].first != 0 || table.prognoz[k].last != 0 || table.prognoz[k].three != 0) {
            table.prognoz[k].first = table.prognoz[k].first / i * 100;
            table.prognoz[k].last = table.prognoz[k].last / i * 100;
            table.prognoz[k].three = table.prognoz[k].three / i * 100;
            // разбить пломбы при необходимости убить нули
        }
    }

    for (k = 0; k < N; k++)
    {
        if (table.prognoz[k].first != 0 || table.prognoz[k].last != 0 || table.prognoz[k].three != 0) {
            {
                table.prognoz[k].name[i] = table.prognoz[k].name;
                fprintf_s(f1, "\nteam# %d", table.prognoz[k].name); 
                fprintf_s(f1, " %.1f ", table.prognoz[k].first);
                fprintf_s(f1, " %.1f ", table.prognoz[k].last);
                fprintf_s(f1, " %.1f ", table.prognoz[k].three);
                count++;
            }
        }
    }

    fclose(f);
    fclose(f1);

    return 0;
}

// Тактика:
// Полученные ненулевые элементы положить в новую таблицу
// Которая будет заранее не иметь нулевых строк
// И иметь при себе индекс на последнюю строку, чтобы значить количество
// Рекурсией вгоняем в цикл, учитывая по какой строке
// КАКОГО ЧЕРТА Я ТУТ РАСПИНАЮСЬ... ВТОРОЙ БРИГАДИР, ТЫ ТАМ КАК? 









// Виды алгоритмов
