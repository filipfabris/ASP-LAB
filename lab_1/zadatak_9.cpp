#include<iostream>
#include <cmath>

using namespace std;

void f(int polje[], int n, int m){

    if (n == 0){
        return;
    }
    polje[n - 1] = pow(m, n - 1);  //n is size, we need index so n-1
    f(polje, n - 1, m);
    return;
}

int main(){
    int m, n;
    cout << "Enter number of elements n: ";
    cin >> n;
    cout << "Enter element for base m: ";
    cin >> m;
    int* array = new int[n];

    f(array, n, m);

    for (int i = 0; i < n; i++){
        printf("[%d] = %d\n", i, array[i]);
    }

    delete[] array;
    return 0;
}