#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

double raiseDoubleToPower(double number, int power, int i){
    if(i == power+1){
        return number;
    }
    else{
        i++;
        return raiseDoubleToPower(number*10, power, i);
    }
}

int main(){
    double doubleNumber;
    cout << "Enter Double Number: ";
    doubleNumber = inputValidate_float();
    int power;
    cout << "Enter it's power: ";
    power = inputValidate_int();
    cout << raiseDoubleToPower(doubleNumber, power, 1) << endl;
    return 0;
}
