#include "stack.h"
#include "stdio.h"
void Push(stack *&p, int num)
{
    if (p == NULL)
    {
        p = new stack;
        p->next = NULL;
        p->elem = num;
    }
    else
    {
        stack *q = new stack;
        q->elem = num;
        q->next = p;
        p = q;
    }
}
int Pop(stack *&p, int &num)
{
    if (!isStackEmpty(p))
    {
        num = p->elem;
        if (p->next == NULL)
        {
            delete p;
            p = NULL;
        }
        else
        {
            stack *q = p;
            p = p->next;
            delete q;
        }
        return 0;
    }
    return 1;
}
void printStack(stack *&p)
{
    printf("Содержимое стека: ");
    if (p != NULL)
    {
        stack *q = p;
        do
        {
            printf("%d ", q->elem);
            q = q->next;
        } while (q != NULL);
    }
    printf("\n");
}
