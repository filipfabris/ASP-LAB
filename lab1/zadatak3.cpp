#include <iostream>

using namespace std;

double pi(int n){

    double result = 0;

    if (n == 1){
        return (double)4;
    }
    if (n % 2 == 0){
        result = 4 * (-1) * (1 / (2.0 * n - 1));
    }
    if (n % 2 == 1){
        result = 4 * (1 / (2.0 * n - 1));
    }

    return result + pi(n - 1);

}

int main(){

    int n = 2;
    double result = pi(n);

    cout << "Rezultat za n = " << n << " je " << result << endl;


    return 0;
}