#include <stdio.h>
#include <cmath>
 
int main() {
    // Работа с файлами - later
    // ввод массива P
    struct polinomP { char l; polinomP* next; };
    polinomP* head, * p; char ch;
    head = p = new polinomP;
    scanf_s("%c", &(p->l));
    scanf_s("%c", &ch);
    while (ch != '\n') {
        p->next = new polinomP; p = p->next; p->l = ch;
        scanf_s("%c", &ch);
    }
    p->next = NULL; // ура, запустилось 
 
// КАК ВЫВЕСТИ ПОЛИНОМ
    // Пока не конец строки
    // ввод массива Q
    struct polinomQ { char l; polinomQ* next; };
    polinomQ* head, * q; char ch;
    head = q = new polinomQ;
    scanf_s("%c", &(q->l));
    scanf_s("%c", &ch);
    while (ch != '\n') {
        q->next = new polinomQ; q = q->next; q->l = ch;
        scanf_s("%c", &ch);
    }
    q->next = NULL; // ура, не запустилось
}
// Ну а тут чисто по дефолту
//     рассмотрим размерности двух списков
//     возьмем наибольшее
//     и начнем поиндексально складывать
 
    // Первая редакция программы - два полинома делаются в 2 прогона
    // Вторая редакция программы - два полинома делаются в 
    // одном динамическом массиве
    // Третья редакция программы - работа с файлами
    // Четвертая редакция программы - автоматизация подсчета A[1][i] + A[2][i]
 