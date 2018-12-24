#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int elem;
    node *sled;
};

void postroenie(node **no, node **ko){
    int el;
    node *t;
    cin >> el;
    if (el != 0){
        t = new(node);
        (*t).elem = el;
        (*t).sled = nullptr;
        *no = t;
        *ko = t;
        cin >> el;
        while (el!=0){
            t = new(node);
            (*t).elem = el;
            (*t).sled = nullptr;
            (**ko).sled = t;
            *ko = t; cin >> el;
        }
    } else {
        t = nullptr; *no=t; *ko = t;}
}

void Adding(node **no, node **ko, int el){
    node *r; r = new(node);
    (*r).elem = el;
    (*r).sled = nullptr;
    if(*no != nullptr) {
        (**ko).sled = r;
        *ko = r;
    }   else {
        *no = r;
        *ko = r;
    }
}

void print(node *no){
    node *q;
    q = no;
    while(q != nullptr){
        cout << (*q).elem << ' ';
        q = (*q).sled;
    }
    cout << endl;
}

void Ydalenie(node **no, node **ko, int &klad){
    node *q;
    if (*no == nullptr) cout << "deleting impossible because queue is empty";
    else {
        klad = (**no).elem;
        q = *no;
        *no = (**no).sled;
        delete(q);
    }
    cout << "deleted item: " << klad << endl;
}

int main() {
    int start=0;
    node *no = nullptr;
    node *ko = nullptr;
    postroenie(&no, &ko);
    Adding(&no, &ko, 555);
    Ydalenie(&no, &ko, start);
    print(no);
    return 0;
}


