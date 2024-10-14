#include <iostream>
#include <vector>
#include "inputvalidate.cpp"
using namespace std;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(vector<int> &hT, int i)
{
    int size = hT.size();
    int largest= i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest])
        largest= l;
    if (r < size && hT[r] > hT[largest])
        largest= r;
    if (largest!= i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}

void insert(vector<int> &hT, int newNum)
{
    int size = hT.size();
    if (size == 0)
        hT.push_back(newNum);
    else
    {
        hT.push_back(newNum);
        if (size == 1)
            heapify(hT, 0);
        else{
            for (int i = size / 2 - 1; i >= 0; i--)
                heapify(hT, i);
        }
    }
}

void deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
        {
            break;
        }
    }
    if (num != hT[i])
    {
        cout << "Element not exist in heap" << endl;
        return;
    }
    swap(&hT[i], &hT[size - 1]);
    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(hT, i);
}

int peekMax(vector<int> &hT) {
    if (hT.empty()) {
        cout << "Heap is empty." << endl;
        return -1; // Return some default value indicating an empty heap
    }
    return hT[0]; // Max element is at the root of the heap (index 0)
}

int extractMax(vector<int> &hT) {
    if (hT.empty()) {
        cout << "Heap is empty." << endl;
        return -1; // Return some default value indicating an empty heap
    }

    int maxValue = hT[0]; // Store the max value to return later
    int lastValue = hT.back(); // Get the last element in the heap
    hT[0] = lastValue; // Replace the root with the last element
    hT.pop_back(); // Remove the last element from the heap
    heapify(hT, 0); // Heapify the heap from the root to maintain the max-heap property
    return maxValue; // Return the extracted max value
}

void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

int main()
{
    cout << "LAB 11 Q2 ------------- MAX HEAP ----------------- " << endl;
    int element;
    vector<int> heapTree;
    
    while(1){
        cout << "Note: Please press \'~\' when you have completed entering the input" << endl;
        cout << "Select any option: " << endl;
        cout << "Press \'A\' to Insert Element in Max Heap" << endl;
        cout << "Press \'B\' to Delete Element in Max Heap" << endl;
        cout << "Press \'C\' to use peekMax() function in Max Heap" << endl;
        cout << "Press \'D\' to Extract Maximum Value in Max Heap" << endl;
        cout << "Press \'E\' to Display Elements of Max Heap" << endl;
        cout << "Press \'F\' to Exit Program" << endl;
        char c = inputValidate_char();

        switch(c){
            case 'A':
            cout << "Enter Element that you want to insert: ";
            element = inputValidate_int();
            insert(heapTree, element);
            break;

            case 'B':
            cout << "Enter Element that you want to delete: ";
            element = inputValidate_int();
            deleteNode(heapTree, element);
            break;

            case 'C':
            cout << "Peek Max is: " << peekMax(heapTree) << endl;
            break;

            case 'D':
            cout << "Maximum Value is extracted which was " << extractMax(heapTree) << endl;
            break;

            case 'E':
            cout << "Heap Elements: ";
            printArray(heapTree);
            break;

            case 'F':
            break;

            default:
            cout << "Invalid Input. Press Key again" << endl;
        }
        if(c == 'F'){
            break;
        }
    }
}