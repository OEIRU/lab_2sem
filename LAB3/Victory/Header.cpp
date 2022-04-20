#include "Header.h"
#include <fstream>
using namespace std;
using namespace A;
btree* build_tree(fstream* doc) {     // Функция считывания дерева из файла "input.txt" 
	char sym;
	btree* d;
	*doc >> sym;
	switch (sym) {
	case '(': {
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
	case ',': {
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

void initilisation(queue* q) {                    // Иницилизация очереди
	q->frnt = NULL;
	q->rear = NULL;

}

list* init(btree* a) {                            // инициализация списка для переброса (1 раз)
	struct list* lst;
	// Выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;								  // ЗАКЛАДКА УРОВНЯ
	lst->ptr = NULL;							  // Последний узел списка, 
	return(lst);
}

list* addelem(list* lst, btree* number) {         // "ретранслятор"
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr;                                 // Сохранение указателя на следующий узел
	lst->ptr = temp;                              // Предыдущий узел указывает на создаваемый
	temp->field = number;						  // Сохранение поля данных добавляемого узла
	temp->ptr = p;
	//global.frontir->global.frontir++;
	A::count++;
	if (A::count == 2) { A::floor_now++; }
	return(temp);
}

void Add(queue* q, btree* x) {                     // Добавление в очередь 
	if ((q->rear == NULL) && (q->frnt == NULL)) {
		q->rear = init(x);
		q->frnt = q->rear;
	}
	else {
		q->rear = addelem(q->rear, x);
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

void print(queue* q, btree* head) {				   // Вывод 
	btree* d = head;
	initilisation(q);
	if (d != NULL) {
		Add(q, d);
		do {
			d = getlast(q);
			if (d->elem != NULL)
				cout << d->elem << endl;
			if (d->left != NULL)
				Add(q, d->left);
			if (d->right != NULL)
				Add(q, d->right);
			Delete(q);
			A::count = 0;
		} while (A::floor_now != A::floor + 1);
	}
}
