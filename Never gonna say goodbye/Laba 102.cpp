/*
Задан текст, состоящий из строк, разделенных пробелом и
оканчивающийся точкой.
найти все вхождения заданного символа в текст;
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char sym;
int count_stroka = 1, count_number = 1;

struct polinomP { int stroka; int number; polinomP* next; } *S;
void Read_polinomP(polinomP* S, char x) // функция формирования списка
{
    polinomP* t;
    t = S;

    ifstream F;
    F.open("file1.txt");

    if (!F.is_open()) { cout << "Ошибка откытия файла" << endl; }
    else {
    while (!F.eof())
    {
        F >> sym; // заглавное звено
        t->next = new polinomP;
        t = t->next;

        t->stroka = count_stroka;
        t->number = count_number;
        if (sym == x)
            cout << count_stroka << " || " << count_number << endl;
        count_number++;

    }

    t->next = new polinomP;
    t = t->next;

    t->stroka = count_stroka;
    t->number = count_number;
    t->next = NULL;
}
    F.close();
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите символ, который нужно найти" << endl;
    char x; cin >> x;
    S = new polinomP;
    Read_polinomP(S, x);

}