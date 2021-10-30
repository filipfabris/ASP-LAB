#include <iostream>

using namespace std;

template <typename T>
int binarnoTrazi(T polje[], int n, T x){
    int left = 0;
    int right = n - 1;
    int index = -1;

    while (left <= right){
        int middle = (left + right) / 2;

        if (polje[middle] == x){
            index = middle;
            break;
        }

        if (polje[middle] < x){
            left = middle + 1;
        }

        if (polje[middle] > x){
            right = middle - 1;
        }

    }

    return index;
}

int main(){
    int n = 5;
    float x = 4.4;

    float* A = new float[n];

    cout << "Ispis polja:" << endl;
    cout << "[";

    for (int i = 0; i < n; i++){
        A[i] = i * 1.1;

        if (i == (n - 1))

            cout << A[i] << "]" << endl;
        else
            cout << A[i] << ", ";
    }

    int found;
    found = binarnoTrazi(A, n, x);

    if (found == -1)
        cout << "X is not found in an array." << endl;

    else
        cout << "X found in array at index:  " << found << endl;


    delete[] A;
    return 0;
}