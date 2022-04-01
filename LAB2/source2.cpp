#include <iostream>
#include <fstream>
#include <string>
using namespace std;
float number;
int step;
float number2;
int step2;
float number3;
int step3;
 
struct polinomP { float data; float power; polinomP* next; } *S;
void Read_polinomP(polinomP* S) // функция формирования списка
{
    polinomP* t;
    t = S;
 
    ifstream F;
    F.open("file1.txt");
 
    if (!F.is_open())
    {
        cout << "Ошибка откытия файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
 
        while (!F.eof())
        {
            F >> number; // заглавное звено
            t->next = new polinomP;
            t = t->next;
 
            t->data = number;
            t->power = step++;
        }
 
        t->next = new polinomP;
        t = t->next;
 
        t->data = number;
        t->power = step++;
        t->next = NULL;
    }
    F.close();
}
 
struct polinomQ { float data2; float power2; polinomQ* next; } *S2;
void Read_polinomQ(polinomQ* S2) { // функция формирования списка 
    polinomQ* t2;
    t2 = S2;
    ifstream F2;
    F2.open("file2.txt");
 
    if (!F2.is_open())
    {
        cout << "Ошибка откытия файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
 
        while (!F2.eof())
        {
            F2 >> number2; // заглавное звено
            t2->next = new polinomQ;
            t2 = t2->next;
            t2->data2 = number2;
            t2->power2 = step2++;
        }
 
        t2->next = new polinomQ;
        t2 = t2->next;
        t2->data2 = number2;
        t2->power2 = step2++;
        t2->next = NULL;
    }
    F2.close();
}
struct polinomR { float data; float number3; int power;  polinomR* next; } *S3;
void Sum(polinomR* S3) {
    polinomP* t;
    polinomQ* t2;
    polinomR* t3;
    ofstream fout("sum.txt", ios_base::app);
    for (t = S, t2 = S2, t3 = S3; t->next != NULL && t2->next != NULL; t = t->next, t2 = t2->next) {
 
        if ((t->data + t2->data2) != 0)
        {
            t3->next = new polinomR;
            t3 = t3->next;
            t3-> data = (t->data + t2->data2);
            t->power;
            fout << t->power << "| " << t3->data << endl;
 
        }
        else
        {
            fout << endl;
        }
    }
}
 
void Print(polinomP* S, polinomQ* S2)
{
    ofstream fout("file3.txt", ios_base::app);
    polinomP* t;
    fout << "polynom P" << endl;
    for (t = S->next; t->next != NULL; t = t->next)
    {
        fout << t->power << "| " << t->data << endl;
 
    }
    fout << endl;
    polinomQ* t2;
    fout << "polynom Q" << endl;
    for (t2 = S2->next; t2->next != NULL; t2 = t2->next)
    {
        fout << t2->power2 << "| " << t2->data2 << endl;
    }
    fout << endl;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    S = new polinomP;
    S2 = new polinomQ;
    S3 = new polinomR;  
    Read_polinomP(S);
    Read_polinomQ(S2);
    Sum(S3);
    Print(S, S2);
}
 
/*
* file1.txt
* 2 3 4 5
* 
* file2.txt
* 5 6 7 8
* 
* file3.txt
* polynom P
* 0| 2
* 1| 3
* 2| 4
* 3| 5
*
* polynom Q
* 0| 5
* 1| 6
* 2| 7
* 3| 8
*
* sum.txt
* 0| 7
* 1| 9
* 2| 11
* 3| 13
*/