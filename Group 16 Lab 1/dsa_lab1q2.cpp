/*
DSAA LAB 1
23 OCT 2023

2. Write a program to calculate the CGPA of students of all subjects of a single semester. 
Assume all the courses have the same credit hour (let’s assume 3 credit hours). 

*/

#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

int main(){
    float **gpas;
    gpas = new float*[5];
    int creditHours = 3;
    float gpasMultCreditHours[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    float cgpa[5];
    int totalCredits = 0;
    int noOfCourses[5];

    for(int i = 0; i < 5; i++){
        int no;
        cout << "\nEnter Passed Courses of Student # " << i+1 << ": ";
        no = inputValidate_unsignInt();
        gpas[i] = new float[no];

        noOfCourses[i] = no;

        cout << "\nStudent # " << i+1 << ": " << endl;
        for(int j = 0; j < no; j++){
            cout << "Course # " << j+1 << ": ";
            gpas[i][j] = inputValidate_unsignInt();
            gpasMultCreditHours[i] += (gpas[i][j] * creditHours);
            totalCredits += 4 * creditHours;
        }

        cgpa[i] = (gpasMultCreditHours[i] / totalCredits) * 4.00;
    }

    for(int i = 0; i < 5; i++){
        cout << "\nStudent " << i+1 << ": ";
        for(int j = 0; j < noOfCourses[i]; j++){
            cout << gpas[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nCGPAs of Students: " << endl;
    for(int i = 0; i < 5; i++){
        cout << "\nStudent # " << i+1 << ": " << cgpa[i];
    }
    cout << endl;

    return 0;
}
