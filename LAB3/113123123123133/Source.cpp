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
		cout << "���� �� ��������! ������� ��������/�������������" << endl;
	}
	else {
		tree* root = adde(&in);

		do
		{

			cout << "2. �����" << endl;
			cout << "0. �����\n\n";
			cout << "����� ������� > "; cin >> number;
			switch (number)
			{


			case '2':
				cout << endl;
				treeprintwide(q, d);
				cout << endl;
				break;

			case '0': break;
			default: cout << endl << "���� �������\n\n";
				break;
			}
		} while (number != '0');
	}
}