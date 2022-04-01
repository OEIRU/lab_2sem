#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
double number;
struct elems { double data; elems *next; } *S;
void Make_elems(elems *S) // функция формирования списка
{
    elems *t;
    t = S;
    t2; \\ 
    t3; \\ 
    counter; \\ 
 
    ifstream F;
    F.open("file1.txt");
 
    if (!F.is_open())
    {
        cout << "Ошибка откытия файла" << endl;
    }
    else
    {
        cout << "Файл открыт" << endl;
        for // посчитать 2 раза
        while (ch != '\n')
        {
            F >> number;
            t->next = new elems;
            t = t->next;                
            t->data = number;           
        }
        
        t->next = new elems;
        t = t->next;
        t->data = number;
        t->next = NULL;
        
    }
    F.close();
 
}
 
void Count(elems *S, double number)
{
    elems *t;
    for (t1 = S, t2 = S2; t1->next->next != NULL, t1->next->next != NULL; t1 = t1->next, t2->next)
    {
        t1->next->data -= number;
        t3 = t1 + t2; 
        t3 = t3 -> next; 
        
    }
    if (t1->next->next == NULL, t2->next->next == NULL)
    { t->next = NULL; }
}
 
void Print(elems* S)
{
    ofstream fout("file1.txt", ios_base::app);
    elems *t;
    fout << endl;
    for (t3 = S->next; t3->next != NULL; t = t->next)
    {
        fout << t->data << " ";
        // обозначить for для красивого "x^n"
    }
}
 
int main() 
{
    setlocale(LC_ALL, "RUS");
    S1 = new elems;
    Make_elems(S1, S2);
    Count(S, number);
    Print(S);
}
 
// паста с угрозами