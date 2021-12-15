#include <iostream>
#include <string>

using namespace std;

class Vozilo{
private:
    string model;
    int godina;
public:
    Vozilo(string model, int godina){
        this->model = model;
        this->godina = godina;
    }
    Vozilo(){

    }

    bool operator<(Vozilo& other){
        if (model < other.model){
            return true;
        }
        if (model == other.model){
            if (godina > other.godina){
                return true;
            }
        }
        return false;
    }

    bool operator>(Vozilo& other){
        if (model > other.model){
            return true;
        }
        if (model == other.model){
            if (godina < other.godina){
                return true;
            }
        }
        return false;
    }

    friend ostream& operator<<(ostream& o, const Vozilo& X);


};

ostream& operator<<(ostream& o, const Vozilo& X){
    return o << "Model: " << X.model << " Godina: " << X.godina;
}

template <typename T>
void SwapM(T& prvi, T& drugi){
    T pomocni = prvi;
    prvi = drugi;
    drugi = pomocni;
}

template <typename T>
void SelectionSort(T A[], int n){
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (A[min] > A[j]){
                min = j;
            }
        }
        SwapM(A[min], A[i]);
    }
}

int main(){

    Vozilo v1("Peugeot", 1981);
    Vozilo v2("Peugeot", 1983);
    Vozilo v3("Renulet", 1967);
    Vozilo v4("Fiat", 1972);
    Vozilo v5("BMW", 1985);
    Vozilo v6("Merdesec", 1983);

    int n = 6;
    Vozilo polje[n] = {v1, v2, v3, v4, v5, v6};

    cout << "Prije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }
    cout << endl;

    SelectionSort<Vozilo>(polje, n);

    cout << "Poslije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }



    return 0;
}