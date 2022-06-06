#include <iostream>
#include <fstream>
#include <locale.h>
#include <stdio.h>
using namespace std;

struct table {
	int index = NULL;
	float tmp = NULL; // к этой штуке нужно подвязать весь столбец first;
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
		// построчное деление на 100
		printf_s("Команда №%d: \n 1 - %2.f \n 2 - %2.f \n В тройке - %2.f\n", team, T[team].first, T[team].last, T[team].three);
		keep.close();
	}
}

void qs(table* s_arr, int f, int l) // таблица не входит(((
{
	if (f < l)
	{
		int left = f, right = l, middle = s_arr[(left + right) / 2].first;
		do
		{
			while (s_arr[left].first > middle) left++;
			while (s_arr[right].first < middle) right--;
			if (left <= right)
			{
				int tmp = s_arr[left].first;
				s_arr[left].first = s_arr[right].first;
				s_arr[right].first = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qs(s_arr, f, right);
		qs(s_arr, left, l);
	}
}

void ShellSort(int n, table* mass)
{
	int i, j, step;
	int tmp;
	for (step = n / 3; step > 0; step /= 3)
		for (i = step; i < n; i++)
		{
			tmp = mass[i].first;
			for (j = i; j >= step; j -= step)
			{
				if (tmp > mass[j - step].first) {
					mass[j].index = mass[j - step].index;
					mass[j].first = mass[j - step].first;
					mass[j].last = mass[j - step].last;
					// индексация не работает((((((
				}
				else
					break;
			}
			mass[j].first = tmp;
		}
}

/*
void pyramide (table* a, int i, int j) {
	int max = i;
	do {
		t = max; lt = 2 * t + 1; rt = 2 * (t + 1);
		if (lt =< j)
			if (a[i].first > a[i].first max (????)).....................................................................................................................
	}
}*/

int main() {
	const int N = 100; // размерность таблицы
	setlocale(LC_CTYPE, "Russian");
	table T[N]; // таблица с результатами
	table Z[N];
	ifstream in("input.txt");
	int i = 0, jup, team = 1, num, M = 10;
	jup = read_machine(); // чтение из файла (почисленно)

	while (!in.eof())
	{
		add(team, T, jup);
		team++;
		if (team == M)
		{
			break;
		}
	}
	add(team, T, jup);

	// за индекс отвечает сама строка таблицы
	for (int i = 0; i < 20; i++)
		cout << "  " << i << "  " << T[i].first << "  " << T[i].last << "  " << T[i].three << endl;
	// создать еще одну таблицу, в которой номер строки кочует в индекс
	int memo = 0;
	int count = 0;
	for (int i = 0; i < 10; i++){
		for (int j = memo; j <= 10; j++) {
			if (T[j].first != 0 || T[j].last != 0 || T[j].three != 0) {
				Z[i].index = j;
				Z[i].first = T[j].first;
				Z[i].last = T[j].last;
				Z[i].three = T[j].three;
				memo = j+1;
				count++;
				break;
			} 
		}
	}
	Z[count].index = 0; Z[count].first = 0; Z[count].last = 0; Z[count].three = 0; // обнуляем
	cout << "Новая таблица" << endl;
	for (int i = 0; i < count; i++)
		cout << "  " <<Z[i].index << "  " << Z[i].first << "  " << Z[i].last << "  " << Z[i].three << endl;
	// входные данные готовы, а теперь хоть на Марс.
	//qs(Z, 0, count);
	cout << "Сортировка Шелла" << endl;
	 ShellSort(count - 1, Z);
	for (int i = 0; i < count ; i++)
		cout << "  " << Z[i].index << "  " << Z[i].first << "  " << Z[i].last << "  " << Z[i].three << endl;
	// входные данные готовы, а теперь хоть на Марс.
	return 0;
}
