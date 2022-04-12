#include "Header.h"
#include <fstream>
using namespace std;

struct tree* adde(char x, tree* d) {
    if (d == NULL) {
        d = new tree;
        d->elem = x;
        d->left = NULL;
        d->right = NULL;
    }
    else if (x < d->elem)
        d->left = adde(x, d->left);
    else
        d->right = adde(x, d->right);
    return(d);
};

list* init(tree* a) {                             // ���������� � �������(���������������)
    struct list* lst;
                                                  // ��������� ������ ��� ������ ������
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->ptr = NULL;                              // ��������� ���� ������
    return(lst);
}

list* addelem(list* lst, tree* number) {          // ���������� � ������� (���������������)
    struct list* temp, * p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->ptr;                                 // ���������� ��������� �� ��������� ����
    lst->ptr = temp;                              // ���������� ���� ��������� �� �����������
    temp->field = number;                         // ���������� ���� ������ ������������ ����
    temp->ptr = p;                                // ��������� ���� ��������� �� ��������� �������
    return(temp);
}

void initilisation(queue* q) {                    // ������������ �������
    q->frnt = NULL;
    q->rear = NULL;
}

void Add(queue* q, tree* x) {                     // ���������� � �������
    if ((q->rear == NULL) && (q->frnt == NULL)) {
        q->rear = init(x);
        q->frnt = q->rear;
    }
    else
        q->rear = addelem(q->rear, x);
}

tree* Delete(queue* q) {                          // �������� ������ �������
    struct list* temp;
    tree* x;
    if (q->frnt == NULL) {
        printf("������� �����!\n\n");
        return 0;
    }
    x = q->frnt->field;
    temp = q->frnt;
    q->frnt = q->frnt->ptr;
    free(temp);
    return x;
}

tree* getlast(queue* q) {                         // ������ ������ �������
    tree* x;
    x = q->frnt->field;
    return x;
}

int n = 0;

int print_queue(queue* q, tree* d, int floor) { // ����� ������ � ������
    int sosed = 0, sosed_2 = 0;
    initilisation(q);
    if (d != NULL) {
        Add(q, d);
        do
        {
            d = getlast(q);
            cout << n;
            if (d->elem != NULL) sosed++;
            cout << d->elem;
            if (d->left != NULL) {
                Add(q, d->left); n++; sosed_2 = sosed; sosed = 0;
            }
            if (d->right != NULL)
                Add(q, d->right);
            if (n > floor) {
                cout << "\n ���������� ��������� �� ���� �����: " << sosed_2; return 1;
            }
            Delete(q);
        } while (q->frnt != NULL);
        // ��� ���������� ���. �����
        if (n == floor) {
            cout << " \n ���������� ��������� �� ���� �����: " << sosed_2;
        }
        else cout << "\n ����� ����� �� ����������";
    }
    return sosed_2;
}

// ����� ���� �����, � ��  if (n != n) { cout << n; }
