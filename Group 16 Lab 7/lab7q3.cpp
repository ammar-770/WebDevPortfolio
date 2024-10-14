#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

void specialCharacter(char a){
    while(1){
        cout << "Enter Character: ";
        char b = inputValidate_char();
        if(a == b){
            return;
        }
        else{
            specialCharacter(a);
            cout << b << " ";
            return;
        }
    }
}

int main(){
    char a;
    cout << "Enter Special CHaracter: ";
    a = inputValidate_specialChar();
    specialCharacter(a);
    return 0;
}
