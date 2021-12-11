#include <iostream>

using namespace std;

template<typename T> class List{

public:
    struct cvor{
        string string;
        cvor* next;
        cvor* prev;
    };
    cvor* head;
    cvor* tail;


    List(){
        head = nullptr;
        tail = nullptr;
    }

    bool upis(string element){

        cvor* newCvor = new (nothrow) cvor;
        if (newCvor == nullptr) return false;

        newCvor->string = element;
        newCvor->next = nullptr;
        newCvor->prev = tail;   //razlika izmedju dvostruko povezane liste

        if (tail == nullptr){
            head = newCvor;

        }
        else{
            tail->next = newCvor;
            tail = newCvor;
        }

        tail = newCvor;
        return true;
    }

    void print(){
        cout << "HEAD -> ";
        for (auto curr = head; curr != nullptr; curr = curr->next)
            cout << curr->string << " -> ";
        cout << "NULLPTR" << endl;
    }

};

int main(){

    List<int> lista;
    lista.upis("a");
    lista.upis("b");
    lista.upis("c");
    lista.upis("d");

    lista.print();




    return 0;
}