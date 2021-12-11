#include <iostream>
#include <string>
using namespace std;

class Queue{
private:
    static const int MAX = 10;
    int queue[MAX] = {0};
    int read = 0;
    int write = 0;

public:
    bool enqueue(int item){
        if ((write + 1) % MAX == read)
            return false;


        queue[write] = item;
        write = (write + 1) % MAX;
        return true;
    }

    bool dequeue(int& item){
        if (read == write)
            return false;
        item = queue[read];
        read = (read + 1) % MAX;
        return true;
    }

    void print(){

        if (read == write){
            cout << "Polje je prazno" << endl;
            return;
        }

        cout << "READ -> ";
        int i = read;

        while (true){
            cout << queue[i] << " ";
            i = (i + 1) % MAX;
            if (i == write)
                break;
        }
        cout << "<- WRITE" << endl;
    }

    int count(){
        if (write > read)
            return write - read;
        else
            return write - read + MAX;
    }

};

int main(void){

    Queue q;
    int item;

    q.print();

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