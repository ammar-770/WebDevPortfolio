/*
DSAA LAB 2
29 OCT 2023

3. Given an array arr[ ] of length N consisting cost of N toys and an integer K the amount 
with you. The task is to find maximum number of toys you can buy with K amount. 
Test Case:
Input: N = 7, K = 50, arr[] = {1, 12, 5, 111, 200, 1000, 10} 
Output: 4 
Explanation: The costs of the toys. You can buy are 1, 12, 5 and 10. 

*/

#include <iostream>
#include "inputvalidate.cpp"
#include <algorithm>
using namespace std;
int maximumToys(int arr[], int N, int K) {
    sort(arr, arr + N); // Sort the array in ascending order
    int count = 0;
    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        if (totalCost + arr[i] <= K) {
            totalCost += arr[i];
            count++;
        } else {
            break; // If you can't afford the next toy, stop.
        }
    }
    return count;
}
int main() {
	cout << "Enter N: ";
    int N = inputValidate_unsignInt();
    cout << "Enter K: ";
    int K = inputValidate_unsignInt();
    int arr[N];
    for(int i = 0; i < N; i++){
    	cout << "Enter elements of array [" << i << "] : ";
    	arr[i] = inputValidate_unsignInt();
	}
    int result = maximumToys(arr, N, K);
    cout << "Maximum number of toys you can buy: " << result << endl;
    return 0;
}
