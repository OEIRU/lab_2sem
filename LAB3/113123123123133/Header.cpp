#include "Header.h"
#include <fstream>



struct tree* adde(fstream* doc)
 {
        int sym;
        float num;
        tree* d;
        *doc >> sym;
        switch (sym)
        {
        case '(':
        {
            d = new tree;
            *doc >> sym;
            d->elem = sym;
            d->left = adde(doc);
            d->right = adde(doc);
            *doc >> sym;
            return  d;        
        }

        case '0':
            return NULL;

        case ',':
        {
            d = adde(doc);
            break;
        }
        }
 }


list* init(tree* a)         //���������� � ������� (���������������)
{
    struct list* lst;
    // ��������� ������ ��� ������ ������
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->ptr = NULL; // ��� ��������� ���� ������
    return(lst);
}

list* addelem(list* lst, tree* number)         //���������� � ������� (���������������)
{
    struct list* temp, * p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->ptr; // ���������� ��������� �� ��������� ����
    lst->ptr = temp; // ���������� ���� ��������� �� �����������
    temp->field = number; // ���������� ���� ������ ������������ ����
    temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
    return(temp);
}

void initilisation(queue* q)            //������������ �������
{
    q->frnt = NULL;
    q->rear = NULL;
}

void Add(queue* q, tree* x)              //���������� � �������
{
    if ((q->rear == NULL) && (q->frnt == NULL)) {
        q->rear = init(x);
        q->frnt = q->rear;
    }
    else
        q->rear = addelem(q->rear, x);
}

tree* Delete(queue* q)                 // �������� ������ �������
{
    struct list* temp;
    tree* x;
    if (Full(q) == 1) {
        printf("������� �����!\n\n");
        return 0;
    }
    x = q->frnt->field;
    temp = q->frnt;
    q->frnt = q->frnt->ptr;
    free(temp);
    return x;
}

bool Full(queue* q)                 //�������� �� ������������ �������
{
    if (q->frnt == NULL)
        return 1;
    else
        return 0;
}
tree* getlast(queue* q)                 // ������ ������ �������
{
    tree* x;
    x = q->frnt->field;
    return x;
}



void treeprintwide(queue* q, tree* d)                    // ����� ������ � ������
{
    initilisation(q);
    if (d != NULL) {
        Add(q, d);

        do
        {
            d = getlast(q);
            cout << d->elem << endl;
            if (d->left != NULL) Add(q, d->left);
            if (d->right != NULL) Add(q, d->right);
            Delete(q);


        } while (q->frnt != NULL);
    }
}

tree* build_tree(fstream* doc)     // ������� ���������� ������ �� ����� "input.txt" 
{
    char sym;
    float num;
    tree* d;
    *doc >> sym;
    switch (sym)
    {
    case '(':
    {
        d = new tree;
        *doc >> sym;
        d->elem = sym;
        d->left = build_tree(doc);
        d->right = build_tree(doc);
        *doc >> sym;
        return  d;
    }

    case '0':
        return NULL;

    case ',':
    {
        d = build_tree(doc);
        break;
    }
    }
}