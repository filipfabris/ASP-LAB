#include <iostream>
#include <string>

using namespace std;

class Zapis{
private:
    int broj;
    string ime;

public:
    Zapis(int broj, string ime){
        this->broj = broj;
        this->ime = ime;
    }

    Zapis(){

    }

    int getBroj(){
        return broj;
    }

    string getIme(){
        return ime;
    }

    bool operator<(Zapis& other){
        if (broj < other.broj){
            return true;
        }
        return false;
    }

    bool operator>(Zapis& other){
        if (broj > other.broj){
            return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& o, const Zapis& X);

};

void insertionSort(Zapis A[], int n, char smjer){

    int j;
    for (int i = 1; i < n; i++){
        Zapis tmp = A[i];
        for (j = i; j >= 1 && A[j - 1] > tmp; j--){
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}

ostream& operator<<(ostream& o, const Zapis& X){
    return o << "broj: " << X.broj << " ime: " << X.ime;
}

int main(){
    Zapis z1(52210, "Rovinj");
    Zapis z2(10000, "Zagreb");
    Zapis z3(52000, "Pula");
    Zapis z4(123232, "MB");
    Zapis z5(32123, "ZD");

    int n = 5;
    Zapis polje[n] = {z1, z2, z3, z4, z5};

    cout << "Prije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }
    cout << endl;

    insertionSort(polje, n, 0);

    cout << "Poslije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }

    return 0;
}