#include <stdio.h>
#include <cmath>
 
int main() {
    // Работа с файлами - later
    // ввод массива P
    struct polinomP { char l; polinomP* next; };
    polinomP *head, *p; char ch;
    head = p = new polinomP;
    scanf("%c", &(p->l));
    scanf("%c", &ch);
    while (ch != '\n') {
        p->next = new polinomP; p = p->next; p->l = ch;
        scanf("%c", &ch);
    }
    p->next = NULL; // ура, запустилось 
// КАК ВЫВЕСТИ ПОЛИНОМ
    // Пока не конец строки
    // ввод массива Q
    // Пока не конец файла
    // R[i] = P[i] + Q[i] 
    //for (int i = 0; i < n; i++) {
        //polinomR[i] = polinomP[i] + polinomQ[i];
    //} все рушится, если полиномы разной размерности
 
    // if R[i] == 0 -> пропустить
    // Вывести R
}
 
 
 