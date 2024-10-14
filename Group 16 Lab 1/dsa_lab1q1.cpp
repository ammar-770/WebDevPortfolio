/*
DSAA LAB 1
23 OCT 2023

1. Write a C++ code to copy data of a 2D array in a 1D array using Column Major Order. 
*/

#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

int main(){
	cout << "Enter rows of 2d Array";
	int row2d = inputValidate_unsignInt();
	cout << "Enter columns of 2d Array";
	int col2d = inputValidate_unsignInt();
	int array_2D[row2d][col2d];
	for(int i = 0; i < row2d; i++){
		for(int j = 0; j < col2d; j++){
			cout << "Enter value for [" << i << "] [" << j << "] :";
			array_2D[i][j] = inputValidate_unsignInt();
		}
	}
    
    int array1d[row2d * col2d];
    int count = 0;

    for(int i = 0; i < col2d; i++){
        for(int j = 0; j < row2d; j++){
            array1d[count++] = array_2D[j][i];
        }
    }

    cout << "\nElements of 2D Array: " << endl;
    for(int i = 0; i < row2d; i++){
        for(int j = 0; j < col2d; j++){
            cout << array_2D[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nElements of 1D Array using Column Major Order: ";
    for(int i = 0; i < (row2d*col2d); i++)
        cout << array1d[i] << " ";
    cout << endl << endl;
    return 0;
}
