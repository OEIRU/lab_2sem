#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int number;
struct list3 {int el; list3  *next;} *S;
struct dline { list3  *beg, *end ; } *M;
 
 
void Read(list3* S) // функция формирования списка
{
    list3* t;
    t = S;
    
    dline* l;
    l = M;
 
    ifstream F;
    F.open("input.txt");
 
    if (!F.is_open())
    {
        cout << "Ошибка откытия файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
 
        while (!F.eof())
        {
            F >> number; // заглавное звено
            l->beg; 
            // обозначаем и сдвигаем beg (да ничерта он не начальный)
            t->next = new list3; // оно смеется надо мной 
            t = t->next; 
            t->el = number;
        }
 
        t->next = new list3;
        t = t->next;
        l->end; // обозначаем позицию end (А КУДА)
        t->el = number;
        t->next = NULL;
    }
    F.close();
}
 
 
int pushdline (dline *t, int el) // пушим 
// t - херь, которая пробегает по списку
// beg - начальный элемент
// end - конечная
{list3 *r;
  r = new  list3;  r->el = el;  r->next = NULL; // он по новой это делаеТ?? Плевать, список уже создан. 
  if (t->beg == NULL)  t->end = t->beg = r;       // добавление в пустую очередь
  //Segmentation fault
     else { t->end->next = r; t->end = r;}
} 
 
int  popdline (dline *t, int *el) // удоляем
{ list3 *r;
   if (t->beg == NULL)  
        {return 0; cout << "Чел, очередь пуста" << endl;}         //очередь пуста
  *el = t->beg-> el;  r = t->beg;
  t->beg = t->beg->next;
     delete r; 
return 1;
} 
 
 void Print(list3* S)
{
    ofstream fout("output.txt", ios_base::app);
    list3* t;
    for (t = S->next; t->next != NULL; t = t->next)
    {
        fout << t->el << " "; 
    }
    fout << endl;
}
 
 int main() {
    S = new list3;
    Read(S);
    Print(S);
    pushdline (M, 42);
    popdline (M, 0);
    Print(S);
 
 }
 
 /*
Основная проблема - не читается оператор t, то есть я не понимаю, что в него вкладывать. 
По сути он должен прогонять весь созданный список и смотреть в нем указатели beg и end. 
НО ОН ВЫДАЕТ ПЕРЕПОЛНЕНИЕ СПИСКА, видимо не захватывает эти указатели. 
Функции взял из методички. В них самих проблем нет. 
Функцию чтения//ввода взял из прошлой лабы. 
Марк, хелпани. 
Надо как-то после создания объявить расположение этих указателей, чтобы потом на них сослаться. 
 */
 
/*
Вторая часть задания - это создание деки
Следовательно создание деки решит проблему буквы А, и сделает код более гибким. 
Нужно лишь поменять направление движения динамического списка. 
 
Написания нужной нам деки не нашел, придется брать пример из лекции 1_2. 
*/ 