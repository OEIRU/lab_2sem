#include "stdio.h"
#include <locale.h>

struct btree
{
    int elem;
    btree *left, *right;
};

struct stack
{
    btree *elem;
    stack *next;
};

//Ввод дерева
btree *build_tree(FILE *A)
{
    char sym;
    btree *d;
    fscanf(A, "%c", &sym);
    switch (sym)
    {
    case '(':
    {
        d = new btree;
        fscanf(A, "%c", &sym);
        d->elem = sym;
        d->left = build_tree(A);
        d->right = build_tree(A);
        fscanf(A, "%c", &sym);
        return d;
    }
    case '0':
        return NULL;
    case ',':
        d = build_tree(A);
        break;
    }
}

//Вывод дерева
void print_btree(btree *d)
{
    if (d == NULL)
        return;
    if (d->left == NULL)
    {
        printf("%c", d->elem);
        return;
    }
    print_btree(d->left);
    printf("%c", d->elem);
    print_btree(d->right);
}

    btree *build_tree(FILE *A);

    
void main()
{
	btree *d;
	FILE *A;
	fopen(&A, "input.txt");
	d = build_tree(A);
	fclose(A);
	print_btree(d);

    // ходим в поисках смысла до определенного уровня.
}
