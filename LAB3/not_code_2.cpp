// устаревший код устаревшего человека
#include <stdio.h>

struct btree{
    char elem;
    btree *left, *right;
};

struct dline{
    btree *elem;
    dline *next, *pred;
};

void add_elem(dline*b, btree *ss){
    dline *x;
    b = b->pred;
    x = new dline;
    x->elem = ss;
    x->pred = b;
    x->next = b->next;
    b->next->pred = x;
    b->next = x;
}

int pust(dline *b){
    if (b == b->next) 
        return 1;
    return 0;
}

int outline (dline *b, btree **ss){
    dline *r;
    r = b->next;
    *ss = r->elem;
    b->next = r->next;
    b->next->pred = b;
    delete r;
    return 1;
}

void New_line (dline **b){
    dline *k;
    FILE*fp;
    k = b;
    fp = open("rez1.txt", "a");
    do {
        fprintf(fp, "%c", b->next->elem);
        b = b->next;
    }
    while (b->next != k);
    fclose(fp);
}

// главный модуль
FILE *fp;
btree *build_tree(){
    char s;
    btree *d;
    fscanf (fp, "%c", &s);
    switch (s){
        case '(': {
            d = new btree;
            d->left = build_tree();
            d->right = build_tree();
            fscanf(fp, "%c", &s);
            return d;
        }
        case '0': return NULL;
        case ',': d-build_tree(); return d;  
    }
}

void main(){
    FILE *lk;
    int k, p, h, n = 0; h = 0;
    dline *st1, *st2;
    fp = fopen ("tree.txt", "r");
    lk = fopen ("rez.txt", "w");
    btree *a = build_tree();
    fscanf(fp, "%d", &k);
    New_line(&st1);
    New_line(&st2);
    add_elem(st2, a);
    while ((n != k) && (pust(st2) != 1)){
        st1 = st2; 
        New_line(&st2);
        while (pust(st1) == 0){
            p = outline (st1, &a);
            if (a -> left != NULL) 
                add_elem(st2, a -> left);
            if (a -> right != NULL) 
                add_elem(st2, a -> right);
        }
        n++;
    }
    if (k == n) {
        while (pust(st2) == 0){
            p = outline(st2, &a);
            n++;
        }
        fprintf(lk, "%d\n", h);
    }
    else fprintf(lk, "Уровня не существует\n");
    fclose(lk);
    fclose(fp);
}

// беды с типизацией