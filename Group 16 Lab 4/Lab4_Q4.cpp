/*
Group 16

DSAA LAB 4
13 NOV 2023

Question 4

4.  Create a circular link list and perform the mentioned tasks. 
a. Insert a new node at the end of the list. 
b. Insert a new node at the beginning of list. 
c. Insert a new node at given position. 
d. Delete any node. 
e. Print the complete circular link list.

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
    LinkedList(int data){
        Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
    }

    void insert_at_head(int data){
        Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insert_at_end(int data){
        Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insert_in_between(int data, int position){
        Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        Node *temp = head;
        int i = 0;
        while(i != position-1){
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insert_after_node(int data, struct Node* node){
        Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = node->next;
        node->next = newNode;
    }

    void delete_first_node(){
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    void delete_last_node(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = NULL;
        free(temp2);
    }

    void delete_middle_node(int position){
        Node* temp = head;
        int i = 0;
        while(i != position - 1){
            temp = temp->next;
            i++;
        }
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }

    void delete_given_value_node(int data){
        Node* temp = head, *temp2;
        while((temp->data != data) && (temp->next != NULL)){
            temp2 = temp;
            temp = temp->next;
        }
        if(temp->data == data){
            temp2->next = temp->next;
            free(temp);
        }
    }

    void singlyLinkedListTraversal(){
        Node* temp = head;
        cout << "Singly Linked List Traversal: ";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void circularLLConversion(){
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
    }

    void circularLinkedListTraversal(){
        Node *temp = head;
        cout << "Circular Linked List Traversal: ";
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }

    void CCinsert_at_head(int data){
        Node *newNode = (struct Node*)malloc (sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;
        Node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        head = newNode;
    }

    void CCinsert_at_end(int data){
        Node *newNode = (struct Node*)malloc (sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;
        Node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    void CCinsert_in_between(int data, int position){
        Node *newNode = (struct Node*) malloc (sizeof(struct Node));
        newNode->data = data;
        Node* temp = head;
        for(int i = 0; i < position-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void CCinsert_after_node(int data, struct Node* node){
        Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = node->next;
        node->next = newNode;
    }

    void CCdelete_first_node(){
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        Node *temp2 = head;
        temp->next = temp2->next;
        head = temp->next;
        free(temp2);
    }

    void CCdelete_end_node(){
        Node *temp = head, *temp2;
        while(temp->next != head){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = head;
        free(temp);
    }

    void CCdelete_in_between(int position){
        Node *temp = head;
        int i = 0;
        while(i != position-1){
            temp = temp->next;
            i++;
        }
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
};

int main(){
    LinkedList L1(12);
    L1.insert_at_end(13);
    L1.insert_at_end(14);
    L1.insert_at_end(15);
    L1.insert_at_end(16);
    L1.insert_at_end(17);
    L1.insert_at_end(18);
    L1.insert_at_end(19);
    L1.singlyLinkedListTraversal();
    cout << "Circular Linked list Conversion...\n";
    L1.circularLLConversion();
    cout << "Circular Linked list Traversal:\n\t";
    L1.circularLinkedListTraversal();
    L1.CCinsert_at_head(11);
    cout << "CC insert at head (11):\n\t";
    L1.circularLinkedListTraversal();
    L1.CCinsert_at_end(20);
    cout << "CC insert at end (20):\n\t";
    L1.circularLinkedListTraversal();
    L1.CCinsert_in_between(22, 2);
    cout << "CC insert in between (22, 2):\n\t";
    L1.circularLinkedListTraversal();
    L1.CCdelete_in_between(2);          // index starts from 0, will delete 3rd element
    cout << "CC delete in between (2): // index starts from 0, this function will delete 3rd element (index=2)\n\t";
    L1.circularLinkedListTraversal();
    return 0;
}
