#include <iostream>
#include <cstdlib>
using namespace std;

struct stk{
    int elem;
    stk *sled;
};

void postroenie(stk **no, stk **ko){
    int el;
    stk *t;
    cin >> el;
    if (el != 0){
        t = new(stk);
        (*t).elem = el;
        (*t).sled = nullptr;
        *no = t;
        *ko = t;
        cin >> el;
        while (el!=0){
            t = new(stk);
            (*t).elem = el;
            (*t).sled = nullptr;
            (**ko).sled = t;
            *ko = t; cin >> el;
        }
    } else {
        t = nullptr; *no=t; *ko = t;}
}

/*void Deleting(stk **top, int N){
    stk *q = *top; //создаем указатель типа comp и приравниваем(ставим) его на вершину стека
    stk *prev = nullptr;//создаем указатель на предыдуший элемент, с начала он будет пустым
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
}*/

void print(stk *no, stk *ko){
    stk *q;
    q = no;
    while(q != nullptr){
        cout << (*q).elem << ' ';
        q = (*q).sled;
    }
    cout << endl;
}

int main() {
    stk *no = nullptr;
    stk *ko = nullptr;
    postroenie(&no, &ko);
    print(no, ko);



    return 0;
}


