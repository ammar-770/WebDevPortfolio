/*
Group 16

DSAA LAB 4
13 NOV 2023

Question 1

1. Create a doubly link list and perform the mentioned tasks. 
a. Insert a new node at the end of the list. 
b. Insert a new node at the beginning of list. 
c. Insert a new node at given position. 
d. Delete any node. 
e. Print the complete doubly link list. 

*/

#include<iostream>
#include<cstdlib>
#include "inputvalidate.cpp"
using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

class DoublyLL{
    Node* head;

    public:
    DoublyLL(int data){
        Node* newNode = (struct Node*) malloc (sizeof(struct Node));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
    }

    void insert_at_head(int data){
        Node* newNode = (struct Node*) malloc (sizeof(struct Node));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insert_at_end(int data){
        Node* newNode = (struct Node*) malloc (sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }

    void insert_in_between(int data, int position){
    	if(position <= 0){
    		cout << "Invalid input";
    		return;
		}
        Node* newNode = (struct Node*) malloc (sizeof(struct Node));
        newNode->data = data;
        Node *temp = head;
        int i = 0;
        while(i != position-1){
            temp = temp->next;
            i++;
        }
        if(temp == NULL){
        	cout << "Invalid Input" << endl;
        	return;
		}
        newNode->next = temp->next;
        newNode->prev = temp;
        Node* temp2 = temp->next;
        temp2->prev = newNode;
        temp->next = newNode;
    }

    void delete_first_node(){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }

    void delete_last_node(){
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node *temp2 = temp->prev;
        temp->prev = NULL;
        temp2->next = NULL;
        free(temp);
    }

    void delete_in_between(int position){
    	if(position <= 0){
    		cout << "Invalid input" << endl;
    		return;
		}
        Node* temp = head;
        int i = 0;
        while(i != position-1){
            temp = temp->next;
            i++;
        }
        if(temp == NULL){
        	cout << "Invalid Input" << endl;
        	return;
		}
        Node* temp2 = temp->next;
        Node* temp3 = temp->next = temp2->next;
        temp3->prev = temp;
        free(temp2);
    }

    void doubleLLTraversal(){
        Node* temp = head, *temp2;
        cout << "Doubly Linked List Traversal: ";
        while(temp != NULL){
            cout << temp->data << " ";
            if(temp->next == NULL){
                temp2 = temp;
            }
            temp = temp->next;
        }
        while(temp2 != NULL){
            cout << temp2->data << " ";
            temp2 = temp2->prev;
        }
        cout << endl;
    }
};

bool linkedListIsEpmty(DoublyLL &D){
	
}

int main(){
	DoublyLL *D1;
	cout << "Doubly Linked List Program" << endl;
	cout << "Enter First Element in Doubly Linked List: ";
	int value = inputValidate_unsignInt();
	D1 = new DoublyLL(value);
	D1->doubleLLTraversal();
	while(1){
		cout << "Doubly Linked List Program" << endl;
		cout << "Press 1 to insert value at head" << endl;
		cout << "Press 2 to insert value in between" << endl;
		cout << "Press 3 to insert value at end" << endl;
		cout << "Press 4 to delete first value" << endl;
		cout << "Press 5 to delete last value" << endl;
		cout << "Press 6 to delete middle value" << endl;
		cout << "Press 7 to display Doubly Linked List" << endl;
		cout << "Press 8 to Exit Program" << endl;
		cout << "Press any key: " << endl;
		char key = inputValidate_char();
		if(!(key >= '0' && key <= '8')){
			cout << "Error from input validation organization" << endl;
			continue;
		}
		else{
			int value, position;
			switch(key){
				case '1':
					cout << "Enter value to insert at head: ";
					value = inputValidate_unsignInt();
					D1->insert_at_head(value);
					break;
					
				case '2':
					cout << "Enter value to insert in between: ";
					value = inputValidate_unsignInt();
					cout << "Enter position: ";
					position = inputValidate_unsignInt();
					D1->insert_in_between(value, position);
					break;
					
				case '3':
					cout << "Enter value to insert at end: ";
					value = inputValidate_unsignInt();
					D1->insert_at_end(value);
					break;
					
				case '4':
					D1->delete_first_node();
					break;
					
				case '5':
					D1->delete_last_node();
					break;
					
				case '6':
					cout << "Enter position: ";
					position = inputValidate_unsignInt();
					D1->delete_in_between(position);
					break;
					
				case '7':
					D1->doubleLLTraversal();
					break;
					
				case '8':
					cout << "Exiting program" << endl;
					return 0;
					
				default:
					cout << "Wrong Input" << endl;
					continue;
			}
		}
	}
    
    return 0;
}
