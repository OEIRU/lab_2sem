#ifndef STACK_H
#define STACH_H

#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

struct list{int el; list *next; list *pred;};
struct queue{list *beg, *end;};
ofstream fout("output.txt", ios_base::app);



void putToQueue(queue *q, int iEl);      //добавить в очередь
int takeFromQueue(queue *q, int *iEl);   //взять из очереди

queue *CreateQueue()            //создать очередь
{
    queue *q;
    q = new queue;
    q->beg = NULL;
    q->end = NULL;
    return q;
}

int isQueueEmpty(queue *q);              //проверка очереди на пустоту
int ClearQueue(queue *q);                //очистка очереди
void PrintQueue(queue *q);               //вывести очередь на экран
void PrintFile(queue *q);                         //чтение из файла

#endif