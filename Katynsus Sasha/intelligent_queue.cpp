#include <iostream>
#include <queue>

using namespace std;

int main(){
    int size, x, y;
    queue <int> q;
    cin >> size;
    for (int i = 0; i < size; i++){  //заполняем очередь
        cin >> x;
        q.push(x);
    }

    int number = 4;           // если хотим что-то найти
    int &start = q.front();                             //странный способ вывести всю очередь
    int &finish = q.back();
    for (auto now = &start; now != &finish+1; now++){
        if (*now == number){
            q.pop();
        }
        cout << *now << ' ';
    }

    // как надо делать
    while (!q.empty()){
        cout << q.front();
        q.pop();
    }
}