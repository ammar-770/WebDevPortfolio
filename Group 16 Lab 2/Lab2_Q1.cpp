/*
DSAA LAB 2
29 OCT 2023

1. If the array is already sorted, we don’t want to continue with the comparisons. This can 
be achieved with modified bubble sort. Update the code in example 02 to have a 
modified bubble sort function. 
*/

#include <iostream>
#include "inputvalidate.cpp"
void modifiedBubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
               // If no two elements were swapped in the inner loop, the array is already sorted.
            if (!swapped) {
                std::cout << "No swap\n";
                  break;
        }
    }
}
  int main() {
  	cout << "Enter size of array: ";
  	int size = inputValidate_unsignInt();
  	int arr[size];
  	
  	cout << "Enter elements of array: ";
  	for(int i = 0; i < size; i++){
  		cout << "Element [" << i << "] : ";
  		arr[i] = inputValidate_unsignInt();
	  }
     modifiedBubbleSort(arr, size);
     std::cout << "Sorted array: ";
     for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
     std::cout << std::endl;
     return 0;
}
