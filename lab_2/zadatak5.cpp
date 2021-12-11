#include <iostream>
#include <ctime>
#define MAX 10

using namespace std;

class Stog{
public:
    int polje[MAX] = {0};
    int top = -1;

    bool push(int element){


        if (top >= (MAX - 1)){
            return false;
        }

        polje[++top] = element;
        return true;
    }

    bool pop(int& element){
        if (top < 0){
            return false;
        }

        element = polje[top--];

        return true;
    }

    void print(){
        cout << "VRH -> ";
        for (int i = top; i > -1; i--){
            cout << polje[i] << " -> ";
        }
        cout << "KRAJ" << endl;

    }


};

int main(){
    Stog stog;
    srand(time(NULL));

    bool zastavica = true;
    for (int i = 0; i < 11; i++){
        int element = rand() % 10 + 1;
        zastavica = stog.push(element);

        if (zastavica == false){
            cout << "element: " << element << " nije upisan." << endl;
        }
    }

    stog.print();

    Stog pomocni;
    int element;
    while (stog.pop(element)){
        pomocni.push(element);
    }

    cout << "Pocetak ";
    while (pomocni.pop(element)){
        cout << element << " -> ";
    }
    cout << "Kraj";

    return 0;
}