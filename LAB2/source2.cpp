#include <iostream>
#include <fstream>
using namespace std;
 
/*ОБЪЯВЛЕНИЕ СТРУКТУРЫ*/
struct Queue { int x; //информационный элемент
    Queue *Tail, *Head, *Next; //Голова очереди и указатель на следующий элемент
};
 
/*ФУНКЦИЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА В очередь */
void Push(int x, Queue *&MyQueue){ 
//Принимаем элемент очереди и указатель на очередь, при этом говорим, что принимаемый указатель будет сам по себе указателем
    
    Queue *element = new Queue; //Выделяем память для нового элемента
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
 
    Queue *temp = MyQueue->Head; //Объявляем указатель и Указываем ему, что его позиция в голове очереди
    //с помощью цикла проходим по всему стеку
    while (temp != NULL){ //выходим при встрече с пустым полем
        cout << temp->x << " "; //Выводим на экран элемент очереди
        temp = temp->Tail; //Переходим к следующему элементу
    }
        cout << endl; 
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
    MyQueue->Head = NULL; //Во избежание ошибок инициализируем первый элемент
    for (int i = -2; i<10; i++) 
        Push(i, MyQueue); //Заносим данные в очередь
}
 
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