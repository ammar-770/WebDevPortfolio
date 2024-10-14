/*
DSAA LAB 2
29 OCT 2023

2. Create a Person class which has following attributes:
First Name 
Last Name 
Birth Year 
Birth Month 
Birth Date 
Develop C++ solution such that day month and year are taken as input for N persons and 
perform Sorting based on year, month and day using Selection Sort. 

*/

#include<iostream>
#include "inputvalidate.cpp"
#include<vector>
using namespace std;

class Person{
    string firstName;
    string lastName;
    int birthYear;
    int birthMonth;
    int birthDate;

    public:
    Person(string f, string l, int y, int m, int d){
        setFirstName(f);
        setLastName(l);
        setBirthYear(y);
        setBirthMonth(m);
        setBirthDate(d);
    }

    Person(const Person& obj){
        setFirstName( obj.getFirstName() );
        setLastName( obj.getLastName() );
        setBirthYear( obj.getBirthYear() );
        setBirthMonth( obj.getBirthMonth() );
        setBirthDate( obj.getBirthDate() );
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    int getBirthYear() const {
        return birthYear;
    }

    int getBirthMonth() const {
        return birthMonth;
    }

    int getBirthDate() const {
        return birthDate;
    }

    void setFirstName(string fn){
        firstName = fn;
    }

    void setLastName(string ln){
        lastName = ln;
    }

    void setBirthDate(int bd){
        birthDate = bd;
    }

    void setBirthMonth(int bm){
        birthMonth = bm;
    }

    void setBirthYear(int by){
        birthYear = by;
    }

    ~Person(){

    }

};

void swapIntElementsPerson(int i, int j, vector<Person> &obj){
    // *a = *a + *b;
    // *b = *a - *b;
    // *a = *a - *b;
    obj.at(i).setBirthDate( obj.at(i).getBirthDate() + obj.at(j).getBirthDate() );
    obj.at(j).setBirthDate( obj.at(i).getBirthDate() - obj.at(j).getBirthDate() );
    obj.at(i).setBirthDate( obj.at(i).getBirthDate() - obj.at(j).getBirthDate() );

    obj.at(i).setBirthMonth( obj.at(i).getBirthMonth() + obj.at(j).getBirthMonth() );
    obj.at(j).setBirthMonth( obj.at(i).getBirthMonth() - obj.at(j).getBirthMonth() );
    obj.at(i).setBirthMonth( obj.at(i).getBirthMonth() - obj.at(j).getBirthMonth() );

    obj.at(i).setBirthYear( obj.at(i).getBirthYear() + obj.at(j).getBirthYear() );
    obj.at(j).setBirthYear( obj.at(i).getBirthYear() - obj.at(j).getBirthYear() );
    obj.at(i).setBirthYear( obj.at(i).getBirthYear() - obj.at(j).getBirthYear() );
}

void swapVectors(int i, int j, vector<Person> &obj){

    string fn, ln;
    
    fn = obj.at(i).getFirstName();
    obj.at(i).setFirstName( obj.at(j).getFirstName() );
    obj.at(j).setFirstName( fn );
    ln = obj.at(i).getLastName();
    obj.at(i).setLastName( obj.at(j).getLastName() );
    obj.at(j).setLastName( ln );

    swapIntElementsPerson(i, j, obj);
}

void bubbleSortPersonClass(vector<Person> &obj){
    for(int i = 0; i < obj.size() - 1; i++){
        for(int j = 0; j < obj.size() - 1; j++){
            
            if(obj.at(j).getBirthYear() > obj.at(j+1).getBirthYear()){
                swapVectors(j, j+1, obj);
            }
                
            if((obj.at(j).getBirthYear() == obj.at(j+1).getBirthYear()) && 
               (obj.at(j).getBirthMonth() > obj.at(j+1).getBirthMonth()) ){
                    swapVectors(j, j+1, obj);
            }

            if((obj.at(j).getBirthYear() == obj.at(j+1).getBirthYear()) &&
               (obj.at(j).getBirthMonth() == obj.at(j+1).getBirthMonth()) &&
               (obj.at(j).getBirthDate() > obj.at(j+1).getBirthDate())){
                    swapVectors(j, j+1, obj);
            }
        
        }
    }
}

void printVectorPersonElements(vector<Person> &obj) {
    cout << "FirstName: \tLastName: \tDOB\n";
    for(int i = 0; i < obj.size(); i++){
        cout << obj.at(i).getFirstName() << "\t" << obj.at(i).getLastName() << "\t"
             << obj.at(i).getBirthDate() << "/" << obj.at(i).getBirthMonth() << "/"
             << obj.at(i).getBirthYear() << endl;
    }
}

int main(){
    Person  P1("Muhammad", "Qureshi", 1985, 2, 14);
    Person  P2("Ahmad", "Zafar", 1990, 5, 23);
    Person  P3("Ali", "Abu Bakar", 1978, 10, 9);
    Person  P4("Umar", "Farooq", 1995, 7, 30);
    Person  P5("Farooq", "Ahmad", 1972, 9, 22);
    Person  P6("Uzair", "Qureshi", 1972, 3, 17);
    Person  P7("Zafar", "Qureshi", 1972, 9, 21); 
    Person  P8("Ali", "Murtaza", 1998, 6, 11);
    Person  P9("Abu Bakar", "Siddique", 1997, 4, 2);
    Person  P10("Hasan", "Hussain", 1980, 11, 13);

    vector<Person> VectorPerson;
    VectorPerson.push_back(P1);
    VectorPerson.push_back(P2);
    VectorPerson.push_back(P3);
    VectorPerson.push_back(P4);
    VectorPerson.push_back(P5);
    VectorPerson.push_back(P6);
    VectorPerson.push_back(P7);
    VectorPerson.push_back(P8);
    VectorPerson.push_back(P9);
    VectorPerson.push_back(P10);

    bubbleSortPersonClass(VectorPerson);
    printVectorPersonElements(VectorPerson);

    return 0;
}
