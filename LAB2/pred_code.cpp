#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
 
struct list{int el; list *next; list *pred;};
struct queue{list *beg, *end;};
    ofstream fout("output.txt", ios_base::app);
 
void putToQueue(queue *q, int iEl)   //добавить в очередь
{
    list *tmp;
    tmp = new list;
    tmp->next = NULL;
    tmp->el = iEl;
    if(q->end != NULL)
        q->end->next = tmp;
    else
        q->beg = tmp;
    q->end = tmp;
}
 
int takeFromQueue(queue *q, int *iEl) // взять из очереди
{
    if(q->beg == NULL) return 0;
    list *tmp;
    tmp = q->beg;
    *iEl = tmp->el;
    q->beg = tmp->next;
    delete tmp;
    if(q->beg == NULL) q->end = NULL;
    return 1;
}
 
 
queue *CreateQueue()            //создать очередь
{
    queue *q;
    q = new queue;
    q->beg = NULL;
    q->end = NULL;
    return q;
}
 
int isQueueEmpty(queue *q)      //проверка очереди на пустоту
{
    if(q->beg == NULL) { return 1;}
    return 0;
}
 
int ClearQueue(queue *q)        //очистка очереди
{
    if(q->beg == NULL) return 0;
    list *tmp, *t;
    tmp = q->beg;
    while(tmp->next != NULL)
    {
        t = tmp;
        tmp = t->next;
        delete t;
    }
    q->beg = NULL;
    q->end = NULL;
    return 1;
}
 
void PrintQueue(queue *q)       //вывести очередь на экран
{
    printf("\n");
    queue *tmp = CreateQueue();
    int iEl;
    while(!isQueueEmpty(q))
    {
        takeFromQueue(q, &iEl);
        fout << iEl << " ";
        putToQueue(tmp, iEl);
    }
    while(!isQueueEmpty(tmp))
    {
        takeFromQueue(tmp, &iEl);
        putToQueue(q, iEl);
    }
    fout << endl;
}
 
int main()
{
    int i;
    queue *q = CreateQueue();
    fout << (".......Put Elems..............") << endl; 
    ifstream F;
    F.open("input.txt");
 
    if (!F.is_open())
    {
        fout << "Файл не открылся! Проверь название/существование" << endl;
    }
    else {
        fout << "Opening file" << endl;
 
        while (!F.eof())
        {
            F >> i; // заглавное звено
            putToQueue(q, i);        }
    {
        putToQueue(q, i);
        PrintQueue(q);
    }
    }
    fout << ("\n......Take Elems...............") << endl;
    fout << endl;
    PrintQueue(q);
    while(!isQueueEmpty(q))
    {
        takeFromQueue(q, &i);
        PrintQueue(q);
    }
    fout << ("\n........Put Elems.............") << endl;
    for(i=30; i<35; i++)
    {
        putToQueue(q, i);
        PrintQueue(q);
    }
    fout << ("\n........Clear queue.............") << endl;
    ClearQueue(q);
    PrintQueue(q);
}
 