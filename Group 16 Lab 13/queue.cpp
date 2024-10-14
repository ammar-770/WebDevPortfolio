#include<iostream>
using namespace std;

template <class NodeTemplate>
struct Node{
    NodeTemplate data;
    struct Node *next;
};

template <class QueueT>
class Queue{
    Node <QueueT>* front, *rear;
    int size, capacity;

    public:
    Queue(int capacity = 5){
        size = 0;
        front = rear = NULL;
        this->capacity = capacity;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

    void enqueue(QueueT data){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }
        Node <QueueT> *newNode = (struct Node <QueueT>*) malloc(sizeof(struct Node <QueueT>));
        newNode->data = data;
        newNode->next = NULL;
        if(front == NULL && rear == NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }
        Node <QueueT> *temp = front;
        front = front->next;
        free(temp);
        size--;
    }

    QueueT queueFront(){
        return front->data;
    }

    QueueT queueRear(){
        return rear->data;
    }

    void setCapacity(int c){
        capacity = c;
    }

    int getSize() const{
        return size;
    }

    int getCapacity() const{
        return capacity;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is empty"<< endl;
            return;
        }
        Node <QueueT> *temp = front;
        cout << "Queue: ";
        while(temp->next != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

//int main(){
//    Queue <int> Q1;
//    Q1.dequeue();
//    Q1.display();
//    Q1.enqueue(1);
//    Q1.display();
//    Q1.enqueue(2);
//    Q1.display();
//    Q1.enqueue(3);
//    Q1.display();
//    Q1.enqueue(4);
//    Q1.display();
//    Q1.enqueue(5);
//    Q1.display();
//    Q1.enqueue(6);
//    Q1.display();
//    Q1.dequeue();
//    Q1.display();
//    Q1.dequeue();
//    Q1.display();
//    Q1.dequeue();
//    Q1.display();
//    Q1.dequeue();
//    Q1.display();
//    Q1.dequeue();
//    Q1.display();
//    Q1.dequeue();
//    Q1.display();
//    Q1.dequeue();
//    Q1.display();
//    return 0;
//}
