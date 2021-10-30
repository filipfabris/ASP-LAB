#include <iostream>
#include <cmath>

using namespace std;

double exp(double x, int n, int* fakt, double* xpot){
    if (n == 1){
        return 1;
    }
    xpot[n - 1] = pow(x, n - 1);
    return xpot[n - 1] / fakt[n - 1] + exp(x, n - 1, fakt, xpot);

}
double factorial(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}


int main(){
    int n = 5;
    double x = 1;
    int* fakt = new int[n];
    double* xpot = new double[n];
    double* A = new double[n];

    for (int i = 0; i < n; i++){
        fakt[i] = factorial(i);
        A[i] = exp(x, i + 1, fakt, xpot);
        printf("%2d. approximation e^(%g) = %20.6f\n", i + 1, x, A[i]);

    }



    delete[] fakt;
    delete[] xpot;
    delete[] A;

    return 0;
}