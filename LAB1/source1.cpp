#include <stdio.h>
#include <cmath>
 
int main() {
    struct list {
        list* next;
        char elem;
        int number;
    }
    list * ph; * num; // не объявляется num
    list* p, * p2, * p3, * counter;
    // p - первый полином
    // p2 - второй полином
    // p3 - сумма полиномов 
    // counter - степень полинома
 
    char ch;
    int i = 0;
    FILE* f;
    fopen_s(&f, "input.txt", "r");
 
    {ph = new list; // объявление ph главным звеном
    fscanf_s(f, "%c", &ch);
    ph->next = NULL; // next - прямая ссылка
    num->next = NULL;
    p = ph; // сделать p заглавным звеном (заготовка для продвижения)
    counter = num; // num - считать
    while ((ch = getchar()) != '\n') {
        p->next = new list; // Создание очеревдного звена (продвижение)
        counter->next = new list;
        p = p->next; // p присваиваем ссылку на очередное звено (действие на ячейку)
        counter = counter->next;
        p->elem = ch; // elem присваиваем значение символа ch (действие на содержание ячейки)
        counter->number = i++;
        scanf(f, "%c", &ch);
    }
    p2 = p->next;
    p = NULL;
 
    int i = 0; //  обнулить
    while ((ch = getchar()) != '\n') {
        p2->next = new list; // повторение создания заглавного звена? 
        counter->next = new list;
        p2 = p2->next;
        counter = counter->next;
        p2->elem = ch;
        counter->number = i++;
        scanf(f, "%c", &ch);
    }
    
        // степень n[i] = n[0] - истинная степень
 
    p2->next = NULL;
    list * ph2;
    for (p = ph, p2 = ph2; p != NULL, p2 != NULL; p = p->next, p2 = p2->next) {
        p3 -> (p + p2);
        p3 = p3->next;
        // вывод в формате 
        // p1 = 2x^3 + 3x^2 + 2x + 6
        // p2 = 4x^3 + 6x^2 + 7x - 3
        // p3 = 6x^3 + 9x^2 + 9x + 3
    }
    p3 -> next = NULL;
 
    // открыть файл для третьего
    for (p3 = ph; p->next != NULL; p3 = p->next) {
        // вывод значения p3 + значение степени через цикл for 
        // (хотя n нужно как-то достать)
    }
    }
    return 0;
}