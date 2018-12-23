#include <cstdlib>
#include <iostream>
using namespace std;
struct comp { //Структура с именем comp
    int Data; //Кикие то данные(могут быть любими, к примеру можно написать int key; char Data; или добавить еще какие то данные)
    comp *next;//Указатель типа comp на следующий эелемент
};

void s_push(comp **top, int D) { //функция типа void(ничего не возвращает) которая принимает указатль на вершину стека и переменную которая будет записываться в ячейку
    comp *q; //Создаем новый указатель q, который приравниваем к вершине стека. По сути это и есть наш новый элемент
    q = new comp(); //выделяем память для нового элемента
    (*q).Data = D; //Записываем D в Data элемента
    if (top == NULL) { //Если вершины нет, тоесть стек пустой
        *top = q; //вершиной стека будет новый элемент
    }
    else //если стек не пустой
    {
        q->next = *top; //Проводим связь от нового элемента, к вершине. Тоесть кладем книжку на вершину стопки.
        *top = q; //Пишем, что вершиной теперь является новый элемент
    }
}

void s_delete_key(comp **top, int N) {//функция которая принимает вершину top и число которое нужно удалить
    comp *q = *top; //создаем указатель типа comp и приравниваем(ставим) его на вершину стека
    comp *prev = NULL;//создаем указатель на предыдуший элемент, с начала он будет пустым
    while (q != NULL) {//пока указатель q не путой, мы его будем проверять, если он все же пусть цикл заканчивается
        if (q->Data == N) {//если Data элемента равна числу, которое нам нужно удалить
            if (q == *top) {//если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
                *top = q->next;//передвигаем вершину на следующий элемент
                free(q);
                q->next=NULL;
                //q->Data=NULL;
            }
            else//если элемент последний или находится между двумя другими элементами
            {
                prev->next = q->next;//Проводим связь от предыдущего элемента к следующему
                free(q);//очищаем ячейку
                q->next=NULL;
                //q->Data=NULL;
            }
        }// если Data элемента НЕ равна числу, которое нам нужно удалить
        prev = q; //запоминаем текущую ячейку как предыдущую
        q = q->next;//перемещаем указатель q на следующий элемент
    }
}

void s_print(comp *top) { //принимает указатель на вершину стека
    comp *q = top; //устанавливаем q на вершину
    while (q) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
        cout << q->Data;//выводим на экран данные ячейки стека
        q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
    }
}

int main() {
    comp *top = NULL; //в начале программы у нас нет очереди, соответственно вершины нет, даем ей значение NULL
    //Дальше начинаем добавлять цифры от 1 до 5 в наш стек
    s_push(&top, 1);
    s_push(&top, 2);
    s_push(&top, 3);
    s_push(&top, 4);
    s_push(&top, 5);
    //после выполнения функций в стеке у нас будет 54321
    s_print(top);//выводим
    s_delete_key(&top, 4); //Затем удаляем 4, в стеке получается 5321
    cout << endl;
    s_print(top);//выводим
    return 0;
}

