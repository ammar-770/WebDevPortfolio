/*
DSAA LAB 2
29 OCT 2023

4. Create a single class Sort, which will provide the user the option to choose between all 3
sorting techniques. The class should have following capabilities: 
 Take an array and a string (indicating the user choice for sorting technique) as 
input and perform the desired sorting. 
 Should allow the user to perform analysis on a randomly generated array. The 
analysis provides number of comparisons and number of swaps performed for 
each technique. 
 After printing all the results, the class should highlight the best and worst 
techniques. 
*/

#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

class Sort{
    int comparisons;

    public:
    void sortingTechnique(string sorting_technique, int array[], int size){
        comparisons = 0;
        if(sorting_technique == "Bubble Sort"){
            bubbleSort(array, size);
            cout << "Bubble Sort: ";
        }
        else if(sorting_technique == "Selection Sort"){
            selectionSort(array, size);
            cout << "Selection Sort: ";
        }
        else if(sorting_technique == "Insertion Sort"){
            insertionSort(array, size);
            cout << "Insertion Sort: ";
        }
        printArray(array, size);
        printComparisons();
    }

    void bubbleSort(int array[], int size){
        for(int i = 0; i < size-1; i++){
            comparisons++;
            for(int j = 0; j < size-i-1; j++){
                comparisons++;
                if(array[j] > array[j+1]){
                    swap(array[j], array[j+1]);
                }
                comparisons++;
            }
        }
    }

    void selectionSort(int array[], int size){
        int i, j, min_index;
        for(i = 0; i < size-1; i++){
            comparisons++;
            min_index = i;
            for(j = i+1; j < size; j++){
                comparisons++;
                if(array[j] < array[min_index]){
                    min_index = j;
                }
                comparisons++;
            }
            if(min_index != i){
                swap(&array[min_index], &array[i]);
            }
            comparisons++;
        }
    }

    void insertionSort(int array[], int size){
        int i, key, j;
        for(i = 1; i < size; i++){
            comparisons++;
            key = array[i];
            j = i - 1;
            while(j >= 0 && array[j] > key){
                array[j+1] = array[j];
                j = j - 1;
            }
            comparisons += 3;
            array[j+1] = key;
        }
    }

    void printArray(int array[], int size){
        cout << "Array Elements:" << endl;
        for(int i = 0; i < size; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void printComparisons(){
        cout << "Number of Comparisons: " << comparisons << endl;
    }
};

int main(){
	cout << "Enter size of array: ";
	int size = inputValidate_unsignInt();
    int array1[size], array2[size], array3[size];
    for(int i = 0; i < size; i++){
    	cout << "Enter elements for Array [" << i << "] : ";
    	array1[i] = inputValidate_unsignInt();
        array3[i] = array2[i] = array1[i];
    }
    Sort S1;
    cout << "Bubble Sort: ";
    S1.sortingTechnique("Bubble Sort", array1, size);
    cout << "Selection Sort: ";
    S1.sortingTechnique("Selection Sort", array2, size);
    cout << "Insertion Sort: ";
    S1.sortingTechnique("Insertion Sort", array3, size);
    return 0;
}
