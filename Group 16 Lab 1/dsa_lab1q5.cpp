/*
DSAA LAB 1
23 OCT 2023

5. Write a program that creates a 2D array of 5x5 values of type boolean. Suppose indices 
represent cities and that the value at row i, column j of a 2D array is true just in case i and 
j are direct neighbors and false otherwise. Use initializer list to instantiate and initialize 
your array to represent the following configuration: (* means “neighbors”) 

Write a method to check whether two cities have a common neighbor. For example, in the 
example above, 0 and 2, 3 and 4 are neighbors with 1 (so they have a common neighbor), 
whereas 0 and 1 have no common neighbors. 
*/

#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

int main(){
    bool neighbors[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if((i == 0 && j == 1) || (i == 1 && (j == 0 || j == 2)) ||
            ((i == 2) && (j == 1 || j == 4)) || ((i == 3) && (j == 1 || j == 2)) || 
            ((i == 4) && (j == 1 || j == 2 || j == 3))){
                neighbors[i][j] = true;
            }
            else{
                neighbors[i][j] = false;
            }
        }
    }

    int city1, city2;
    bool common = false;

    cout << "Enter 2 cities to search whether they have common neighbors or not? ";
    cout << "City 1: ";
    city1 = inputValidate_unsignInt();
    cout << "City 2: ";
    city2 = inputValidate_unsignInt();

    for(int i = 0; i < 5; i++){
        if(neighbors[city1][i] == true && neighbors[city2][i] == true){
            common = true;
             cout << "City " << city1 << " and City " << city2 << " have common neighbor(s) "<< i << endl;
           
        }
    }
    if (common==false){
    	cout << "City " << city1 << " and City " << city2 << "do not have common neighbor(s) " << endl;
	}
    
    return 0;
}
