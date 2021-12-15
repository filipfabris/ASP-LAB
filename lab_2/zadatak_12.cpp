#include <iostream>
#include <string>

using namespace std;

class Osoba{
private:
    string ime;
    int godine;
public:
    Osoba(string ime, int godine){
        this->ime = ime;
        this->godine = godine;
    }
    Osoba(){

    }

    bool operator<(Osoba& other){
        if (godine < other.godine){
            return true;
        }
        if (godine == other.godine){
            if (ime < other.ime){
                return true;
            }
        }
        return false;
    }

    bool operator>(Osoba& other){
        if (godine > other.godine){
            return true;
        }
        if (godine == other.godine){
            if (ime > other.ime){
                return true;
            }
        }
        return false;
    }

    friend ostream& operator<<(ostream& o, const Osoba& x);



};
ostream& operator<<(ostream& o, const Osoba& x){
    return o << "Godine: " << x.godine << " Ime: " << x.ime;
}

template <typename T>
void InsertionSort(T A[], int n){
    int j;
    for (int i = 1; i < n; i++){
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

    int n = 5;
    Osoba polje[5] = {o1, o2, o3, o4, o5};

    cout << "Prije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }
    cout << endl;

    InsertionSort<Osoba>(polje, n);

    cout << "Poslije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }





    return 0;
}