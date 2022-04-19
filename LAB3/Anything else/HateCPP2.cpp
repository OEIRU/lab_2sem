// один хороший код одного хорошего человека

#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

namespace A {
	int count = 0;
	int floor_now = 1; // ну не работает нулевой этаж
	int floor;
	int count_sosed = 0;
}

struct btree {        // Структура дерева, можете заметить, что изначально каждый чаровский элемент это %. это необбходимо для проверки
	char elem;
	btree* left, * right;
};

struct list {
	int frontir = 0;
	btree* field;
	struct list* ptr;
};

struct queue {
	struct list* frnt, * rear;
};
struct list global;

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

void prem_obhod(btree* head) {  // функция прямого обхода и вывода элементов дерева

	btree* d = head;
	stek* sth = new stek, * stn = NULL;
	sth->back = NULL;
	sth->tree = NULL;
	while (d != NULL)  // т.к. я реализовал прямой обход выше, то решил сделать стандартный обход, а не рекурсивный
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
			if (d->left == NULL && d->right == NULL) // Если все же возникнет вопрос, то по большей части этот обход организован по тому принципу, который давался на лекции
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
	lst->field = a;	// ЗАКЛАДКА УРОВНЯ, ЗАКЛАДКА УРОВНЯ, КТО ТАКОЕ А
	lst->ptr = NULL;     
	// Последний узел списка, ПТР ИДЕТ ЛЕСОМ, ОБНУЛЯЕМ СОСЕДЕЙ
	return(lst);
}
list* addelem(list* lst, btree* number) {          // "ретранслятор"
	struct list* temp, * p; 
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr;                                 // Сохранение указателя на следующий узел
	lst->ptr = temp;                              // Предыдущий узел указывает на создаваемый
	temp->field = number;							// Сохранение поля данных добавляемого узла
	temp->ptr = p;
	//global.frontir->global.frontir++;
	A::count++;

	if (A::count == 2) { A::floor_now++;} // ну не работает нулевой этаж
	return(temp);
}
void Add(queue* q, btree* x) {                     // Добавление в очередь 
	if ((q->rear == NULL) && (q->frnt == NULL)) {
		q->rear = init(x); 		
		q->frnt = q->rear;
	}
	else
	{
		q->rear = addelem(q->rear, x) ;
		if (A::count == 2) {
			A::count_sosed++;
		}


	}
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
				cout << d->elem << endl;
				// cout  << "Этажерка - " << q->frnt << endl;
				if (d->left != NULL)
				{
					Add(q, d->left);
				}
			if (d->right != NULL)
				Add(q, d->right);
			Delete(q);
			// до обнуления скипать число соседей

			A::count = 0; 
		} while (A::floor_now != A::floor+1);
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
	cout << "Введите этаж: ";
	cin >> A::floor;
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
	cout << "Количество соседей: " << A::count_sosed << endl;

	return 1;
}


//  Что же пишут в газетах в разделе "Из зала суда"?\
	Приговор приведен в исполненье.Взглянувши сюда,\
	обыватель узрит сквозь очки в оловянной оправе,\
	как лежит человек вниз лицом у кирпичной стены;\
	но не спит.Ибо брезговать кумполом сны\
	продырявленным вправе.

