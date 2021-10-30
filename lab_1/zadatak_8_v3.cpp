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
        for (int i = 1; i < str.size(); i++){
            if (str[i] == ' ' && str[i - 1] == ' '){
                str.erase(str.begin() + i);
                i--;
            }
        }
    }

    void removeNonAlphaChars(){
        for (int i = 0; i < str.length(); i++){

            if (!(isalpha(str[i]) || str[i] == ' ')){
                str.erase(str.begin() + i);  //iterator erase
                i--;
            }
        }
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