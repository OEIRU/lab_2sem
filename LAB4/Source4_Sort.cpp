#include <iostream>
#include <fstream>
#include <locale.h>
#include <stdio.h>
using namespace std;

struct table {
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

void add(int j, table* T, int jup) {
	int num, i;
	ifstream keep;
	if (T[j].first == NULL && T[j].last == NULL && T[j].three == NULL)
	{
		keep.open("input.txt");
		keep >> j;
		i = 0;
		while (!keep.eof())
		{

				switch (i % 5)
				{
				case 0: // из пяти остаток при остатке дает только первый элемент
					T[j].first++;
					break;
				case 1: // а тут только второй 
					T[j].last++;
					break;
				default: // остальные вкладываем сюда 
					T[j].three++;
					break;
				}

			keep >> j; // обновить уровень чтения
			i++;
		}
			switch (i % 5)
			{
			case 0:
				T[j].first++;
				break;
			case 1:
				T[j].last++;
				break;
			default:
				T[j].three++;
				break;
			}
			T[j].first = (T[j].first / jup) * 100;
			T[j].last = (T[j].last / jup) * 100;
			T[j].three = (T[j].three / jup) * 100;
		//printf_s("Команда №%d: \n 1 - %2.f \n 2 - %2.f \n В тройке - %2.f\n", j, T[j].first, T[j].last, T[j].three);

		keep.close();
	}
}

int main() {
	const int N = 100; // размерность таблицы
	setlocale(LC_CTYPE, "Russian");
	table T[N]; // таблица с результатами
	ifstream in("input.txt");
	int i = 0, jup, j, num, M = 10;
	cout << "Введите количество команд" << endl;
	jup = read_machine(); // чтение из файла (почисленно)
	for (int j = 0; j < M; j++) {
		in >> j; // считываем номер первой команды
		while (!in.eof())
		{
			add(j, T, jup);
			// построчное деление на 100

			printf_s("Команда №%d: \n 1 - %2.f \n 2 - %2.f \n В тройке - %2.f\n", j, T[j].first, T[j].last, T[j].three);

			in >> j; // считываем номер следующей команды в строке
		}
		add(j, T, jup);
	}
	return 0;
}
