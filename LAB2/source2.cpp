#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
 ifstream F;
 ifstream F2; 
 
/*ОБЪЯВЛЕНИЕ СТРУКТУРЫ*/
struct Queue { int x; //информационный элемент
    Queue *Tail, *Head, *Next; //Голова очереди и указатель на следующий элемент
};
 
/*ФУНКЦИЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА В очередь */
void Push(int x, Queue *&MyQueue){ 
//Принимаем элемент очереди и указатель на очередь, при этом говорим, что принимаемый указатель будет сам по себе указателем
 
    element->x = x; //Записываем в поле x принимаемый в функцию элемент x
    element->Tail = NULL;
    if (MyQueue->Head == NULL)
        MyQueue->Head = MyQueue->Next = element;
    else{
        //Сдвигаем хвост на позицию вперед
        (MyQueue->Next)->Tail = element;
        MyQueue->Next = element;
    }
}
 
/*ФУНКЦИЯ ОТОБРАЖЕНИЯ очереди*/
void Show(Queue *MyQueue){ //Нужна только сама очередь
 
    ofstream fout ("output.txt", ios_base::app);
    //fout.open("output.txt");
    Queue *temp = MyQueue->Head; //Объявляем указатель и Указываем ему, что его позиция в голове очереди
    //с помощью цикла проходим по всему стеку
    while (temp != NULL){ //выходим при встрече с пустым полем
        fout << temp->x << " "; //Выводим в файл элемент очереди
        temp = temp->Tail; //Переходим к следующему элементу
    }
        fout << endl; 
}
 
/*ФУНКЦИЯ УДАЛЕНИЯ ОЧЕРЕДИ ИЗ ПАМЯТИ*/
void ClearQueue(Queue *MyQueue){
    while (MyQueue->Head != NULL){ //Пока по адресу не пусто
 
        Queue *temp = MyQueue->Head->Tail; //Временная переменная для хранения адреса следующего элемента
        delete MyQueue->Head; //Освобождаем адрес обозначающий начало
        MyQueue->Head = temp; //Меняем адрес на следующий
    }
}
 
/*ФУНКЦИЯ УБАВЛЕНИЯ ЭЛЕМЕНТА ИЗ очереди */
void Pop(Queue *MyQueue){   
    if (MyQueue->Head != NULL){ //Пока по адресу не пусто
        Queue *temp = MyQueue->Head->Tail; //Временная переменная для хранения адреса следующего элемента
        MyQueue->Head = temp; //Меняем адрес на следующий
    }
 
}
 
/*ЗАПОЛНЕНИЕ ИЗ ЦИКЛА*/
void CreateQueue(Queue *MyQueue){
    F.open("input.txt");
    Queue *element = new Queue;
    while (!fin.eof())
    {
        fin >> element;
        push(element, myQueue); // заглавное звено
    } 
    //ifstream fin("input.txt", ios_base::app);//Выделяем память для нового элемента
 
 
/*УДАЛЕНИЕ ЭЛЕМЕНТОВ"*/
void DeleteNegative(Queue *MyQueue){
    int count=0;
    Queue *temp = MyQueue->Head; //Объявляем указатель и Указываем ему, что его позиция в голове очереди
    //с помощью цикла проходим по всему стеку
    while (temp != NULL){
        temp = temp->Tail;
    }
    temp = MyQueue->Head;
    Pop(MyQueue);
}
 
/*ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ*/
void AddNegative (Queue *MyQueue) {
    int count=0;
    Queue *temp = MyQueue->Head; //Объявляем указатель и Указываем ему, что его позиция в голове очереди
    //с помощью цикла проходим по всему стеку
    while (temp != NULL){
        count++;
        temp = temp->Tail;
    }
    temp = MyQueue->Head;
    Push(42, MyQueue);
    temp = temp->Tail;
}
 
/*ПРОВЕРКА НА ПУСТОТУ*/
void Checkman(Queue *MyQueue){
    int count=0;
    Queue *temp = MyQueue->Head; //Объявляем указатель и Указываем ему, что его позиция в голове очереди
    //с помощью цикла проходим по всему стеку
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
    Queue *MyQueue = new Queue; //Выделяем память для очереди
 
    CreateQueue(MyQueue); //Инициализируем очередь
    cout << "Проверили на пустоту" << endl;
    Checkman(MyQueue);
 
    cout << "Создали список" << endl;
    Show(MyQueue); //Выводим очередь на экран
 
    DeleteNegative(MyQueue);
    cout << "Удалили элемент" << endl; // вопросик: удалять по индексу, или по значению? 
    Show(MyQueue);
 
    AddNegative(MyQueue);
    cout << "Добавили элемент" << endl;
    Show(MyQueue);
 
    ClearQueue(MyQueue); //Очищаем память.
    delete MyQueue->Head;
    delete MyQueue;
    cout << "Память очищена" << endl;
}