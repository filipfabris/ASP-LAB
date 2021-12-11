#include <iostream>

using namespace std;

class Osoba{
public:
    string ime;
    int godina;

    Osoba(string ime, int godina){
        this->ime = ime;
        this->godina = godina;
    }

    friend bool operator<(const Osoba& first, const Osoba& second){
        if (first.godina < second.godina){
            return true;
        }
        if (first.godina == second.godina){
            if (first.ime < second.ime){
                return true;
            }
        }

        return false;
    }

    bool operator <(const Osoba& other){
        if (godina < other.godina){
            return true;
        }
        if (godina == other.godina){
            if (ime < other.ime){
                return true;
            }
        }

        return false;
    }

    bool operator >(const Osoba& other){
        if (godina > other.godina){
            return true;
        }
        if (godina == other.godina){
            if (ime > other.ime){
                return true;
            }
        }

        return false;
    }


};

template<typename T>
void InsertionSort(T A[], int n){
    int i, j, tmp;
    for (i = 1; i < n; i++){
        T tmp = A[i];
        for (j = i; j >= 1 && A[j - 1] > tmp; j--){
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}


int main(){

    Osoba o1("Ana", 20);
    Osoba o2("Ivo", 9);
    Osoba o3("Marko", 9);
    Osoba o4("Lidija", 22);
    Osoba o5("Pero", 19);

    Osoba osobe[5] = {o1, o2,o3, o4, o5};

    cout << "Prije Sorta: " << endl;
    for (int i = 0; i < 5; i++){
        cout << osobe[i].ime << " " << osobe[i].godina << endl;
    }

    InsertionSort(osobe, 5);
    cout << endl;

    cout << "Poslije sorta: " << endl;
    for (int i = 0; i < 5; i++){
        cout << osobe[i].ime << osobe[i].godina << endl;
    }

    return 0;
}