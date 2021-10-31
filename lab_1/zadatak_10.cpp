#include <iostream>

using namespace std;

double f(double z, int k){
    if (k <= 0){
        return z;
    }
    return f(z, k - 1) * ((-1) * z * z) / ((2 * k + 1) * (2 * k));


}

int main(){
    double z = 0.5;
    int k;
    do{
        cout << "To stop function enter negative k: ";
        cin >> k;
        if (k < 0){
            return 0;
        }
        cout << "Result is: " << f(z, k) << endl;

    } while (true);

    return 0;
}