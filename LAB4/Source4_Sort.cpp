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
		printf_s("Команда №%d: \n 1 - %2.f \n 2 - %2.f \n В тройке - %2.f\n", team, T[team].first, T[team].last, T[team].three);

		// построчное деление на 100
		keep.close();
	}
}

int main() {
	const int N = 100; // размерность таблицы
	setlocale(LC_CTYPE, "Russian");
	table T[N]; // таблица с результатами
	ifstream in("input.txt");
	int i = 0, jup, team = 1, num, M = 5;
	jup = read_machine(); // чтение из файла (почисленно)
	
	while (!in.eof())
	{
		add(team, T, jup);
		team++;
		if (team == M)
		{
			break;
		}
		//in >> team; // считываем номер следующей команды в строке
	}
	add(team, T, jup);

	return 0;
}
