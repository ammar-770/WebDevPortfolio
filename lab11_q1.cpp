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
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] < hT[smallest])
        smallest = l;
    if (r < size && hT[r] < hT[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&hT[i], &hT[smallest]);
        heapify(hT, smallest);
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

void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

int main()
{
    int element;
    cout << "LAB 11 Q1 ------------- MIN HEAP ----------------- " << endl;
    vector<int> heapTree;
    while(1){
        cout << "Note: Please press \'~\' when you have completed entering the input" << endl;
        cout << "Select any option: " << endl;
        cout << "Press \'A\' to Insert Element in Min Heap" << endl;
        cout << "Press \'B\' to Delete Element in Min Heap" << endl;
        cout << "Press \'C\' to Display Elements of Mib Heap" << endl;
        cout << "Press \'D\' to Exit Program" << endl;
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
            cout << "Heap Elements: ";
            printArray(heapTree);
            break;

            case 'D':
            break;

            default:
            cout << "Invalid Input. Press Key again" << endl;
        }
        if(c == 'D'){
            break;
        }
    }
}