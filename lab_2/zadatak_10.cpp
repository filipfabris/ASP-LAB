#include <iostream>
#include <ctime>

using namespace std;

void swapM(int& prvi, int& drugi){
    int pomocni = prvi;
    prvi = drugi;
    drugi = pomocni;
}



int main(){

    srand(time(NULL));
    int n = 10;
    int polje[n] = {0};


    cout << "start : ";
    for (int k = 0; k < n; k++){
        polje[k] = rand() % 20;
        cout << polje[k] << " ";
    }
    cout << endl;

    for (int i = 0; i < n / 2; i++){

        int minIdx = i;
        int maxIdx = n - 1 - i;

        for (int j = i; j < n - i; j++){
            if (polje[minIdx] > polje[j]){
                minIdx = j;
            }
            if (polje[maxIdx] < polje[j]){
                maxIdx = j;
            }
        }

        swapM(polje[minIdx], polje[i]);
        if (i == maxIdx)
            maxIdx = minIdx;
        swapM(polje[maxIdx], polje[n - 1 - i]);

    }

    cout << "start : ";
    for (int k = 0; k < n; k++)
        cout << polje[k] << " ";
    cout << endl;

    return 0;
}