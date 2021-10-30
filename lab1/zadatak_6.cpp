#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char* ostaviSlova(string ulaz){
    int size = 0;
    for (char c : ulaz){
        if (isalpha(c)){
            size++;
        }
    }

    char* niz = new char[size];

    int index = 0;
    for (char c : ulaz){
        if (isalpha(c)){
            niz[index] = c;
            index++;
        }
    }

    niz[index] = '\0';   // niz[index] = 0;
    return niz;
}


int main(){

    string ulaz = "asp12_i_ASP13";
    char* niz = ostaviSlova(ulaz);

    for (int i = 0; i < strlen(niz); i++){
        cout << niz[i];
    }

    delete[] niz;
    return 0;
}