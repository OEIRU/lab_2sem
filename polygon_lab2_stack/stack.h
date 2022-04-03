#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
struct list
{
    list *next;
    int elem;
};
typedef list stack;
// Поместить элемент в стек
void Push(stack *&p, int num);
/* inline-функция проверки стека на пустоту, тело которой
может быть встроено непосредственно в месте ее вызова */
inline int isStackEmpty(stack *&p) { return p == NULL; }
// Извлечь элемент из стека
int Pop(stack *&p, int &num);
// Распечатать содержимое стека
void printStack(stack *&p);
#endif /* STACK_H */