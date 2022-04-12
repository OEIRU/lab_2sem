#include "Header.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	// char x;

	tree* d = NULL;
	queue* q;
	q = (queue*)malloc(sizeof(queue*));
	initilisation(q);

	int floor;
	cout << " Введите этаж: ";
	cin >> floor;

	ifstream F;
	F.open("input.txt");

	if (!F.is_open())
		cout << "Открой файл";
	else {
		cout << "Текстовой файл открыт!";
		string line;
		while (getline(F, line)) {
			for (char x : line) {
				if (x != ' ' && x != ',' && x != '(' && x != ')') {
					if (x == '0') { x = NULL; }
					d = adde(x, d);
				}
			}
		}
	}

	/*

		x = 'A';  d = adde(x, d);
		x = 'B';  d = adde(x, d);
		x = 'D';  d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = 'C';  d = adde(x, d);
		x = 'E';  d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = 'G';  d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = 'F';  d = adde(x, d);
		x = 'H';  d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = 'I';  d = adde(x, d);
		x = NULL; d = adde(x, d);
		x = NULL; d = adde(x, d);

		*/
	cout << endl;
	print_queue(q, d, floor);
}