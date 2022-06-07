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

void Delete(table* a, int L, int R, int* ri, int* rj) // в таблице а сортируемая часть от индекса L до индекса R
{
	table x;
	table c;
	x = a[(L + R) / 2]; // выбрали срединный элемент как делящий элемент
	int i = L, j = R;
	while (i <= j)
	{
		while (a[i].first < x.first) i++; // слева от х находим элемент >= х
		while (a[j].first > x.first) j--; // справа от х находим элемент <= х
		if (i <= j) // пока индексы не встретились
		{
			c = a[i]; a[i] = a[j]; a[j] = c; i++; j--;
		} // меняем местами ai и aj , и продолжаем просмотр
	}
	*ri = i; *rj = j; // возвращаем индексы, по которым поделилась таблица
}

void Quicksort(table* a, int L, int R) // в таблице а сортируемая часть от индекса L до индекса R
{
	table x;
	int i = L, j = R;
	float c;

	if (R - L > 3) // если элементов больше порогового значения
	{
		Delete(a, L, R, &i, &j); // делим часть таблицы от индекса L до индекса R на две части
		if (L < j) Quicksort(a, L, j); //если в левой части больше одного элемента, сортируем ее
		if (i < R) Quicksort(a, i, R); //если в правой части больше одного элемента, сортируем ее
	}
	else{
		int count = 10;
		{ for (i = 1; i < count; i++) // i – номер очередного элемента неупорядоченной части таблицы
		{
			x = a[i]; // сохранили очередной элемент неупорядоченной части таблицы в х
			c = a[i].first; // сохранили его ключ в с
			j = i - 1; // j – номер последнего элемента упорядоченной части таблицы

			while (j >= 0 && a[i].first > c) //пока не нашли место для элемента х
			{
				a[j+1] = a[j]; j = j - 1;
			} //сдвигаем элемент T.elemj
			a[j+1] = x;
		} //на освобожденное место ставим х
		}
	}
}

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
	for (int i = 0; i < 10; i++) {
		for (int j = memo; j <= 10; j++) {
			if (T[j].first != 0 || T[j].last != 0 || T[j].three != 0) {
				Z[i].index = j;
				Z[i].first = T[j].first;
				Z[i].last = T[j].last;
				Z[i].three = T[j].three;
				memo = j + 1;
				count++;
				break;
			}
		}
	}
	Z[count].index = 0; Z[count].first = 0; Z[count].last = 0; Z[count].three = 0; // обнуляем
	cout << "Новая таблица" << endl;
	for (int i = 0; i < count; i++)
		cout << "  " << Z[i].index << "  " << Z[i].first << "  " << Z[i].last << "  " << Z[i].three << endl;
	// входные данные готовы, а теперь хоть на Марс.
	//qs(Z, 0, count);
	// cout << "Сортировка Шелла" << endl;
	// ShellSort(count - 1, Z);
	cout << "A" << endl;
	
	i = 0;
	int s = 0;
	int h[10];
	h[s] = 1;
	int n = count, m, k, a, j;
	table x;
	while (h[s] <= n / 9) {
		s += 1;
		h[s] = 3 * h[s - 1] + 1;
	}

	for (m = s; m >= 0; m--) {
		for (k = 0; k < h[m]; k++) {
			i - h[m] + k;
			while (i <= n - 1) {
				x = Z[i]; j = i - h[m];
				while (j >= 0 && x.first > Z[j].first) {
					Z[j + h[m]] = Z[j];
					j = j - h[m];
				}
				Z[j + h[m]] = x; i += h[m];
			}
		}
	}
	
	for (int i = 0; i < count; i++)
		cout << "  " << Z[i].index << "  " << Z[i].first << "  " << Z[i].last << "  " << Z[i].three << endl;
	// входные данные готовы, а теперь хоть на Марс.

	cout << "A2" << endl;
	Quicksort(Z, 0, count);
	for (int i = 0; i < count; i++)
		cout << "  " << Z[i].index << "  " << Z[i].first << "  " << Z[i].last << "  " << Z[i].three << endl;
	// НА МАРС


	return 0;
}
