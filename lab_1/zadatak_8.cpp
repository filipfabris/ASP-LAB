#include <iostream>
#include <string>

using namespace std;

class SanitizedString{
private:
    string str;
public:

    SanitizedString(string str){
        this->str = str;
        removeDuplicateWhitespace();
        removeNonAlphaChars();
    }


    void removeDuplicateWhitespace(){
        int size = str.length();
        char* dest = new char[size];
        int i = 0;
        int j = 0;

        while (i < size){
            if (str[i] == ' ' && str[i + 1] == ' '){
                i++;
                continue;
            }
            dest[j] = str[i];
            j++;
            i++;

        }
        dest[j] = '\0';

        //j is index, we are sending number of elements to copy so we need to put +1
        dest = resize(j + 1, dest);


        str = dest;
        delete[] dest;

    }

    char* resize(int newSize, char* arr){
        char* newArr = new char[newSize];

        memcpy(newArr, arr, newSize * sizeof(char));

        delete[] arr;
        return newArr;
    }

    void removeNonAlphaChars(){
        for (int i = 0; i < str.length(); i++){

            if (!(isalpha(str[i]) || str[i] == ' ')){
                str.erase(str.begin() + i);  //iterator erase
                i--;
            }
        }
    }


    string getString(){
        return str;
    }

    friend std::ostream& operator<<(std::ostream& os, const SanitizedString& str);

};

ostream& operator<<(ostream& os, const SanitizedString& str){
    os << str.str;
    return os;
}



int main(){
    string ulaz;
    cout << "Upisite znakovni niz: ";
    getline(cin, ulaz);

    SanitizedString output(ulaz); //Create an object of SanitizedString

    cout << "Pocetni string: " << ulaz << endl;
    cout << "Sanitizirani string: " << output << endl;

    return 0;
}