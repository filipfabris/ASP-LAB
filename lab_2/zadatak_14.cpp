#include <iostream>
#include <string>

using namespace std;

void swap(string& prvi, string& drugi){
    string pomocni = prvi;
    prvi = drugi;
    drugi = pomocni;
}

void BubbleSortPoboljsani(string A[], int n, char smjer){
    if (n <= 0){
        return;
    }

    if (smjer == 0){   //uzlazno sortiranje
        bool swapHappened = true;
        for (int i = 0; swapHappened == true; i++){
            swapHappened = false;
            for (int j = 0; j < n - 1 - i; j++){
                if (A[j] > A[j + 1]){
                    swap(A[j], A[j + 1]);
                    swapHappened = true;
                }
            }
        }
    }
    else{
        bool swapHappened = false;
        for (int i = 0; swapHappened == true; i++){
            swapHappened = false;
            for (int j = 0; j < n - 1 - i; j++){
                if (A[j] < A[j + 1])
                    swap(A[j], A[j + 1]);
                swapHappened = true;
            }
        }
    }
}
int main(){

    string polje[4];
    polje[0] = "Ivo";
    polje[1] = "Marko";
    polje[2] = "Juraj";
    polje[3] = "Pero";


    cout << "Prije sorta: " << endl;
    for (int i = 0; i < 4; i++){
        cout << polje[i] << endl;
    }

    char smjer = 0;
    BubbleSortPoboljsani(polje, 4, smjer);
    cout << endl;

    cout << "Poslije sorta: " << endl;
    for (int i = 0; i < 4; i++){
        cout << polje[i] << endl;
    }


    return 0;
}