#include "Header.h"
#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	char number;
	tree* d = NULL;
	int x;
	queue* q;
	q = (queue*)malloc(sizeof(queue*));
	initilisation(q);
	fstream in("input.txt");
	if (!in.is_open())
	{
		cout << "Файл не открылся! Проверь название/существование" << endl;
	}
	else {
		tree* root = adde(&in);

		do
		{

			cout << "2. Вывод" << endl;
			cout << "0. Выйти\n\n";
			cout << "Номер команды > "; cin >> number;
			switch (number)
			{


			case '2':
				cout << endl;
				treeprintwide(q, d);
				cout << endl;
				break;

			case '0': break;
			default: cout << endl << "Сбой системы\n\n";
				break;
			}
		} while (number != '0');
	}
}