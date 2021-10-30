#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int* randomSquares(int polje[], int n){
    int* shuffleArray = new int[n];
    int index = 0;

    for (int i = 0; i < n; i++){
        shuffleArray[i] = polje[i] * polje[i];
    }

    int temp;
    for (int i = 0; i < n; i++){
        index = rand() % n;

        temp = shuffleArray[i];
        shuffleArray[i] = shuffleArray[index];
        shuffleArray[index] = temp;

    }

    return shuffleArray;
}



int main(){
    int n;
    cout << "Enter n to create array of n elements: ";
    cin >> n;
    cout << endl;

    int* array = new int[n];

    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    srand(time(NULL));
    int* randomSquaredArray = randomSquares(array, n);

    cout << "Randomized square array: ";
    cout << "[";
    for (int i = 0; i < n; i++){
        if (i == (n - 1)){
            cout << randomSquaredArray[i] << "]" << endl;
        }
        else{
            cout << randomSquaredArray[i] << ", ";
        }
    }

    delete[] array;
    delete[] randomSquaredArray;
    return 0;
}