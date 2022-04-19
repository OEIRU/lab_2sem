#include <stdio.h>
#include <locale.h>
#include "stack.h"
int main()
{
    int n = 0, exitFlag = 0, m = 0;
    stack *st = NULL;
    setlocale(LC_CTYPE, "Russian");
    do
    { // Меню работы со стеком
        printf("<1> - поместить элемент в стек\n");
        printf("<2> - распечатать содержимое стека\n");
        printf("<3> - извлечь элемент из стека\n");
        printf("<4> - выход\n");
        int repeatFlag = 0;
        do
        {
            printf("Введите номер команды (от 1 до 4): ");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                printf("Введите число: ");
                scanf("%d", &m);
                Push(st, m);
                break;
            case 2:
                if (!isStackEmpty(st))
                    printStack(st);
                else
                    printf("Стек пуст\n");
                break;
            case 3:
                if (!Pop(st, m))
                    printf("Из стека извлечен элемент: %d\n", m);
                else
                    printf("Стек пуст\n");
                break;
            case 4:
                exitFlag = 1;
                break;
            default:
                printf("ОШИБКА: неверный номер команды\n");
                repeatFlag = 1;
            }
        } while (!repeatFlag && !exitFlag);
    } while (!exitFlag);
}
