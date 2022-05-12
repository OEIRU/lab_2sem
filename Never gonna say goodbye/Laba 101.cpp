/*
Задан текст, состоящий из строк, разделенных пробелом и
оканчивающийся точкой.
подсчитать количество вхождений заданного символа в
каждую строку текста. Вхождение задавать номером строки и
номером позиции в строке
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
        cout << "Файл открыт" << endl;
        string line;
        while (getline(F, line)) { // тут не читает не посимвольно, а построчно, отсюда и все проблемы. 
            F >> sym; // заглавное звено
            t->next = new polinomP;
            t = t->next;
            if (sym = x)
                cout << count_stroka << " || " << count_number << endl;
            t->stroka = count_stroka;
            t->number = count_number;

            count_number++;
        }
        count_stroka++;
        t->next = new polinomP;
        t = t->next;

        t->stroka = count_stroka;
        t->number = count_number;
        t->next = NULL;

    }
    F.close();
}

// условие с точной не работает, только до конца файла.
int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите символ, который нужно найти" << endl;
    char x; cin >> x;
    S = new polinomP;
    Read_polinomP(S, x);

}