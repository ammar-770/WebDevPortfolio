#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

int factorial(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){
    cout << "Enter the number for which you want the factorial of: ";
    int number = inputValidate_int();
    cout << "Factorial of " << number << " = " << factorial(number) << endl;
    return 0;
}
