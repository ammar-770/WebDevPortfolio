/*
DSA LAB 5
Group 16
Question 2

2. A palindrome is a word, phrase, number, or another sequence of characters that reads the same 
backward and forwards. Can you determine if a given string, s, is a palindrome? Write a 
Program using stack for checking whether a string is palindrome or not. 
*/

#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class Stack{
    Node *top;

    public:
    Stack(){
        top = NULL;
    }

    bool isEmpty(){
        return top == NULL;
    }

    bool isFull(){
        Node* temp = (struct Node*)malloc(sizeof(struct Node));
        return temp == NULL;
    }

    void push(int data){
        if(isFull()){
            cout << "Stack Overflow" << endl;
            return;
        }
        Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* temp = top;
        top = top->next;
        int value = temp->data;
        free(temp);
        return value;
    }

    int peek(int position){
        Node* temp = top;
        int i = 0;
        for(; ((temp != NULL) && (i != position)); i++){
            temp = temp->next;
        }
        if(temp != NULL){
            return temp->data;
        }
        return -1;
    }

    int stackTop(){
        return top->data;
    }

    int stackBottom(){
        Node* temp = top;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp->data;
    }

    Stack palindrome(){
        Stack temp;
        Node *tempNode = top;
        int i;
        for(i = 0; ;i++){
            if(tempNode == NULL){
                break;
            }
            temp.push(peek(i));
            tempNode = tempNode->next;
        }
        i--;
        Stack temp2;
        while(1){
            if(i == -1){
                break;
            }
            temp2.push(temp.peek(i));
            i--;
        }
        return temp2;
    }

    bool checkPalindrome(Stack S1, Stack S2){
        bool correct = true;
        Node* temp = top;
        for(int i = 0; temp != NULL; i++){
            temp = temp->next;
            if(S1.peek(i) == S2.peek(i)){
                correct = true;
            }
            else{
                return false;
            }
        }
        return correct;
    }

    void traversal(){
        cout << "Stack Traversal: ";
        Node* temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Stack S1;
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(3);
    S1.push(2);
    S1.push(1);
    cout << "S1: ";
    S1.traversal();
    Stack S2 = S1.palindrome();
    cout << "S2: ";
    S2.traversal();
    if(S1.checkPalindrome(S1, S2))
    cout << "S1 and S2 are palindrome" << endl;
    else
    cout << "S1 and S2 are not palindrome" << endl;

    Stack S3;
    S3.push(1);
    S3.push(2);
    S3.push(3);
    S3.push(4);
    S3.push(5);
    S3.push(6);
    cout << "S3: ";
    S3.traversal();
    Stack S4 = S3.palindrome();
    cout << "S4: ";
    S4.traversal();
    if(S3.checkPalindrome(S3, S4))
    cout << "S3 and S4 are palindrome" << endl;
    else
    cout << "S3 and S4 are not palindrome" << endl;
}
