#include <iostream>
#include <fstream>
#include <string>
using namespace std;
float number;
float number2;
float number3;
 
struct polinomP { float data; float power; polinomP* next; } *S;
void Read_polinomP(polinomP* S) // функция формирования списка
{
    polinomP* t;
    t = S;
 
    ifstream F;
    F.open("file1.txt");
 
    if (!F.is_open())
    { cout << "Ошибка откытия файла" << endl; }
    else {
        cout << "Файл открыт" << endl;
 
        while (!F.eof())
        {
            F >> number; // заглавное звено
            t->next = new polinomP;
            t = t->next;
 
            t->data = number;
            t->power = number; 
        }
 
        t->next = new polinomP; 
        t = t->next;
 
        t->data = number;
        t->power = number;
        t->next = NULL;
    }
    F.close();
}
 
struct polinomQ { float data; float number2; polinomQ* next; } *S2;
void Read_polinomQ(polinomQ* S2) { // функция формирования списка 
    polinomQ* t2;
    t2 = S2;
    ifstream F2;
    F2.open("file2.txt");
 
    if (!F2.is_open())
    { cout << "Ошибка откытия файла" << endl; }
    else {
        cout << "Файл открыт" << endl;
 
        while (!F2.eof())
        {
            F2 >> number2; // заглавное звено
            t2->next = new polinomQ;
            t2 = t2->next;
            t2->data = number2;
        }
 
        t2->next = new polinomQ;
        t2 = t2->next;
        t2->data = number2;
 
        t2->next = NULL;
    }
    F2.close();
}
struct polinomR { float data; float number3;  polinomR* next;} *S3;
void Sum(polinomR* S3) {
    polinomP *t;
    polinomQ *t2;
    polinomR *t3;
    for (t = S, t2 = S2, t3 = S3; t->next != NULL && t2->next != NULL; t = t->next, t2 = t2->next) {
        if ((t->data + t2->data) != 0)
        {
 
 
            t3->next = new polinomR;
            t3 = t3->next;
            t3->data = (t->data + t2->data);
            t->power
        }
        else
        {
            t3 = 000;
        }
    }
}
 
void Print(polinomP* S, polinomQ* S2, polinomR *S3)
{
    ofstream fout("file3.txt", ios_base::app);
    polinomP* t;
    fout << "polynom P" << endl;
    for (t = S->next; t->next != NULL; t = t->next)
    {
        fout << t->data << " " << t->power << "| ";
 
    }
    fout << endl;
    polinomQ* t2;
    fout << "polynom Q" << endl;
    for (t2 = S2->next; t2->next != NULL; t2 = t2->next)
    {
        fout << t2->data << " ";
    }
    fout << endl;
    polinomR* t3;
    fout << "polinomR" << endl;
    for (t3 = S3->next; t3->next != NULL; t3 = t3->next)
    {
        if (t != 000) {
            fout << t3->data << " ";
            }
        else {
            fout << " ";
        }
    }
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
    Print(S, S2, S3);
}
 