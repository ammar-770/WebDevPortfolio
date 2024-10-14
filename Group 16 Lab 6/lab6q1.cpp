#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    unsigned capacity;
    int* array;

public:
    // Constructor to initialize the queue
    Queue(int siz) : capacity(siz), front(0), rear(-1), size(0) {
        array = new int[capacity];
    }

    // Function to insert an element into the queue
    void insert(int j) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert more elements." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = j;
        size++;
    }

    // Function to remove an element from the queue
    int remove() {
        if (isEmpty()) {
            cout << "Queue is empty. No elements to remove." << endl;
            return -1; // Assuming -1 denotes an empty queue
        }
        int removedItem = array[front];
        front = (front + 1) % capacity;
        size--;
        return removedItem;
    }

    // Function to peek the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No elements to peek." << endl;
            return -1; // Assuming -1 denotes an empty queue
        }
        return array[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to return the size of the queue
    int getSize() {
        return size;
    }

    // Destructor to free dynamically allocated memory
    ~Queue() {
        delete[] array;
    }
};

int main() {
    Queue myQueue(5); // Creating a queue of capacity 5

    myQueue.insert(10);
    myQueue.insert(20);
    myQueue.insert(30);

    cout << "Front element: " << myQueue.peek() << endl;
    cout << "Queue size: " << myQueue.getSize() << endl;

    myQueue.remove();
    cout << "Removed one element from the queue." << endl;

    cout << "Front element after removal: " << myQueue.peek() << endl;
    cout << "Queue size after removal: " << myQueue.getSize() << endl;

    return 0;
}
