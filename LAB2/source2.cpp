#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int number;
struct list3
{ char el; list3 *next; } *S; // ГРЕБАННЫЙ СПИСОК
struct dline
{ list3 *beg, *end ; } *t; // ПУТЕВОДИТЕЛЬ ПО СПИСКУ
 
void Read(list3* S  ) // функция формирования списка
{
    list3* t;
    t = S;
 
    ifstream F;
    F.open("input.txt");
 
    if (!F.is_open())
    {
        cout << "Файл не открылся! Проверь название/существование" << endl;
    }
    else {
        cout << "Opening file" << endl;
 
        while (!F.eof())
        {
            F >> number; // заглавное звено
            t->next = new list3; // оно смеется надо мной 
            t = t->next; // нееет
            t->el = number; // осмысленные комментарии
        }
 
        t->next = new list3; // край мира
        t = t->next;
        t->el = number;
        t->next = NULL;
        cout << "Я прочитал твой файл, хозяин!" << endl;
    }
    F.close(); cout << "Я закрыл файл, с которого читал"<< endl;
}
// список создан, катаемся по dline
 
int pushdline (dline* t, int el) // пушим
{list3 *r; // пробегает список походу
  r = new  list3;  r->el = el;  r->next = NULL; // он по новой это делаеТ?? П-плевать, давай, читай откуда-то, мы же миллионеры 
  if (t->beg == NULL)  {t->end = t->beg = r; cout << "Добавился в пустую очередь" << endl;}  // добавление в пустую очередь
  //Segmentation fault, этого указателя t! (переехал на 56 строку)
     else { t->end->next = r; t->end = r; cout << "Ну я добавил в самое начало, оке?" << endl;}
} 
 
int  popdline (dline* t, int *el) // удоляем
{ list3 *r;
   if (t->beg == NULL)  
        {return 0; cout << "Чел, очередь пуста" << endl;}
        // ДА КТО ТАКОЙ *el... указатель на el (порядок el? или положение. Точно, положение в списке)
  *el = t->beg-> el;  r = t->beg; // захватываем элемент
  // убивать, убивать, убивать, убивать.
  t->beg = t->beg->next; // шо я делаю? 
     delete r; 
     cout << "Удалил" << endl;// удалять, удалять, удалять
return 1; // оффнуть программу (может не надо?)
} 
 
 
 // не кастуется
 void Print(list3 *S)
{
    ofstream fout("output.txt", ios_base::app);
    list3* t;
    for (t = S->next; t->next != NULL; t = t->next)
    {
        fout << t->el << " "; 
    }
    fout << endl;
}
 
 // ДА НЕ БЫЛО НИКАКОГО *S
 // НИКОГО ТЫ НЕ СБИВАЛ 510 ЛЕТ НАЗАД
 // *S НИКОГДА НЕ СУЩЕСТВОВАЛО
 // ОН ВСЕГО ЛИШЬ УКАЗАТЕЛЬ
 
 
 int main() {
    S = new list3;
    t = new dline; // Никакой связи с S
    Read(S);
    // на данном этапе у нас лежит полностью готовый список в list3
    Print(r);
    pushdline (t, 42);
    pushdline (t, 42);
    pushdline (t, 42);
 
    popdline (t, 0); // вместо нуля должна быть ссылка? 
    Print(S);
 }
 
 // Я МЫСЛЮ, СЛЕДОВАТЕЛЬНО СУЩЕСТВУЮ, МАРК, НЕСИ КАПИТАЛ!
 // Ачивка "Полное погружение"
 // Пересмотреть "Сияние", держа в руках топор.
 
 /*
 Что же пишут в газетах в разделе «Из зала суда»?
Приговор приведен в исполненье. Взглянувши сюда,
обыватель узрит сквозь очки в оловянной оправе,
как лежит человек вниз лицом у кирпичной стены;
но не спит. Ибо брезговать кумполом сны
продырявленным вправе.  
*/
// Есть такой зверек - вомбат, а готовой лабы так и нет!
// Да кто такой ваш Бродске 
 
/*
int main() {
    S = NULL;
    t = NULL;
    pushdline (t, 0);
    pushdline (t, 15);
    pushdline (t, 13);
    popdline(t, 0);
    Print(S);
}*/
 
 