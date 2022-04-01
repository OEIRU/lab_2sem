#include <stdio.h>
#include <locale.h>
#include <stack.h>
using namespace std;

int main() {
    int i = 0, n; 
    bool flag = false;
    int i;
    queue *q = CreateQueue();
    setlocale(LC_CTYPE, "Russian");
    do {
        printf ("<1> - Прочитать последовательность из файла");
        printf ("<2> - Добавить элемент в очередь");
        printf ("<3> - Распечатать содержание очереди");
        printf ("<4> - Извлечь элемент из очереди");
        printf ("<5> - Очистить очередь");
        printf ("<6> - Выход");
        do {
            printf ("Введите номер команды (от 1 до 6)");
            scanf ("%d", &n);
            switch (n)
            {
            case1: PrintFile(); break;
            case2: printf("Введите число: ");
                        scanf ("%d", &i);
                        putToQueue (q,i); break;
            case3: PrintQueue(q); break;
            case4: takeFromQueue(q, &i); break;
            case5: ClearQueue(q);
            case6: flag = true; break;
            
            default:
                printf("Ошибка: неверный номер"); return 1;
            }
        } while (!flag);
    }while (!flag);

}