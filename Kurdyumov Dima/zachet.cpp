#include <iostream>
#include <cstdlib>
using namespace std; //еобходимо было реализовать стек и очистить его

struct node{
    int elem;
    node *sled;
};

void postroenie(node **top){
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

void ochistka(node **top){
    while(*top != nullptr){
        //cout << *top << endl; //a lot of checks
        node *q = *top;
        //cout << (*q).sled << endl;
        *top = (*q).sled;
        cout << (*q).elem << " ";
        delete(q);
    }
}

int main(){
    node *top = nullptr;
    postroenie(&top);
    ochistka(&top);
    return 0;
}

