#include <iostream>
#include <fstream>
#include <locale.h>
#include <stdio.h>
using namespace std;

struct table {
	int team1 = 0;
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
			cout << num << " || " << team << endl;
			if (true) {
				if (num == team && num > T[team].team1)
				{

					switch (i % 5)
					{
					case 0: // из пяти остаток при остатке дает только первый элемент
						T[team].first++;			T[team].team1 = team;
						break;
					case 1: // а тут только второй 
						T[team].last++;			T[team].team1 = team;
						break;
					default: // остальные вкладываем сюда 
						T[team].three++;			T[team].team1 = team;
						break;
					}
				}
				keep >> num; // обновить уровень чтения
				i++;
			}
		}
		if (true) {
			if (num == team && num > T[team].team1) // чтение последнего
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
		}

		T[team].first = (T[team].first / jup) * 100;
		T[team].last = (T[team].last / jup) * 100;
		T[team].three = (T[team].three / jup) * 100;
		// построчное деление на 100
		printf_s("Команда №%d: \n 1 - %2.f \n 2 - %2.f \n В тройке - %2.f\n", team, T[team].first, T[team].last, T[team].three);
		keep.close();
	}
}

int main() {
	const int N = 100; // размерность таблицы
	setlocale(LC_CTYPE, "Russian");
	table T[N]; // таблица с результатами
	ifstream in("input.txt");
	int i = 0, jup, team;
	jup = read_machine(); // чтение из файла (почисленно)
	in >> team; // считываем номер первой команды
	while (!in.eof())
	{
		add(team, T, jup);
		in >> team; // считываем номер следующей команды в строке
	}
	add(team, T, jup);
	
	for (int i = 0; i < 25; i++)
	{

		cout << "--------------------------------------" << endl;
		cout << T[i].team1 << " ";
		cout << T[i].first << " ";
		cout << T[i].last << " ";
		cout << T[i].three << " " << endl;
		cout << "--------------------------------------" << endl;
	}
	// нужно создать еще одну таблицу, в которую будут перекладываться значения из первой. 
	return 0;
}