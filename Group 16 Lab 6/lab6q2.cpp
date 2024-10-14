#include<iostream>
#include<cstdlib>
using namespace std;

    template <class T>
    struct Node{
        T data;
        struct Node* next;
    };

template <class DT>
class QueueLinkedList {
    struct Node<DT> * front, *rear;
    int size, capacity;

    public:
    QueueLinkedList(int s){
        capacity = s;
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isFull(){
        return (size == capacity);
    }

    bool isEmpty(){
        return (front == NULL || size == 0);
    }

    void change_capacity(int s){
        capacity = s;
    }

    void enqueue(DT data){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }
        struct Node<DT>* newNode = (struct Node<DT>*) malloc (sizeof(struct Node<DT>));
        newNode->data = data;
        newNode->next = NULL;
        if(front == NULL && rear == NULL){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    DT dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        DT removedItem = front->data;
        front = front->next;
        size--;
    }

    DT peek(){
        return front->data;
    }

    DT last(){
        return rear->data;
    }

    void traversal(){
        cout << "Queue Linked List Traversal: ";
        struct Node<DT> *temp = front;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    QueueLinkedList <int> QL1(5);
    cout << "QL1(5)" << endl;
    QL1.enqueue(12);
    cout << "QL1.enqueue(12)" << endl;
    QL1.enqueue(23);
    cout << "QL1.enqueue(23)" << endl;
    QL1.traversal();
    QL1.enqueue(29);
    cout << "QL1.enqueue(29)" << endl;
    QL1.enqueue(45);
    cout << "QL1.enqueue(45)" << endl;
    QL1.traversal();
    int a = QL1.dequeue();
    cout << "QL1.dequeue(), a : " << a << endl;
    QL1.traversal();
    a = QL1.dequeue();
    cout << "QL1.dequeue(), a : " << a << endl;
    QL1.enqueue(65);
    cout << "QL1.enqueue(65)" << endl;
    QL1.enqueue(76);
    cout << "QL1.enqueue(76)" << endl;
    QL1.traversal();
    QL1.enqueue(86);
    cout << "QL1.enqueue(86)" << endl;
    QL1.enqueue(99);
    cout << "QL1.enqueue(99)" << endl;
    QL1.traversal();
    return 0;
}