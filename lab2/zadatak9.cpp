#include <iostream>
#include <string>

using namespace std;

class Zapis{
public:
    int postanski_broj;
    string mjesto;

    Zapis(int postanski_broj, string mjesto){
        this->postanski_broj = postanski_broj;
        this->mjesto = mjesto;
    }

};

void swap(Zapis& prvi, Zapis& drugi){
    Zapis pomocni = prvi;
    prvi = drugi;
    drugi = pomocni;
}

void insertionSort(Zapis A[], int n, char smjer){
    if (n <= 0){
        return;
    }

    if (smjer == 0){   //uzlazno sortiranje
        for (int i = 0; i < n - 1; i++){
            int minIdx = i;
            for (int j = i + 1; j < n; j++){
                if (A[j].postanski_broj < A[minIdx].postanski_broj)
                    minIdx = j;
            }
            swap(A[i], A[minIdx]);
        }


    }
    else{
        for (int i = 0; i < n - 1; i++){
            int maxIdx = i;
            for (int j = i + 1; j < n; j++){
                if (A[j].postanski_broj > A[maxIdx].postanski_broj)
                    maxIdx = j;
            }
            swap(A[i], A[maxIdx]);
        }
    }
}

int main(){

    Zapis z1(52210, "Rovinj");
    Zapis z2(10001, "Zagreb");
    Zapis z3(21000, "Rijeka");
    Zapis z4(76321, "Zagorje");

    Zapis polje[4] = {z1, z2, z3, z4};

    cout << "Prije sorta: " << endl;
    for (int i = 0; i < 4; i++){
        cout << "Postanski broj: " << polje[i].postanski_broj << " Mjesto: " << polje[i].mjesto << endl;
    }

    char smjer = 1;
    insertionSort(polje, 4, smjer);
    cout << endl;

    cout << "Poslije sorta: " << endl;
    for (int i = 0; i < 4; i++){
        cout << "Postanski broj: " << polje[i].postanski_broj << " Mjesto: " << polje[i].mjesto << endl;
    }


    return 0;
}