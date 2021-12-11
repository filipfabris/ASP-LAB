#include <iostream>

using namespace std;

class Vozilo{
public:
    string model;
    int godina;

    Vozilo(string model, int godina){
        this->model = model;
        this->godina = godina;
    }

    friend bool operator<(const Vozilo& first, const Vozilo& second){
        if (first.model < second.model){
            return true;
        }
        if (first.model == second.model){
            if (first.godina < second.godina){
                return true;
            }
        }

        return false;
    }

    bool operator <(const Vozilo& other){
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

    bool operator >(const Vozilo& other){
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


};

void Zamijeni(Vozilo& prvi, Vozilo& drugi){
    Vozilo tmp = prvi;
    prvi = drugi;
    drugi = tmp;
}

template<typename T>
void SelectionSort(T A[], int n){
    for (int i = 0; i < n - 1; i++){
        int minIdx = i;
        for (int j = i; j < n; j++){
            if (A[j] < A[minIdx]){
                minIdx = j;
            }
        }
        Zamijeni(A[i], A[minIdx]);
    }
}


int main(){

    Vozilo v1("Peugeot", 1981);
    Vozilo v2("Peugeot", 1983);
    Vozilo v3("Renulet", 1967);
    Vozilo v4("Fiat", 1972);
    Vozilo v5("BMW", 1985);
    Vozilo v6("Merdesec", 1983);

    Vozilo vozila[6] = {v1, v2, v3, v4, v5, v6};

    cout << "Prije Sorta: " << endl;
    for (int i = 0; i < 6; i++){
        cout << vozila[i].model << " " << vozila[i].godina << endl;
    }

    SelectionSort(vozila, 6);
    cout << endl;

    cout << "Poslije sorta: " << endl;
    for (int i = 0; i < 6; i++){
        cout << vozila[i].model << " " << vozila[i].godina << endl;
    }

    return 0;
}