#include <iostream>

using namespace std;

template<typename T> class List{

public:
    struct cvor{
        T data;
        cvor* next;
    };
    cvor* head;
    cvor* tail;


    List(){
        head = nullptr;
        tail = nullptr;
    }

    bool upis(T element){

        cvor* newCvor = new (nothrow) cvor;
        if (newCvor == nullptr) return false;

        newCvor->data = element;
        newCvor->next = nullptr;

        cvor** p;
        for (p = &head; *p && (*p)->data < element; p = &((*p)->next));

        newCvor->next = *p;
        *p = newCvor;

        if (!tail || newCvor->next == nullptr)
            tail = newCvor;

        return true;
    }

    void print(){
        cout << "HEAD -> ";
        for (auto curr = head; curr != nullptr; curr = curr->next)
            cout << curr->data << " -> ";
        cout << "NULLPTR" << endl;
    }

};

int main(){

    List<int> lista;
    lista.upis(4);
    lista.upis(3);
    lista.upis(9);
    lista.upis(1);

    lista.print();




    return 0;
}