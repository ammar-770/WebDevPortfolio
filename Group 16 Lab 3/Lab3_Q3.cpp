/*
DSAA LAB 3
11 NOV 2023

3. Use the class of SLL created by you during the lab task 1. Do the following: 
a) Reverse the linked list 
b) Sort the contents of linked list 
c) Find the duplicates in the linked list

*/

#include <iostream>
#include <cstdlib>
#include "inputvalidate.cpp"
using namespace std;

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
    struct Node *head;

public:
    LinkedList(int newdata)
    {
        Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newdata;
        newNode->next = NULL;
        head = newNode;
    }

    void insert_at_head(int newdata)
    {
        Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newdata;
        newNode->next = head;
        head = newNode;
    }

    void insert_in_between(int newdata, int position)
    {
    	if(position <= 0){
    		cout << "Invalid Input:" << endl;
    		return;
		}
        Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newdata;

        Node *temp = head;
        int i = 0;

        while (i != position - 1)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insert_in_end(int newdata)
    {
        Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newdata;
        newNode->next = NULL;
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insert_after_node(Node *prevNode, int newdata)
    {
        Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newdata;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    void delete_First_Node()
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    void delete_End_Node()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = NULL;
        free(temp2);
    }

    void delete_Middle_Node(int position)
    { // position is index, will not run on index = 0, as it will be the starting one
        if(position <= 0){
    		cout << "Invalid Input:" << endl;
    		return;
		}
		Node *temp = head;
        int i = 1;
        while (i != position - 1)
        {
            temp = temp->next;
            i++;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }

    void delete_Node_With_Given_Value_Which_Comes_FIrst(int value)
    {
        Node *temp = head, *temp2 = head->next;
        while (temp2->data != value)
        { // loop for traversing
            if (temp->data == value)
            {                        // if given data is in 0 index i.e. head
                delete_First_Node(); // first index, call function delete first node
                free(temp);          // free mempry
                return;              // end function
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        if (temp2->next == NULL)
        {                      // if given data is in last index
            temp->next = NULL; // same as delete_end_node function
            free(temp2);       // free memory
            return;            // end function
        }
        temp->next = temp2->next;
        free(temp2);
    }

    struct Node *getNode(int index)
    {
        Node *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp;
    }

    void display()
    {
        Node *temp = head;
        cout << "Linked List: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseList()
    {
        Node *next = NULL, *prev = NULL;
        while (head != NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
    }

    void sortList()
    {
        Node *current = head, *next = head->next, *count = head;
        while (count != NULL)
        {
            next = head->next;
            current = head;
            while (next != NULL)
            {
                if (current->data > next->data)
                {
                    swap(current->data, next->data);
                }
                current = current->next;
                next = next->next;
            }
            count = count->next;
        }
    }

    void findDuplicates()
    {
        Node* temp = head, *temp2 = head, *temp3 = head;
        int count = 0, i;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        int duplicates[count];
        for(i = 0; i < count; i++)
        duplicates[i] = 0;

        i = 0;

        temp = head;
        while(temp != NULL){
            temp2 = head;
            while(temp2 != NULL){
                if((temp2->data == temp->data) && (temp != temp2)){
                    duplicates[i]++;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
            i++;
        }

        temp = head;
        for(int j = 0; j < count; j++){
            if(duplicates[j] != 0){
                cout << "THer is/are " << duplicates[j] << " duplicate of value " << temp->data << endl;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    cout << "Enter first element in LinkedList: ";
	int number = inputValidate_unsignInt(), posi;
    LinkedList L1(number);
    
    while(1){
    	cout << "Press 1 for inserting at Head" << endl;
    	cout << "Press 2 for inserting at End" << endl;
    	cout << "Press 3 for inserting in Between" << endl;
    	cout << "Press 4 for deleting at head" << endl;
    	cout << "Press 5 for deleting at end" << endl;
    	cout << "Press 6 for deleting at between" << endl;
    	cout << "Press 7 for deleting a given node value which comes first" << endl;
    	cout << "Press 8 for Displaying List" << endl;
    	cout << "Press 9 to convert into Reverse" << endl;
    	cout << "Note: Press 9 to end taking inputs" << endl;
		char a = inputValidate_char();
		
		switch(a){
			case '1':
				cout << "Insert At Head Operation: ";
				cout << "Enter Value:";
				number = inputValidate_unsignInt();
				L1.insert_at_head(number);
				break;
				
			case '2':
				cout << "Insert At End Operation: ";
				cout << "Enter Value:";
				number = inputValidate_unsignInt();
				L1.insert_in_end(number);
				break;
				
			case '3':
				cout << "Insert At Between Operation: ";
				cout << "Enter Value:";
				number = inputValidate_unsignInt();
				cout << "Enter position: ";
				posi = inputValidate_unsignInt();
				L1.insert_in_between(number, posi);
				break;
			
			case '4':
				cout << "Delete Head Operation: ";
				L1.delete_First_Node();
				break;
			
			case '5':
				cout << "Delete End Operation: ";
				L1.delete_End_Node();
				break;
				
			case '6':
				cout << "Delete in Between Operation: ";
				cout << "Enter index: ";
				number = inputValidate_unsignInt();
				L1.delete_Middle_Node(number);
				break;
				
			case '7':
				cout << "Delete a given node value which comes first - Operation: ";
				cout << "Enter Value:";
				number = inputValidate_unsignInt();
				L1.delete_Node_With_Given_Value_Which_Comes_FIrst(number);
				break;
				
			case '8':
				cout << "Display List Operation: ";
				L1.display();
				break;
				
			case '9':
				cout << "Reverse List Operation:" << endl;
				break;
				
			default:
			cout << "Invalid input. Please read the instructions carefully" << endl;
			continue;	
		}
		if(a == '9'){
			break;
		}


	}
    cout << "Input: ";
    L1.display();
    L1.reverseList();
    cout << "Reverse List: ";
    L1.display();
    L1.sortList();
    cout << "Sort List: ";
    L1.display();
    cout << "Find Duplicates:" << endl;
    L1.findDuplicates();

    return 0;
}
