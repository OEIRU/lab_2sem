#include <stdio.h>
#include <cmath>
 
int main() {
    struct list {
        list* next;
        float elem;
        int ch;
    }
    list * ph; * num; // ЭТО ВСЕГО ЛИШЬ СПИСКИ
    list* p, * p2;
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
 
    for (int i = 0; i < 2; i++){
    while ((ch != '\n') {
        p[i]->next = new list; // Создание очеревдного звена (продвижение)
        p[i] = p[i]->next; // p присваиваем ссылку на очередное звено (действие на ячейку)
        p[i]->elem = ch; // elem присваиваем значение символа ch (действие на содержание ячейки)
        scanf(f, "%c", &ch);
    }
    p[i] = p[i]->next;
    p[i] = NULL;
    }
 
    list  *ph2;
    for (p = ph, p2 = ph2; p != NULL, p2 != NULL; p = p->next, p2 = p2->next) {
        p3 -> (p + p2); // бред какой-то 
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
