// один хороший код одного хорошего человека

#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

struct btree {        // Структура дерева, можете заметить, что изначально каждый чаровский элемент это %. это необбходимо для проверки
	char elem;
	btree* left, * right;
};

struct list {
	btree* field;
	struct list* ptr;
};

struct queue {
	struct list* frnt, * rear;
};


struct stek {     // структура стека для дальнейшего прямого обхода
	btree* tree; // туда
	stek* back;  // обратно
};

btree* build_tree(fstream* doc)     // Функция считывания дерева из файла "input.txt" 
{
	char sym;
	btree* d;
	*doc >> sym;
	switch (sym)
	{
	case '(':
	{
		d = new btree;
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

btree* getlast(queue* q) {                         // Взятие головы очереди
	btree* x;
	x = q->frnt->field;
	return x;
}

void prem_obhod(btree* head) { 

	btree* d = head;
	stek* sth = new stek, * stn = NULL;
	sth->back = NULL;
	sth->tree = NULL;
	while (d != NULL) 
	{
				cout << d->elem;
		if ((d->left != NULL && d->right != NULL))
		{
			stn = new stek;
			stn->back = sth;
			sth = stn;
			stn->tree = d->right;
			d = d->left;
		}
		else
		{
			if (d->left == NULL && d->right == NULL)
				if (sth->tree != NULL)
				{
					d = stn->tree;
					sth = stn->back;
					delete stn;
					stn = sth;
				}
				else
					d = NULL;
			else
				if (d->left != NULL)
					d = d->left;
				else
					d = d->right;
		}
	}
}

void initilisation(queue* q) {                    // Иницилизация очереди
	q->frnt = NULL;
	q->rear = NULL;
}

list* init(btree* a) {                             // инициализация листика для переброса
	struct list* lst;
	// Выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->ptr = NULL;                              // Последний узел списка
	return(lst);
}

list* addelem(list* lst, btree* number) {          // "ретранслятор"
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr;                                 // Сохранение указателя на следующий узел
	lst->ptr = temp;                              // Предыдущий узел указывает на создаваемый
	temp->field = number;                         // Сохранение поля данных добавляемого узла
	temp->ptr = p;                                // Созданный узел указывает на следующий элемент
	return(temp);
}

void Add(queue* q, btree* x) {                     // Добавление в очередь 
	if ((q->rear == NULL) && (q->frnt == NULL)) {
		q->rear = init(x); 
		q->frnt = q->rear; 
	}
	else
		q->rear = addelem(q->rear, x);
}

btree* Delete(queue* q) {                          // Удаление головы очереди
	struct list* temp;
	btree* x;
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

void print(queue* q, btree* head) {
	btree* d = head;
	initilisation(q);
	if (d != NULL) {
		Add(q, d);
		do
		{
			d = getlast(q);
			if (d->elem != NULL)
				cout << d->elem;
			if (d->left != NULL)
				Add(q, d->left);
				if (d->right != NULL)
					Add(q, d->right);
			Delete(q);
		} while (q->frnt != NULL);
	}
}
/*
int print_queue(queue* q, btree* d) { // Вывод дерева в ширину
	initilisation(q);
	if (d != NULL) {
		Add(q, d);
		do
		{
			d = getlast(q);
			if (d->elem != NULL)
			cout << d->elem;
			if (d->left != NULL) 
				Add(q, d->left)
			if (d->right != NULL)
				Add(q, d->right);
			Delete(q);
		} while (q->frnt != NULL);
	}
}*/

int main() {                 // основная функция т.к. все фукции описаны выше, мы просто вызываем их исполнение
	setlocale(LC_CTYPE, "Russian");
	btree* d = NULL;
	queue* q;
	q = (queue*)malloc(sizeof(queue*));
	initilisation(q);

	fstream in("input.txt");
	btree* root = build_tree(&in);
	prem_obhod(root);
	cout << " - Прямой обход" << endl;
	print (q, root);
	cout << " - НЕ Прямой обход" << endl;
	return 1;
}


//  Что же пишут в газетах в разделе "Из зала суда"?\
	Приговор приведен в исполненье.Взглянувши сюда,\
	обыватель узрит сквозь очки в оловянной оправе,\
	как лежит человек вниз лицом у кирпичной стены;\
	но не спит.Ибо брезговать кумполом сны\
	продырявленным вправе.

