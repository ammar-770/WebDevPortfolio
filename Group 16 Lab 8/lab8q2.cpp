#include <iostream>
#include "inputvalidate.cpp"
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    cout << "Enter size of unsorted array: ";
    int n = inputValidate_int();
    int arr[n];
    cout << "Enter elements of Array: ";
    for(int i = 0; i < n; i++){
    	cout << "Enter Element " << i << ": ";
        arr[i] = inputValidate_int();
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
