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


list* init(tree* a)         //добавление в очередь (вспомогательная)
{
    struct list* lst;
    // выделение памяти под корень списка
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->ptr = NULL; // это последний узел списка
    return(lst);
}

list* addelem(list* lst, tree* number)         //добавление в очередь (вспомогательная)
{
    struct list* temp, * p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->ptr; // сохранение указателя на следующий узел
    lst->ptr = temp; // предыдущий узел указывает на создаваемый
    temp->field = number; // сохранение поля данных добавляемого узла
    temp->ptr = p; // созданный узел указывает на следующий элемент
    return(temp);
}

void initilisation(queue* q)            //иницилизация очереди
{
    q->frnt = NULL;
    q->rear = NULL;
}

void Add(queue* q, tree* x)              //добавление в очередь
{
    if ((q->rear == NULL) && (q->frnt == NULL)) {
        q->rear = init(x);
        q->frnt = q->rear;
    }
    else
        q->rear = addelem(q->rear, x);
}

tree* Delete(queue* q)                 // удаление головы очереди
{
    struct list* temp;
    tree* x;
    if (Full(q) == 1) {
        printf("Очередь пуста!\n\n");
        return 0;
    }
    x = q->frnt->field;
    temp = q->frnt;
    q->frnt = q->frnt->ptr;
    free(temp);
    return x;
}

bool Full(queue* q)                 //проверка на заполненость очереди
{
    if (q->frnt == NULL)
        return 1;
    else
        return 0;
}
tree* getlast(queue* q)                 // взятие головы очереди
{
    tree* x;
    x = q->frnt->field;
    return x;
}



void treeprintwide(queue* q, tree* d)                    // вывод дерева в ширину
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

tree* build_tree(fstream* doc)     // Функция считывания дерева из файла "input.txt" 
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