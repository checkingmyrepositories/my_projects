#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int elem;
    node *sled;
};

void W_S(node **top, int &el){
    node *q;
    q = new(node);
    (*q).elem = el;
    (*q).sled = *top;
    *top = q;
}

void postroenie_not_full_keyboard(node **top){
    int el;
    cin >> el;
    while(el != 0){
        W_S(top, el);
        cin >> el;
    }
}

void postroenie_full_keyboard(node **top){
    int el;
    cin >> el;
    while (el!=0){
        node *t;
        t = new(node);
        (*t).elem = el;
        (*t).sled = *top;
        *top = t; cin >> el;
    }
}

void Deleting(node **top, int N){
    node *q = *top; //создаем указатель типа comp и приравниваем(ставим) его на вершину стека
    node *prev = nullptr;//создаем указатель на предыдуший элемент, с начала он будет пустым
    while (q != nullptr) {//пока указатель q не путой, мы его будем проверять, если он все же пусть цикл заканчивается
        if ((*q).elem == N) {//если Data элемента равна числу, которое нам нужно удалить
            if (q == *top) {//если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
                *top = (*q).sled;//передвигаем вершину на следующий элемент
                free(q);
                (*q).sled= nullptr;
                //q->Data=NULL;
            }
            else//если элемент последний или находится между двумя другими элементами
            {
                (*prev).sled = (*q).sled;//Проводим связь от предыдущего элемента к следующему
                free(q);//очищаем ячейку
                (*q).sled= nullptr;
                //q->Data=NULL;
            }
        }// если Data элемента НЕ равна числу, которое нам нужно удалить
        prev = q; //запоминаем текущую ячейку как предыдущую
        q = (*q).sled;//перемещаем указатель q на следующий элемент
    }
}

void print(node *top){
    node *q = top;
    while(q != nullptr){
        cout << (*q).elem << ' ';
        q = (*q).sled;
    }
    cout << endl;
}

int main() {
    node *top = nullptr;
    postroenie_not_full_keyboard(&top);
    print(top);
    int b;
    cin >> b;
    Deleting(&top,b);
    print(top);
    return 0;
}
