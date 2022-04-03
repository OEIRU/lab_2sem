#include "stack.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    int i = 0, exitFlag = 0;
    queue *q = CreateQueue();
    setlocale(LC_CTYPE, "Russian");
    do
    {
        printf("<1> - Прочитать последовательность из файла\n");
        printf("<2> - Добавить элемент в очередь\n");
        printf("<3> - Распечатать содержание очереди\n");
        printf("<4> - Извлечь элемент из очереди\n");
        printf("<5> - Очистить очередь\n");
        printf("<6> - Выход\n");
        int repeatFlag = 0;
        do
        {
            printf("Введите номер команды (от 1 до 6)\n");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                PrintFile(q);
                break;
            case 2:
                printf("Введите число: ");
                scanf("%d", &i);
                putToQueue(q, i);
                break;
            case 3:
                PrintQueue(q);
                break;
            case 4:
                takeFromQueue(q, &i);
                break;
            case 5:
                ClearQueue(q);
            case 6:
                exitFlag = 1;
                break;
            default:
                printf("Ошибка: неверный номер\n");
                break;
            }
        } while (!repeatFlag && !exitFlag);
    } while (!exitFlag);
}