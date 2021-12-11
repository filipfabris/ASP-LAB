#include <iostream>
#include <ctime>


using namespace std;

class Stog{
public:
    struct Atom{
        int data;
        Atom* next = nullptr;
    };

    Atom* head = nullptr;

    bool push(int data){
        Atom* newAtom = new (nothrow)Atom();
        if (newAtom == nullptr){
            return false;
        }

        newAtom->data = data;
        newAtom->next = head;
        head = newAtom;

        return true;
    }

    void print(){
        cout << "TOP -> ";
        for (Atom* i = head; i != nullptr; i = i->next)
            cout << i->data << " -> ";
        cout << "NULLPTR" << endl;
    }


};


int main(){
    Stog stog;
    srand(time(NULL));

    bool zastavica = true;
    for (int i = 0; i < 11; i++){
        int element = rand();
        zastavica = stog.push(element);

        if (zastavica == false){
            cout << "element: " << element << " nije upisan." << endl;
        }
    }

    stog.print();

    return 0;
}