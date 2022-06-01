#include <iostream>
#include <fstream>
#include <locale.h>
#include <stdio.h>
#include "ConsoleApplication8.h"
using namespace std;

struct table {
	int index = NULL;
	float first = NULL;
	float last = NULL;
	float three = NULL;
};

int read_machine() { // машина, которая перебирает значения и делит на 5
	ifstream fin("input.txt");
	int set = 0, i;
	while (!fin.eof()) {
		fin >> i;
		set++;
	}
	set = set / 5;
	return set;
}

void add(int team, table* T, int jup) {
	int num, i;
	ifstream keep;
	if (T[team].first == NULL && T[team].last == NULL && T[team].three == NULL)
	{
		keep.open("input.txt");
		keep >> num;
		i = 0;
		while (!keep.eof())
		{
			if (num == team)
			{
				T[team].index = team;
				switch (i % 5)
				{
				case 0: // из пяти остаток при остатке дает только первый элемент
					T[team].first++;
					break;
				case 1: // а тут только второй 
					T[team].last++;
					break;
				default: // остальные вкладываем сюда 
					T[team].three++;
					break;
				}
			}
			keep >> num; // обновить уровень чтения
			i++;
		}
		if (num == team) // чтение последнего
		{
			T[team].index = team;
			switch (i % 5)
			{
			case 0:
				T[team].first++;
				break;
			case 1:
				T[team].last++;
				break;
			default:
				T[team].three++;
				break;
			}
		}

		T[team].first = (T[team].first / jup) * 100;
		T[team].last = (T[team].last / jup) * 100;
		T[team].three = (T[team].three / jup) * 100;
		// построчное деление на 100
		printf_s("Команда №%d: \n 1 - %2.f \n 2 - %2.f \n В тройке - %2.f\n", team, T[team].first, T[team].last, T[team].three);
		keep.close();
	}
}

void QuickSort(int l, int r, table* a) {
	int x, i, j;
	if (l < r) {
		x = a[(l + r) / 2].first;
		i = l; j = r;
		while (i <= j) {
			while (a[i].first < x) i++;
			while (a[j].first > x) j--;
			if (i <= j) { swap(a[i++].first, a[j--].first); swap(a[i++].first, a[j--].first); }
		}
		QuickSort(l, j, a);
		QuickSort(i, r, a);
	}
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	int i = 0, jup, team, num;
	const int N = 10; // размерность таблицы СТАТИЧЕСКАЯ

	ifstream in("input.txt");
	in >> team; // считываем номер первой команды
	jup = read_machine(); // чтение из файла (почисленно)

	table T[N]; // таблица с результатами

	while (!in.eof())
	{
		add(team, T, jup);
		in >> team; // считываем номер следующей команды в строке
	}
	add(team, T, jup);

	int temp, temp1, temp2, temp3;

	for (int i = 0; i < N - 1; i++) { // лютый костыль по сортировке ()

		for (int j = 0; j < N - i - 1; j++) // работает, не трожь 
			if (T[j].index < T[j + 1].index) { // НУЛИ В КОНЦЕ

					// меняем элементы местами
				temp = T[j].index;
				T[j].index = T[j + 1].index;
				T[j + 1].index = temp;
				// меняем элементы first
				temp1 = T[j].first;
				T[j].first = T[j + 1].first;
				T[j + 1].first = temp1;
				// меняем элементы last
				temp2 = T[j].last;
				T[j].last = T[j + 1].last;
				T[j + 1].last = temp2;
				// меняем элементы three 
				temp3 = T[j].three;
				T[j].three = T[j + 1].three;
				T[j + 1].three = temp3;
				cout << T[i].index << "  " << T[i].first << "  " << T[i].last << "  " << T[i].three << endl;

			}

		// bruh moment перестановок
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (T[i].first != 0 || T[i].last || 0 && T[i].three || 0)
			count++;
	}
	for (int i = 0; i < N; i++)
		if (T[i].first != 0 || T[i].last || 0 && T[i].three || 0)
			cout << "  " << T[i].index << "  " << T[i].first << "  " << T[i].last << "  " << T[i].three << endl;



	/// 5 ЛАБА CONFERDED
	cout << "Подсчет по проценту первых мест" << endl;
	QuickSort(0, N - 1, T);

	for (int i = 0; i < count; i++)
		cout << "  " << T[i].index << "  " << T[i].first << "  " << T[i].last << "  " << T[i].three << endl;

	return 0;
}
	