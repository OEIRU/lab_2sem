#pragma once
#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

namespace A { // глобальные переменные
	int count = 0;
	int floor_now = 1;
	int floor;
	int count_sosed = 0;
};

struct btree {
	char elem;
	btree* left, * right;
};

struct list {
	int frontir = 0;
	btree* field;
	struct list* ptr;
};

struct queue {
	struct list* frnt, * rear;
};

btree* build_tree(fstream* doc);
btree* getlast(queue* q);
void initilisation(queue* q);
list* init(btree* a);
list* addelem(list* lst, btree* number);
void Add(queue* q, btree* x);
btree* Delete(queue* q);
void print(queue* q, btree* head);