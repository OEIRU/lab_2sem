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

int read_machine() {
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
				case 0: // из пяти остатот при остатке дает только первый элемент
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
		// построчное деление на 100
		printf_s("Команда №%d: 1 - %f 2 - %f В тройке - %f\n", team, T[team].first, T[team].last, T[team].three);
		keep.close();
	}
}

// разве мы не должны считать это по командам\
	в плане на то, что n команда возьмет первое место поставило 3 человека\
	а команда под номером m пойдет на последнее место с таким-то процентом.

// Построить таблицу, содержащую проценты голосов, отданных командам -\
претендентам на первое место, \
командам - претендентам на последнее место \
и проценты голосов, отданных командам - претендентам на первую тройку.

// ПОДПРАВИЛ


int main() {
	const int N = 101; // размерность таблицы
	setlocale(LC_CTYPE, "Russian");
	table T[N]; // таблица с результатами
	ifstream in("input.txt");
	int i = 0, jup, team, num;
	jup = read_machine(); // чтение из файла (посимвольно)
	in >> team; // чтение первого элемента из машины, чтобы заложить его в while
	while (!in.eof())
	{
		add(team, T, jup); // номер команды закладываем в таблицу 
		in >> team; // тупо переносим таблицу, зачем?
	}
	add(team, T, jup);

	return 1;
}
