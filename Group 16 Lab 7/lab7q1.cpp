#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

void fibonacci(int a, int b, int i, int n){
    if(i == n){
        cout << endl;
        return;
    }
    if(i == 1)
    cout << a << " " << b << " ";
    else
    cout << b << " ";
    i++;
    fibonacci(b, a+b, i, n);
}

int main(){
    cout << "Enter n value till where you want the fibonacci series: ";
    int n = inputValidate_int();
    cout << "Your Fibonacci Series: ";
    fibonacci(0, 1, 1, n);
    return 0;
}