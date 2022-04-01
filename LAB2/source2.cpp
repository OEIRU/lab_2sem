#include <stdio.h>
 
struct list
{
    int el;
    list *next;
};
 
struct queue
{
    list *beg, *end;
};
 
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
    if(q->beg == NULL) return 1;
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
 
void PrintQueue(queue *q)       //вывестии очередь на экран
{
    printf("\n");
    queue *tmp = CreateQueue();
    int iEl;
    while(!isQueueEmpty(q))
    {
        takeFromQueue(q, &iEl);
        printf("%d ", iEl);
        putToQueue(tmp, iEl);
    }
    while(!isQueueEmpty(tmp))
    {
        takeFromQueue(tmp, &iEl);
        putToQueue(q, iEl);
    }
}
int main()
{
    int i;
    queue *q = CreateQueue();
    printf(".......Put Elems..............");
    for(i=30; i<40; i++)
    {
        putToQueue(q, i);
        PrintQueue(q);
    }
    printf("\n......Take Elems...............");
    while(!isQueueEmpty(q))
    {
        takeFromQueue(q, &i);
        PrintQueue(q);
    }
    printf("\n........Put Elems.............");
    for(i=30; i<35; i++)
    {
        putToQueue(q, i);
        PrintQueue(q);
    }
    printf("\n........Clear queue.............");
    ClearQueue(q);
    PrintQueue(q);
 
}