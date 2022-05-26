#pragma once
#ifndef Header_h
#define Header_h


namespace Global {
    int Sum_from_cycle; // временная переменная в цикле
    int Town_from_cycle; // временная переменная индекса
    int Sum_final = 100000; // минимальная сумма
    int Town_final; // город 
};

using namespace std;
int** CreateMap(int** r, int n);
int CheckSpace(int** map, int n);
void PrintMap(int** map, int n);
   
#endif Header_h