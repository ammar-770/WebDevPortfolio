/*
DSAA LAB 3
11 NOV 2023

1. Implement a singly linked list class with the following functions: 
a) Insert a node at head 
b) Insert  a node at tail/end/back 
c) Insert a node at any position 
d) Delete a node by value 
e) Delete head 
f) Delete tail 
g) Delete a node at any position. 

*/

#include<iostream>
#include<cstdlib>
#include "inputvalidate.cpp"
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class LinkedList{
    struct Node* head;

    public:
    LinkedList(int newdata){
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node*));
        newNode->data = newdata;
        newNode->next = NULL;
        head = newNode;
    }

    void insert_at_head(int newdata){
        Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = newdata;
        newNode->next = head;
        head = newNode;
    }

    void insert_in_between(int newdata, int position){
    	if(position <= 0){
    		cout << "Invalid Input:" << endl;
    		return;
		}
        Node* newNode = (struct Node*) malloc (sizeof(struct Node));
        newNode->data = newdata;

        Node *temp = head;
        int i = 0;

        while(i != position-1){
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insert_in_end(int newdata){
        Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = newdata;
        newNode->next = NULL;
        Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insert_after_node(Node* prevNode, int newdata){
        Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = newdata;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    void delete_First_Node(){
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    void delete_End_Node(){
        Node *temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = NULL;
        free(temp2);
    }

    void delete_Middle_Node(int position){ // position is index, will not run on index = 0, as it will be the starting one
        if(position <= 0){
    		cout << "Invalid Input:" << endl;
    		return;
		}
		Node *temp = head;
        int i = 1;
        while(i != position-1){
            temp = temp->next;
            i++;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }

    void delete_Node_With_Given_Value_Which_Comes_FIrst(int value){
        Node *temp = head, *temp2 = head->next;
        while(temp2->data != value){        // loop for traversing
            if(temp->data == value){        // if given data is in 0 index i.e. head
                delete_First_Node();        // first index, call function delete first node
                free(temp);                 // free mempry 
                return;                     // end function
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        if(temp2->next == NULL){            // if given data is in last index
            temp->next = NULL;              // same as delete_end_node function
            free(temp2);                    // free memory
            return;                         // end function
        }
        temp->next = temp2->next;
        free(temp2);
    }

    struct Node* getNode(int index){
        Node *temp = head;
        for(int i = 0; i < index; i++)
        temp = temp->next;
        return temp;
    }

    void display(){
        Node* temp = head;
        cout << "Linked List: ";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
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
    	cout << "Press 9 for Exiting Program" << endl;
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
				cout << "Exiting Program..." << endl;
				break;
				
			default:
			cout << "Invalid input. Please read the instructions carefully" << endl;
			continue;	
		}
		if(a == '9'){
			break;
		}


	}

    return 0;
    
}
