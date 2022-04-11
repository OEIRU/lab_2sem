#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;


struct btree {        // Структура дерева, можете заметить, что изначально каждый чаровский элемент это %. это необбходимо для проверки
	char elem;
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
	
	int n;
	btree* d = head;
	stek* sth = new stek, * stn = NULL;
	sth->back = NULL;
	sth->tree = NULL;


	while (d != NULL)  // ГРЕБАННЫЙ ОБХОД В ГЛУБИНУ
		// НАМ В ШИРИНУ ТО НУЖЕН
		// МАРКО, ГДЕ ОТВЕТЫ НА ВОПРОСЫ ВСЕЛЕННОЙ
		// И ВСЕГО МИРОЗДАНИЯ


	{
		cout << d->elem;
		if ((d->left != NULL && d->right != NULL))
		{
			stn = new stek;
			stn->back = sth;
			sth = stn;
			stn->tree = d->right;
			// cout << stn << endl;
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


int main() {                 // основная функция т.к. все фукции описаны выше, мы просто вызываем их исполнение
	setlocale(LC_CTYPE, "Russian");
	fstream in("input.txt");
	btree* root = build_tree(&in);
		prem_obhod(root);
		cout << " - Прямой обход" << endl;
	return 1;
}

// и я почти не сплю
// да кому это сдалось! 
// СНА НЕ СУЩЕСТВУЕТ
// страдать страдать страдать
// так и не написал письмо

