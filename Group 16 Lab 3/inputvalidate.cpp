#include<iostream>
using namespace std;

int inputValidate_signInt(){
	int i = 0;
	char sign = '+';
    int no = 0;
    while(1){
        char a;
        cin >> a;
        if(i++ == 0 && a == '-'){
        	sign = '-';
		}
        else if(a >= '0' && a <= '9'){
            no = no*10 + (int)(a - '0');
        }
        else if(a == '~'){
            break;
        }
        else{
            cout << "Error from Input Validation Organization" << endl;
            break;
        }
    }
    if(sign == '+')
    return no;
    if(sign == '-')
    return no * (-1);
}

int inputValidate_unsignInt(){
	int i = 0;
	char sign = '+';
    int no = 0;
    while(1){
        char a;
        cin >> a;
        if(a >= '0' && a <= '9'){
            no = no*10 + (int)(a - '0');
        }
        else if(a == '~'){
            break;
        }
        else{
            cout << "Error from Input Validation Organization" << endl;
            break;
        }
    }
    if(sign == '+')
    return no;
    if(sign == '-')
    return no * (-1);
}

float inputValidate_float(){
	int i = 0;
	char sign = '+';
    float fno = 0.0;
    while(1){
        char a;
        cin >> a;
        if(i++ == 0 && a == '-'){
        	sign = '-';
		}
        else if(a >= '0' && a <= '9'){
            fno = fno*10 + (int)(a - '0');
        }
        else if(a == '~'){
            a = (float)a;
            break;
        }
        else if(a == '.'){
            float i = 10.0;
            while(1){
                char b;
                cin >> b;
                if(b >= '0' && b <= '9'){
                    fno = fno + (int)(b - '0') / i;
                }
                else if(b == '~'){
                    break;
                }
                else{
                    cout << "Error from Input Validation Organization" << endl;
                    break;
                }
                i *= 10.00;
            }
            break;
        }
        else{
            cout << "Error from Input Validation Organization" << endl;
            break;
        }
    }
    if(sign == '+')
    return fno;
    if(sign == '-'){
    	return fno * (-1);
	}
}

char* inputValidate_charPtr_Alphabets(){
    char *alphabets = new char;
    int i = 0;
    while(1){
        char a;
        cin >> a;
        if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
            alphabets[i++] = a;
        }
        else if(a == '~'){
            alphabets[i] = '\0';
            break;
        }
        else{
            alphabets[i] = '\0';
            cout << "Error from Input Validation Organization" << endl;
            break;
        }
    }
    return alphabets;
}

char* inputValidate_charPtr_alphaNumeric(){
    char *alphabets = new char;
    int i = 0;
    while(1){
        char a;
        cin >> a;
        if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')){
            alphabets[i++] = a;
        }
        else if(a == '~'){
            alphabets[i] = '\0';
            break;
        }
        else{
            alphabets[i] = '\0';
            cout << "Error from Input Validation Organization" << endl;
            break;
        }
    }
    return alphabets;
}

char inputValidate_specialChar(){
    char specialCharacter;
    while(1){
        char a;
        cin >> a;
        if(!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a == '~'))){
            specialCharacter = a;
        }
        else if(a == '~'){
            break;
        }
        else{
            cout << "Error from Input Validation Organization" << endl;
            break;
        }
    }
    return specialCharacter;
}

char inputValidate_char(){
    char character;
    while(1){
        char a;
        cin >> a;
        if(a != '~'){
            character = a;
        }
        else if(a == '~'){
            break;
        }
        else{
            cout << "Error from Input Validation Organization" << endl;
            break;
        }
    }
    return character;
    
    
}

// int main(){
//     cout << "Enter your Number: ";
//     int no = inputValidate_int();
//     cout << "Your Number is " << no << endl;

//     float fno = inputValidate_float();
//     cout << "Enter Your FLoat Number: ";
//     cout << "Your FLoat Number is : " << fno << endl;

//     cout << "Enter Your string: ";
//     char* alphabets = new char;
//     alphabets = inputValidate_charPtr_Alphabets();
//     cout << "Your string is: " << alphabets << endl;
//     return 0;
// }
