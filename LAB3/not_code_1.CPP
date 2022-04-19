// один хороший код одного хорошего человека

#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

struct btree {        // Структура дерева, можете заметить, что изначально каждый чаровский элемент это %. это необбходимо для проверки
	char elem = '%';
	float num; 
	btree* left, * right;
};

struct stek {     // структура стека для дальнейшего прямого обхода
	btree* tree; // туда
	stek* back;  // обратно
};

btree* build_tree(fstream* doc)     // Функция считывания дерева из файла "input.txt" 
{
	char sym;
	float num;
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

void prem_obhod(btree* head) {  // функция прямого обхода и вывода элементов дерева
	
	int n, sosed = 0, znak;
	btree* d = head;
	stek* sth = new stek, * stn = NULL;
	sth->back = NULL;
	sth->tree = NULL;
	while (d != NULL)  // т.к. я реализовал прямой обход выше, то решил сделать стандартный обход, а не рекурсивный
	{
		if (d)
		{
			if (d->elem == '%')
				cout << d->num;
			else
				cout << d->elem;
		}
		if ((d->left != NULL && d->right != NULL))
		{
			stn = new stek;
			// n++;
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
		// if (n > znak) { return 1; }
	}
}

void obr_obhod(btree* head) { // рекурсивный обратный обход
	btree* now = head;
	if (head) {
		obr_obhod(now->left);
		if (now->elem == '%')
			cout << now->num;
		else
			cout << now->elem;
		obr_obhod(now->right);
	}
}

void kol_obhod(btree* head) {  // рекурсивный кольцевой обход
	btree* now = head;
	if (head) {
		kol_obhod(now->left);
		kol_obhod(now->right);
		if (now->elem == '%')
			cout << now->num;
		else
			cout << now->elem;
	}
}

int main() {                 // основная функция т.к. все фукции описаны выше, мы просто вызываем их исполнение
	setlocale(LC_CTYPE, "Russian");
	fstream in("input.txt");
	btree* root = build_tree(&in);
		prem_obhod(root);
		cout << " - Прямой обход" << endl;
		obr_obhod(root);
		cout << " - Обратный обход" << endl;
		kol_obhod(root);
		cout << " - Кольцевой обход" << endl;
	return 1;
}