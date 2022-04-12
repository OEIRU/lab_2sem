#include "Header.h"

using namespace std;

void main()
{	
	setlocale(LC_ALL, "Rus");
	char number;

	char x;
	tree* d = NULL;
	queue* q;
	q = (queue*)malloc(sizeof(queue*));
	initilisation(q);
	int floor;
	cout << "введите этаж";
	cin >> floor;

	//x = 50; d = adde(x, d); x = 40; d = adde(x, d); x = 30; d = adde(x, d); x = 20; d = adde(x, d); x = 45; d = adde(x, d); x = 44; d = adde(x, d); x = 46; d = adde(x, d); x = 35; d = adde(x, d); x = 60; d = adde(x, d); x = 70; d = adde(x, d); x = 80; d = adde(x, d); x = 65; d = adde(x, d); x = 58; d = adde(x, d); x = 55; d = adde(x, d); x = 59; d = adde(x, d);

		x = 'A'; d = adde(x, d); 
		x = 'B'; d = adde(x, d);
		x = 'D'; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = 'C'; d = adde(x, d);
		x = 'E'; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = 'G'; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = 'F'; d = adde(x, d);
		x = 'H'; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = 'I'; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);
	
	do
	{
		cout << "1. Добавить" << endl;
		cout << "2. Вывод" << endl;
		cout << "0. Выйти\n\n";
		cout << "Номер команды > "; cin >> number;
		switch (number)
		{

		case '2':
			cout << endl;
			
			treeprintwide(q, d, floor);
			cout << endl;
			break;
			
		case '0': break;
		default: cout << endl << "Сбой системы\n\n";
			break;
		}
	} while (number != '0');
	

}