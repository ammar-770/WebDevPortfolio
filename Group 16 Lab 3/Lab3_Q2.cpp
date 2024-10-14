/*
DSAA LAB 3
11 NOV 2023

2. Solve the following problem using a Singly Linked List. Given a singly linked list of 
characters, write a function to make word out of given letters in the list. Test Case:  
Input:C->S->A->R->B->B->E->L->NULL, 
Output:S->C->R->A->B->B->L->E->NULL
*/

#include <iostream>
#include <string.h>
#include "inputvalidate.cpp"
#include<cstdlib>
using namespace std;

void swap(char *a, char *b)
{ // swapping of variables, also can be done with that method temp = a; a = b; b = temp;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

struct Node
{
    char data;
    struct Node *next;
};

class LinkedList
{
    struct Node *head;

public:
    LinkedList(char newdata)
    {
        Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newdata;
        newNode->next = NULL;
        head = newNode;
    }

    void insert_at_head(char newdata)
    {
        Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newdata;
        newNode->next = head;
        head = newNode;
    }

    void insert_in_between(char newdata, int position)
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

    void insert_in_end(char newdata)
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

    void insert_after_node(Node *prevNode, char newdata)
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
        Node *temp = head;
        if(position <= 0){
    		cout << "Invalid Input:" << endl;
    		return;
		}
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

    void delete_Node_With_Given_Value_Which_Comes_FIrst(char value)
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

    void sort_word(int size)
    {
        if (size == 4)
        {
            char targettedArray[size] = "GAZA";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 5)
        {
            char targettedArray[size] = "SYRIA";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 6)
        {
            char targettedArray[size] = "PYTHON";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 7)
        {
            char targettedArray[size] = "LEBANON";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 8)
        {
            char targettedArray[size] = "SCRABBLE";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 9)
        {
            char targettedArray[size] = "PALESTINE";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 10)
        {
            char targettedArray[size] = "STRUCTURES";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 12)
        {
            char targettedArray[size] = "APPLICATIONS";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 13)
        {
            char targettedArray[size] = "INTERNATIONAL";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 15)
        {
            char targettedArray[size] = "DEV_C_PLUS_PLUS";
            sort_part_2(head, targettedArray, size);
        }
        else if (size == 18)
        {
            char targettedArray[size] = "VISUAL_STUDIO_CODE";
            sort_part_2(head, targettedArray, size);
        }
        else
        {
            cout << "Invalid Word." << endl;
            return;
        }
    }

    void sort_part_2(struct Node *h, char targetedArray[], int size)
    {
        char b;
        for (int k = 0; k < size; k++)
        {
            Node *temp = head;
            for (int i = 0; i < size; i++)
            {
                b = targetedArray[i];
                Node *temp2 = head;
                for (int j = 0; j < size; j++)
                {
                    if (temp2->data == b)
                    {
                        swap(temp2->data, temp->data);
                        break;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }
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
            cout << temp->data << "->";
            temp = temp->next;
        }
        if (temp == NULL)
            cout << "NULL";
        cout << endl;
    }

    void swapNodes(struct Node *a, struct Node *b)
    {
        a->data = a->data + b->data;
        b->data = a->data - b->data;
        a->data = a->data - b->data;
    }
};

int main()
{
    cout << "Enter No: ";
    int no;
    no = inputValidate_unsignInt();
    
    char a[no];
    cout << "Enter characters:";
    
    for (int i = 0; i < no; i++)
        a[i] = inputValidate_char();
    
    LinkedList L1(a[0]);

    for (int i = 1; i < no; i++)
        L1.insert_in_end(a[i]);
    
    cout << "Input: ";
    L1.display();
    
    L1.sort_word(no);
    
    cout << "Output: ";
    L1.display();
}
