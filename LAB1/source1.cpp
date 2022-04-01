#include <stdio.h>
#include <cmath>
 
int main() {
    struct polinom { char l; polinom* next; };
    polinom* head, * p; polinom* head2, *p2; char ch;
    fopen_s(&f, "input.txt", 'r');
    head = p = new polinom;
    fopen_s(f, &f, "input.txt", 'r');
    fscanf_s(f, "%c", &ch);
    int i;
    while (ch != '\n') {
        p->next = new polinom; 
        p = p->next; 
        p->l = ch;
        scanf_s(f, "%c", &ch);
    }
    p2 = p;
    p->next = NULL;
 
    head2 = p2 = new polinom;
    scanf_s("%c", &(p2->l));
    scanf_s("%c", &ch);
    while (ch != '\n') {
        p2->next = new polinom;
        p2 = p2->next;
        p2->l = ch;
        scanf_s(f, "%c", &ch);
    }
    p2->next = NULL;
 
    fclose(f);
    return 0;
}