/*
DSAA LAB 1
23 OCT 2023

3. Suppose you are planning a picnic. You want to store the names of the students of your 
class who have submitted their contribution money. Write a program that uses jagged 
array to store the students’ names and then perform a search for your name. 

*/

#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

int main(){
    string name;
    int noOfStudents;
    cout << "Enter No of Students: ";
    noOfStudents = inputValidate_unsignInt();
    int namesLetters[noOfStudents];
    char **names;
    names = new char*[noOfStudents];
    // cin.ignore();

    for(int i = 0; i < noOfStudents; i++){
        cout << "Enter Name: ";
        name = inputValidate_charPtr_Alphabets();
        namesLetters[i] = name.length();
        names[i] = new char[namesLetters[i]];
        for(int j = 0; j < namesLetters[i]; j++){
            names[i][j] = name[j];
        }
    }

    cout << "Students in the List:";
    for(int i = 0; i < noOfStudents; i++){
        cout << "\n" << i+1 <<". ";
        for(int j = 0; j < namesLetters[i]; j++){
            cout << names[i][j];
        }
    }
    cout << endl;

    cout << "Write a name to search: ";
    name = inputValidate_charPtr_Alphabets();

    for(int i = 0; i < noOfStudents; i++){
        int count = 0;

        for(int j = 0; j < namesLetters[i]; j++){
            if(name[j] == names[i][j])
            count++;
        }
        if(count == namesLetters[i]){
            cout << "Entered Name is present in the list in index # " << i << "." << endl;
            break;
        }
    }

    return 0;
}
