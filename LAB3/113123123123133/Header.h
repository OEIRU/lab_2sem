#pragma once
#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

//дерево
struct tree 
{
	int elem;
	struct tree* left, * right;
};

//очередь
struct list 
{  
	tree* field;
	struct list* ptr;
};
struct queue
{
	struct list* frnt, * rear;
};


void treeprintwide(queue* q, tree* d);
struct tree* adde(fstream* doc);
	struct list* init(tree* a);

void initilisation(struct queue* q);

struct list* addelem(list* lst, tree* a);

void Add(struct queue* q, tree* a);

tree* Delete(queue* q);

tree* getlast(struct queue* q);

bool Full(queue* q);