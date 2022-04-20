#include "Header.h"
#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;
using namespace A;

int main() {
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите этаж: ";
	cin >> A::floor;
	btree* d = NULL;
	queue* q;
	q = (queue*)malloc(sizeof(queue*));
	initilisation(q);

	fstream in("input.txt");
	btree* root = build_tree(&in);
	print(q, root);
	cout << "Обход в ширину" << endl;
	cout << "Количество соседей: " << A::count_sosed << endl;

	return 1;
}
