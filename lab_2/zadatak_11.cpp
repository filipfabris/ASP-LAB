#include <iostream>
#include <string>

using namespace std;

class zapis{
private:
    int sifra;
    string naziv;

public:
    zapis(int sifra, string zapis){
        this->sifra = sifra;
        this->naziv = zapis;
    }
    zapis(){

    }

    bool operator<(zapis& other){
        if (sifra < other.sifra){
            return true;
        }
        return false;
    }

    bool operator>(zapis& other){
        if (sifra > other.sifra){
            return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& o, const zapis& x);
};

void SwapM(zapis& prvi, zapis& drugi){
    zapis pomocni = prvi;
    prvi = drugi;
    drugi = pomocni;
}

ostream& operator<<(ostream& o, const zapis& x){
    return o << "Sifra: " << x.sifra << " Naziv: " << x.naziv;
}

void obicanBubbleSort(zapis A[], int n, char smjer){
    if (smjer == 0){
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - 1; j++){
                if (A[j] > A[j + 1]){
                    SwapM(A[j], A[j + 1]);
                }
            }
        }
    }
    else{
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - 1; j++){
                if (A[j] < A[j + 1]){
                    SwapM(A[j], A[j + 1]);
                }
            }
        }
    }
}

int main(){

    zapis z1(5, "riba");
    zapis z2(3, "Brancin");
    zapis z3(9, "orada");
    zapis z4(2, "pomfrit");
    zapis z5(7, "spinat");

    int n = 5;
    zapis polje[5] = {z1, z2, z3, z4 ,z5};

    cout << "Prije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }
    cout << endl;

    obicanBubbleSort(polje, n, 1);

    cout << "Poslije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }



    return 0;
}