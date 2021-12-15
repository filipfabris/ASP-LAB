#include <iostream>
#include <ctime>

using namespace std;

void swapM(int& prvi, int& drugi){
    int pomocni = prvi;
    prvi = drugi;
    drugi = pomocni;
}


void selection2Sort(int A[], int n, char smjer){

    if (smjer == 0){
        for (int i = 0; i < n / 2; i++){
            int min = i;
            int max = n - i - 1;
            for (int j = i; j < n - i; j++){
                if (A[min] > A[j]){
                    min = j;
                }
                if (A[max] < A[j]){
                    max = j;
                }
            }
            swapM(A[min], A[i]);
            if (i == max){
                max = min;
            }
            swapM(A[max], A[n - i - 1]);
        }
    }
    else{
        for (int i = 0; i < n / 2; i++){
            int max = i;
            int min = n - i - 1;
            for (int j = i; j < n - i; j++){
                if (A[max] < A[j]){
                    max = j;
                }
                if (A[min] > A[j]){
                    min = j;
                }
            }
            swapM(A[max], A[i]);
            if (i == min){
                min = max;
            }
            swapM(A[min], A[n - i - 1]);
        }
    }
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

    selection2Sort(polje, n, 1);

    cout << "poslije : ";
    for (int k = 0; k < n; k++){
        cout << polje[k] << " ";
    }
    cout << endl;


    return 0;
}