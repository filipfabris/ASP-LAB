#include <iostream>
#include <math.h>

using namespace std;

//Version 1.
int zbrojiKvadrate(int polje[], int n){

    if (n < 0){
        return 0;
    }

    int korijen = sqrt(polje[n - 1]);

    if (korijen * korijen == polje[n - 1]){
        return zbrojiKvadrate(polje, n - 1) + polje[n - 1];
    }
    else{
        return zbrojiKvadrate(polje, n - 1);
    }
    return 0;
}

//Version 2.
int zbrojiKvadrate2(int polje[], int n){

    if (n < 0){
        return 0;
    }

    double korijen = sqrt(*polje);
    int ckorijen = korijen;


    if (ckorijen == korijen){
        return  *polje + zbrojiKvadrate2(++polje, --n);
    }
    else{
        return  zbrojiKvadrate2(++polje, --n);
    }

    return 0;
}

//Version 3.
int zbrojiKvadrate3(int polje[], int n){

    if (n < 0){
        return 0;
    }

    int korijen = sqrt(*polje);

    if (korijen * korijen == *polje){
        return  *polje + zbrojiKvadrate3(++polje, --n);
    }
    else{
        return  zbrojiKvadrate3(++polje, --n);
    }

    return 0;
}




int main(){

    int n = 5;
    int* polje = new int[5];
    //int* polje = (int*)malloc(sizeof(int) * n);

    int unos = 0;

    cout << "Unesite " << n << " brojeva" << endl;
    for (int i = 0; i < n; i++){
        scanf("%d", &unos);
        *(polje + i) = unos;
    }

    int rezultat = zbrojiKvadrate3(polje, n);
    cout << "rezultat je :" << rezultat << " " << endl;

    delete[] polje;
    return 0;
}