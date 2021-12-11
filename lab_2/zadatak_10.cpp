#include <iostream>

using namespace std;

void selection2Sort(int A[], int n, char smjer){
    if (smjer == 0){
        for (int i = 0; i < n / 2; i++){
            int minIdx = i;
            int maxIdx = n - 1 - i;
            for (int j = i + 1; j < n - i; j++){
                if (A[minIdx] > A[j]){
                    minIdx = j;
                }
                else if (A[maxIdx] < A[j]){
                    maxIdx = j;
                }
            }

            if (maxIdx != minIdx){
                swap(A[minIdx], A[i]);
                swap(A[maxIdx], A[n - 1 - i]);
            }
            else{
                swap(A[minIdx], A[i]);

            }
        }
    }
    else{
        for (int i = 0; i < n / 2; i++){
            int maxIdx = i;
            int minIdx = n - 1 - i;
            for (int j = i + 1; j < n - i; j++){
                if (A[maxIdx] < A[j]){
                    maxIdx = j;
                }
                else if (A[minIdx] > A[j]){
                    minIdx = j;
                }
            }

            if (maxIdx != minIdx){
                swap(A[maxIdx], A[i]);
                swap(A[minIdx], A[n - 1 - i]);
            }
            else{
                swap(A[maxIdx], A[i]);

            }
        }

    }
}


int main(){

    int n = 8;
    int polje[n]{2,5,4,8,7,1,3,6};

    cout << "start : ";
    for (int k = 0; k < 8; k++)
        cout << polje[k] << " ";
    cout << endl;

    selection2Sort(polje, n, 1);


    cout << "start : ";
    for (int k = 0; k < 8; k++)
        cout << polje[k] << " ";
    cout << endl;

    return 0;
}