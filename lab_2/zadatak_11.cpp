#include <iostream>
#include <string>

using namespace std;

class Zapis{
public:
    int sifra;
    string naziv;

    Zapis(int sifra, string naziv){
        this->sifra = sifra;
        this->naziv = naziv;
    }

};

void swap(Zapis& prvi, Zapis& drugi){
    Zapis pomocni = prvi;
    prvi = drugi;
    drugi = pomocni;
}

void obcanBubbleSort(Zapis A[], int n, char smjer){
    if (n <= 0){
        return;
    }

    if (smjer == 0){   //uzlazno sortiranje
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - 1 - i; j++){
                if (A[j].sifra > A[j + 1].sifra)
                    swap(A[j], A[j + 1]);
            }
        }
    }
    else{
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - 1 - i; j++){
                if (A[j].sifra < A[j + 1].sifra)
                    swap(A[j], A[j + 1]);
            }
        }
    }
}
int main(){

    Zapis z1(2000, "Jelo1");
    Zapis z2(1000, "Jelo2");
    Zapis z3(8000, "Jelo2");
    Zapis z4(7000, "Jelo2");

    Zapis polje[4] = {z1, z2, z3, z4};

    cout << "Prije sorta: " << endl;
    for (int i = 0; i < 4; i++){
        cout << "Postanski broj: " << polje[i].sifra << " Mjesto: " << polje[i].naziv << endl;
    }

    char smjer = 1;
    obcanBubbleSort(polje, 4, smjer);
    cout << endl;

    cout << "Poslije sorta: " << endl;
    for (int i = 0; i < 4; i++){
        cout << "Postanski broj: " << polje[i].sifra << " Mjesto: " << polje[i].naziv << endl;
    }


    return 0;
}