#include <iostream>
#include <string>
using namespace std;

class Queue{

private:
    int size = 0;

    struct Atom{
        int data;
        Atom* next;
    };

    Atom* read = nullptr;
    Atom* write = nullptr;

public:
    bool enqueue(int data){

        Atom* newAtom = new (nothrow) Atom;
        if (newAtom == nullptr)
            return false;

        newAtom->data = data;
        newAtom->next = nullptr;

        if (write == nullptr){  //prvi element
            read = newAtom;
        }
        else{
            write->next = newAtom;
        }

        write = newAtom;
        size++;

        return true;
    }

    bool dequeue(int& data){

        if (read == nullptr)    //prazna
            return false;

        data = read->data;

        Atom* tbd = read;

        read = read->next;

        if (read == nullptr)    //sada je prazna lista nakon uklanjanja tog elementa
            write = nullptr;

        delete tbd;
        size--;

        return true;
    }

    int count(){
        return size;
    }

};

int main(){
    Queue q;
    int data;

    bool zastavica = true;
    for (int i = 0; i <= 10; i++){
        zastavica = q.enqueue(i);
        if (zastavica == false){
            cout << "Element: " << i << " nije upisan." << endl;
        }
    }

    int element;
    cout << "Pocetak -> ";
    while (q.dequeue(element)){
        cout << element << " -> ";
    }
    cout << "Kraj";


}