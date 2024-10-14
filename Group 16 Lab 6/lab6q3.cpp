#include<iostream>
#include<cstdlib>
using namespace std;

template <class T>
class Queue{
    int front, rear, size;
    int capacity;
    T *array;

    public:
    Queue(int siz){
        capacity = siz;
        array = new T[capacity];
        front = -1;
        rear = -1;
        size = siz;
    }

    bool isFull(){
        return ((front == 0 && rear == capacity-1) || ((rear+1) % size == front));
    }

    bool isEmpty(){
        return (front == -1);
    }

    void insert(T data){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }
        else if(front == -1){
            front = 0;
            rear = 0;
            array[rear] = data;
        }
        else if(front != 0 && rear == capacity-1){
            rear = 0;
            array[rear] = data;
        }
        else{
            rear++;
            array[rear] = data;
        }
        size++;
    }

    T remove(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        T no = array[front];
        array[front] = -1;
        if(front == rear){
            front = -1;
        }
        else if(front == capacity - 1){
            front = 0;
        }
        else{
            front++;
        }
        size--;
    }

    T peek(){
        return array[front];
    }

    T last(){
        return array[rear];
    }

    void traversal(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Elements of Circular Queue: ";
        if(front <= rear){
            for(int i = front; i <= rear; i++){
                cout << array[i] << " ";
            }
        }
        else{
            for(int i = front; i < capacity; i++){
                cout << array[i] << " ";
            }
            for(int i = 0; i <= rear; i++){
                cout << array[i] << " ";
            }
        }
        cout << endl;
        cout << "Front: " << peek() << ", Rear: " << last() << endl;
    }
};

int main(){
    Queue <int>Q1(5);
    cout << "Q1(5)" << endl;
    Q1.insert(12);
    cout << "Q1.insert(12)" << endl;
    Q1.insert(23);
    cout << "Q1.insert(23)" << endl;
    Q1.traversal();
    Q1.insert(29);
    cout << "Q1.insert(29)" << endl;
    Q1.insert(45);
    cout << "Q1.insert(45)" << endl;
    Q1.traversal();
    int a = Q1.remove();
    cout << "Q1.remove(), a : " << a << endl;
    Q1.traversal();
    a = Q1.remove();
    cout << "Q1.remove(), a : " << a << endl;
    Q1.insert(65);
    cout << "Q1.insert(65)" << endl;
    Q1.insert(76);
    cout << "Q1.insert(76)" << endl;
    Q1.traversal();
    Q1.insert(86);
    cout << "Q1.insert(86)" << endl;
    Q1.insert(99);
    cout << "Q1.insert(99)" << endl;
    Q1.traversal();
    return 0;
}

// string inputValidateString(string abc){
//     string a;
//     for(int i = 0; abc[i] != '\0'; i++){
//         if((abc[i] >= 'A' && abc[i] <= 'Z') || (abc[i] >= 'a' && abc[i] <= 'z') || abc[i] == ' '){
//             a[i] = abc[i];
//         }
//         else{
//             return 0;
//         }
//     }
//     return a;
// }

// void inputValidateInt(char *abc){

// }

// void inputValidateFloat(char *abc){

// }

// void inputValidateChar(char *abc){

// }