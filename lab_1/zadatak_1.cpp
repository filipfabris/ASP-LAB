#include <iostream>

using namespace std;

void ispis(float polje[], int n){

    if (*polje < 0){
        cout << *polje << " ";
    }

    if (n > 1){
        ispis(++polje, --n);
    }

    return;

}

/*
    7     polje[0]
    7 - 1 polje[1]
    6 - 1 polje[2]
    5 - 1 polje[3]
    4 - 1 polje[4]
    3 - 1 polje[5]
    2 - 1 polje[6]
 */

int main(){

    int n = 7;
    float polje[7] = {0, -1.2, 2.5, 3.1, -4.17, 5.19, -6.91};
    cout << "Pocetak: " << endl;
    ispis(polje, n);

    return 0;
}