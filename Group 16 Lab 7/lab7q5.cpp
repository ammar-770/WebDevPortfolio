#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

void printsOddFrom1(int i, int n){
        if(i % 2 != 0){
            cout << i << " ";
        }
        if(i == n){
            cout << endl;
            return;
        }
        i++;
        printsOddFrom1(i, n);
}

void printsOddFromN(int n){
    if(n % 2 != 0){
        cout << n << " ";
    }
    if(n == 1){
        cout << endl;
        return;
    }
    n--;
    printsOddFromN(n);
}

int main(){
    cout << "Enter the number from 1 till where you want the odd numbers: ";
    int n = inputValidate_int();
    cout << "Odd Numbers from 1 till " << n << " are: ";
    printsOddFrom1(1, n);
    cout << "Odd Nos from " << n << " till 1 are: ";
    printsOddFromN(n);
    return 0;
}