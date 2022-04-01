#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
float value;
int stepen;
 
struct polinom { float data; float power; polinom* next; } *S, * S2, * S3;
void Read_polinom(polinom* S, char text) {
    polinom* t;
    t = S;
 
    ifstream F;
    F.open(text);
 
    if (!F.is_open()) {
        cout << "Ошибка откытия файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
 
        while (!F.eof()) {
            F >> value; // заглавное звено
            t->next = new polinom;
            t = t->next;
 
            t->data = value;
            t->power = stepen;
        }
 
        t->next = new polinom;
        t = t->next;
 
        t->data = value;
        t->power = stepen;
        t->next = NULL;
    }
    F.close();
}
 
void Record_polinom(polinom* S, char text) {
    ofstream fout(text, ios_base::app);
    polinom* t;
    fout << "polynom" << endl;
    for (t = S->next; t->next != NULL; t = t->next) {
        fout << t->data << " " << t->power << "| ";
    }
    fout << endl;
}
 
void Sum(polinom* S, polinom* S2) {
    polinom* t;
    polinom* t2;
    polinom* t3;
    ofstream fout("out3.txt", ios_base::app);
    fout << "summa polynom" << endl;
    for (t = S->next, t2 = S2->next; t->next != NULL && t2->next != NULL; t = t->next, t2 = t2->next) {
        if ((t->data + t2->data) != 0) {
            t3->next = new polinomR;
            t3 = t3->next;
            t->power;
                t3->data = (t->data + t2->data);
            fout << t3 << ' ' << t << endl;
        }
        else {
            cout << "/n";
        }
    }
}
 
int main()
{
    setlocale(LC_ALL, "RUS");
    S = new polinomP;
    S2 = new polinomQ;
    S3 = new polinomR;
    Read_polinom(S, "text1.txt");
    Record_polinom(S, "out1.txt");
    Read_polinom(S2, "text2.txt");
    Record_polinom(S2, "out2.txt");
        Sum(S, S2);
}