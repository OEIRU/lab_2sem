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

list* init(tree* a) {                             // Добавление в очередь(вспомогательная)
    struct list* lst;
                                                  // Выделение памяти под корень списка
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->ptr = NULL;                              // Последний узел списка
    return(lst);
}

list* addelem(list* lst, tree* number) {          // Добавление в очередь (вспомогательная)
    struct list* temp, * p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->ptr;                                 // Сохранение указателя на следующий узел
    lst->ptr = temp;                              // Предыдущий узел указывает на создаваемый
    temp->field = number;                         // Сохранение поля данных добавляемого узла
    temp->ptr = p;                                // Созданный узел указывает на следующий элемент
    return(temp);
}

void initilisation(queue* q) {                    // Иницилизация очереди
    q->frnt = NULL;
    q->rear = NULL;
}

void Add(queue* q, tree* x) {                     // Добавление в очередь
    if ((q->rear == NULL) && (q->frnt == NULL)) {
        q->rear = init(x);
        q->frnt = q->rear;
    }
    else
        q->rear = addelem(q->rear, x);
}

tree* Delete(queue* q) {                          // Удаление головы очереди
    struct list* temp;
    tree* x;
    if (q->frnt == NULL) {
        printf("Очередь пуста!\n\n");
        return 0;
    }
    x = q->frnt->field;
    temp = q->frnt;
    q->frnt = q->frnt->ptr;
    free(temp);
    return x;
}

tree* getlast(queue* q) {                         // Взятие головы очереди
    tree* x;
    x = q->frnt->field;
    return x;
}

int n = 0;

int print_queue(queue* q, tree* d, int floor) { // Вывод дерева в ширину
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
                cout << "\n Количество элементов на этом этаже: " << sosed_2; return 1;
            }
            Delete(q);
        } while (q->frnt != NULL);
        // для последнего сущ. этажа
        if (n == floor) {
            cout << " \n Количество элементов на этом этаже: " << sosed_2;
        }
        else cout << "\n Этого этажа не существует";
    }
    return sosed_2;
}

// отдых тоже важен, а то  if (n != n) { cout << n; }
