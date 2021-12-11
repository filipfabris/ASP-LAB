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

    void print(){
        cout << "VRH -> ";
        for (int i = top; i > -1; i--){
            cout << polje[i] << " -> ";
        }
        cout << "KRAJ";

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