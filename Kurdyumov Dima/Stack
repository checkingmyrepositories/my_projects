#include <iostream>
#include <cstdlib>



using namespace std;

struct comp{
    int Data;
    comp *next;
};

void s_push(comp **top, int D){
    comp *q;
    q = new comp();
    (*q).Data = D;
    if (top ==  NULL){
        *top = q;
    }
    else {
        (*q).next = *top;
        *top = q;
    }
};


void s_delete_key(comp **top, int N){
    comp *q = *top;
    comp *prev = NULL;
    while (q != NULL){
        if ((*q).Data == N){
            if (q == *top) {
                *top = (*q).next;
                delete q;
                (*q).next = NULL;
            }
            else {
                (*prev).next = (*q).next;
                delete q;
                (*q).next = NULL;
            }
        }
        prev = q;
        q = (*q).next;
    }
}

void s_print(comp *top){
    comp *q = top;
    while (q){
        cout << (*q).Data << ' ';
        q = (*q).next;
    }
}

int main(){
    comp * top = NULL;
    int size, x, y;
    cout << "Enter size of your stack: " << endl;
    cin >> size;
    cout << "Enter your numbers" << endl;
    for (int i = 0; i < size; i ++){
        cin >> x;
        s_push(&top, x);
    }
    cout << "Here are your numbers: ";
    s_print(top);
    cout << "What element do you want to delete? " << endl;
    cin >> y;
    s_delete_key(&top, y);
    s_print(top);
    return 0;
}
