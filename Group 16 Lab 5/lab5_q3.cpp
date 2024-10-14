/*
DSA LAB 5
Group 16
Quetion 3

3. Write a program using stacks which takes an expression as input and determines whether the 
delimiters are matched or not. 
*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    char data;
    struct Node* next;
};

class Stack{
    Node* top;
    int size;       // stores the current number of elements
    int capacity;   // total capacity

    public:
    Stack(int c = 0){
        top = NULL;
        size = 0;
        capacity = c;
    }

    bool isEmpty(){
        return top == NULL;
    }

    bool isFull(){
        return size == capacity;
    }

    int getSize() const{
        return size;
    }

    int getCapacity() const{
        return capacity;
    }

    void push(char data){
        if(isFull()){
            cout << "Stack Overflow" << endl;
            return;
        }
        Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        free(temp);
        size--;
    }

    void setCapacity(int c){
        capacity = c;
    }

    char stackTop(){
        return top->data;
    }

    char stackBottom(){
        Node* temp = top;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp->data;
    }

    char peek(int position){
        Node* temp = top;
        for(int i = 0; ((temp != NULL) && (i != position)); i++){
            temp = temp->next;
        }
        if(temp != NULL){
            return temp->data;
        }
        return -1;
    }
};

bool delimitermatch(string s, Stack st)
{

    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
            continue;
        }
        else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
        {
            if (st.isEmpty())
            {
                return false; // More closing delimiters than opening delimiters
            }
            if (st.stackTop() == '(' && s[i] == ')')
            {
                st.pop();
            }
            else if (st.stackTop() == '[' && s[i] == ']')
            {
                st.pop();
            }
            else if (st.stackTop() == '{' && s[i] == '}')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (st.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Stack st(33);
    string s = "{}()()[]{([dsjhkjshdhsajdghfhf])}";
    cout << "String is: " << s << "\nSize: " << s.size() << endl;
    int n = delimitermatch(s, st);
    if (n == 1)
    {
        cout << "Delimiters matched";
    }
    else
    {
        cout << "Delimiters not matched";
    }
}
