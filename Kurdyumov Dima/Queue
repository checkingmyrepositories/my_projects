#include <iostream>

using namespace std;

struct MyFIFO{
    int val;
    int size;
    MyFIFO *Head, *Tail, *Next;
    void Add(const int x);
    void Show();
    void Del();
};

void MyFIFO::Add(int x){
    static int count=0;
    MyFIFO *temp = new MyFIFO;
    Next = temp->Head;
    temp->val = x;
    if (Head != NULL){
        Tail->Next = temp;
        Tail = temp;
    } else Head = Tail = temp;
    count++;
    size = count;

}

void MyFIFO::Show(){
    MyFIFO *temp = Head;

    while (temp != Tail->Next){
        cout << temp->val << "   " << "\n";
        temp = temp->Next;

    }
}

void MyFIFO::Del(){

    MyFIFO *temp = new MyFIFO;
    int count=0;

    while (temp != Tail){
        temp = Head;                                //Нашли текущее начало очереди и запомнили адрес в сторонюю переменую
        Head = Head->Next;                          //Сместили фактическое начало на адрес следующего поступившего элемента
        cout << "Udalena swiaz s:  " << temp->val << "\n";           //Для наглядности
        delete temp;                                //Очистили связь
    }
    size = 0;                                       //Обозначили, что в очереди ноль элементов
}


int main(){
    MyFIFO Q1;                      //Объявили переменную типа нашей очереди FIFO (имя структуры)
    Q1.Head = NULL;                 //Обозначили что голова пустая, ибо очередь пуста (можно в конструкторе)
    Q1.Add(100);                    //Добавляем элементы
    Q1.Add(200);
    Q1.Add(300);
    Q1.Show();                      //Показываем нашу очередь
    Q1.Del();                       //Очищаем память
    cin.get();
    return 0;
}
