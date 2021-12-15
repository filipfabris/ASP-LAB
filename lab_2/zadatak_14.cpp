#include <iostream>
#include <string>

using namespace std;

void Zamijeni(string& prvi, string& drugi){
    string pomocni = prvi;
    prvi = drugi;
    drugi = pomocni;

}

void BubbleSortPoboljsani(string A[], int n, int smjer){
    bool zasavica = true;
    for (int i = 0; zasavica == true; i++){
        zasavica = false;
        for (int j = 0; j < n - 1; j++){
            if (A[j] > A[j + 1]){
                zasavica = true;
                Zamijeni(A[j], A[j + 1]);
            }
        }
    }

}

int main(){

    int n = 4;
    string* polje = new string[n];

    polje[0] = "Ivo";
    polje[1] = "Marko";
    polje[2] = "Juraj";
    polje[3] = "Pero";



    cout << "Prije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }
    cout << endl;


    BubbleSortPoboljsani(polje, n, 0);

    cout << "Poslije: " << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }


    return 0;
}