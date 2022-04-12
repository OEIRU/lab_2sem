#include "Header.h"

    


    struct tree* adde(char x, tree * derevo) {
        if (derevo == NULL) { 
            derevo = new tree;
            derevo->elem = x;  
            derevo->left = NULL;
            derevo->right = NULL;
        }
        else  if (x < derevo->elem)
            derevo->left = adde(x, derevo->left);
        else  
            derevo->right = adde(x, derevo->right);
            return(derevo);
    }






 
    list* init(tree* a)         //���������� � �������(���������������)
    {
        struct list* lst;
        // ��������� ������ ��� ������ ������
        lst = (struct list*)malloc(sizeof(struct list));
        lst->field = a;
        lst->ptr = NULL; // ��� ��������� ���� ������
        return(lst);
    }



     list* addelem(list* lst, tree* number)         //���������� � ������� (���������������)
    {
        struct list* temp, * p;
        temp = (struct list*)malloc(sizeof(list));
        p = lst->ptr; // ���������� ��������� �� ��������� ����
        lst->ptr = temp; // ���������� ���� ��������� �� �����������
        temp->field = number; // ���������� ���� ������ ������������ ����
        temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
        return(temp);
    }

    void initilisation(queue* q)            //������������ �������
    {
        q->frnt = NULL;
        q->rear = NULL;
    }

    void Add(queue* q, tree* x)              //���������� � �������
    {
        if ((q->rear == NULL) && (q->frnt == NULL)) {
            q->rear = init(x);
            q->frnt = q->rear;
        }
        else
            q->rear = addelem(q->rear, x);
    }
 
     tree* Delete(queue* q)                 // �������� ������ �������
    {
        struct list* temp;
        tree* x;
        if (Full(q) == 1) {
            printf("������� �����!\n\n");
            return 0;
        }
        x = q->frnt->field;
        temp = q->frnt;
        q->frnt = q->frnt->ptr;
        free(temp);
        return x;
    }

    bool Full(queue* q)                 //�������� �� ������������ �������
    {
        if (q->frnt == NULL)
            return 1;
        else
            return 0;
    }
    tree* getlast(queue* q)                 // ������ ������ �������
    {
        tree* x;
        x = q->frnt->field;
        return x;
    }


    int n = 0;
   int treeprintwide(queue* q, tree* d, int floor)                    // ����� ������ � ������
    {
       int sosed = 0, sosed_2 = 0;
        initilisation(q);
        if (d != NULL) {Add(q, d);
        do
            {
                d = getlast(q);
                cout << n; 
                if (d->elem != NULL) sosed++;
                    cout << d->elem;
                    if (d->left != NULL) { Add(q, d->left);                 n++; sosed_2 = sosed; sosed = 0; }
                    if (d->right != NULL) { Add(q, d->right);                 /*cout << n++; */ }
                    if (n > floor) { cout << endl;  cout << sosed_2; return 1; }
                    Delete(q);
        } while (q->frnt != NULL); cout << sosed_2;
        }         
    }   

   // ����� ���� �����, � ��  if (n != n) { cout << n; }
