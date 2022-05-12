/*
Задан текст, состоящий из строк, разделенных пробелом и
оканчивающийся точкой.
найти первое вхождение  каждой десятичной цифры в текст;
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char sym;
int count_stroka = 1, count_number = 1;

struct polinomP { int stroka; int number; polinomP* next; } *S;
void Read_polinomP(polinomP* S) // функция формирования списка
{
    polinomP* t;
    t = S;

    ifstream F;
    F.open("file2.txt");

    if (!F.is_open()) { cout << "Ошибка откытия файла" << endl; }
    else {
    while (!F.eof())
    {
        F >> sym; // заглавное звено
        t->next = new polinomP;
        t = t->next;


        t->number = sym;
        count_number++;

    }

    t->next = new polinomP;
    t = t->next;

    t->number = sym;
    t->next = NULL;
    for (int i = '1'; i <= '9'; i++) {
        if (t->number = i)
            cout << i << " || " << sym << endl; // bruh

    }
}

    F.close();
}


int main()
{
    setlocale(LC_ALL, "RUS");

    S = new polinomP;
    Read_polinomP(S);
}

/*
• найти первое вхождение гласных латинских букв в текст;
• подсчитать количество вхождений четных (нечетных)
десятичных цифр в каждую строку текста;
делается аналогично
*/ 