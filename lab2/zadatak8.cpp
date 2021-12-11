#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Queue{

private:
    int size = 0;

    struct Atom{
        double data;
        Atom* next;
    };

    Atom* read = nullptr;
    Atom* write = nullptr;

public:
    bool dodaj(double broj){

        Atom* newAtom = new (nothrow) Atom;
        if (newAtom == nullptr)
            return false;

        newAtom->data = broj;
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

    bool poljeURed(int polje[], int n){
        if (n == 0){
            cout << "Svi elementi su uspijesno dodani" << endl;
            return true;
        }

        cout << "Dodaje se element: " << polje[n - 1] << endl;

        bool zastavica = true;
        zastavica = dodaj(polje[n - 1]);

        if (zastavica == false){
            cout << "Dodavanje elementa [" << polje[n - 1] << "] nije uspjelo. Prekid rada funkcije..." << endl;
            return false;
        }

        return poljeURed(polje, n - 1);
    }

};

int main(){
    Queue q;
    int data;

    srand(time(NULL));
    int polje[10] = {0};

    int el = 0;
    for (int i = 0; i < 10; i++){
        el = rand() % 10 + 1;
        polje[i] = el;
    }

    bool zastavica = true;
    zastavica = q.poljeURed(polje, 10);

    int element;
    cout << "Pocetak -> ";
    while (q.dequeue(element)){
        cout << element << " -> ";
    }
    cout << "Kraj";


}