#include <iostream>
#include <fstream>
#include <string>
using namespace std;
    ifstream F;
    int number;
struct Queue { int x; Queue *Tail, *Head, *Next;}; // объявление структуры
void Push(int x, Queue *&MyQueue){  // добавление элемента в очередь
    Queue *element = new Queue; 
    element->x = x; 
    element->Tail = NULL;
    if (MyQueue->Head == NULL)
        MyQueue->Head = MyQueue->Next = element;
    else{
        (MyQueue->Next)->Tail = element;
        MyQueue->Next = element;
    }
}
void Show(Queue *MyQueue){ // функция вывода списка в файл 
 
    ofstream fout ("output.txt", ios_base::app);
    Queue *temp = MyQueue->Head; 
    while (temp != NULL){ 
        fout << temp->x << " "; 
        temp = temp->Tail; 
    }
        fout << endl; 
}
void ClearQueue(Queue *MyQueue){ // функция удаления из памяти
    while (MyQueue->Head != NULL){ 
 
        Queue *temp = MyQueue->Head->Tail;
        delete MyQueue->Head; 
        MyQueue->Head = temp; 
    }
}
void Pop(Queue *MyQueue){ // функция удаления элемента  
    if (MyQueue->Head != NULL){ 
        Queue *temp = MyQueue->Head->Tail; 
        MyQueue->Head = temp; 
    }
 
}
void CreateQueue(Queue *MyQueue){ // ввод из файла
    ifstream fin("input.txt");
    Queue *element = new Queue;
    while (!fin.eof()){
        fin >> number;
        Push(number, MyQueue); 
    } 
}
void DeleteNegative(Queue *MyQueue){ // удаление определенных элементов
    Queue *temp = MyQueue->Head; 
    while (temp != NULL){
        temp = temp->Tail;
    }
    temp = MyQueue->Head;
    Pop(MyQueue);
}
void AddNegative (int i, Queue *MyQueue) { // добавление определенных элементов
    int count=0;
    Queue *temp = MyQueue->Head; 
    while (temp != NULL){
        count++;
        temp = temp->Tail;
    }
    temp = MyQueue->Head;
    Push(i, MyQueue);
    temp = temp->Tail;
}
void Checkman(Queue *MyQueue){ // проверка на пустоту
    int count=0;
    Queue *temp = MyQueue->Head;
    while (temp != NULL){
        count++;
        temp = temp->Tail;
    }
    temp = MyQueue->Head;
 
    for (int j = 0; j < count; j++){
    if (temp->x = 0) {continue;}
    else {cout << "Не пуст!" << endl;break;}
    }
}
int main(){
    Queue *MyQueue = new Queue; 
    CreateQueue(MyQueue); 
    cout << "Проверили на пустоту" << endl;
    Checkman(MyQueue);
    cout << "Создали список" << endl;
    Show(MyQueue); 
    DeleteNegative(MyQueue);
    cout << "Удалили элемент" << endl;  
    Show(MyQueue);
    AddNegative(42, MyQueue);
    cout << "Добавили элемент" << endl;
    Show(MyQueue);
    ClearQueue(MyQueue);
    delete MyQueue->Head;
    delete MyQueue;
    cout << "Память очищена" << endl;
}