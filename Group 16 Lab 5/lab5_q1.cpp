/*
DSA Lab 5
Group 16
Question 1

1. Please write a program which performs the following tasks: 
a. Make a left to right scan of the postfix expression 
b. If the element is an operand push it on Stack 
c. If the element is operator, evaluate it using as operands the correct number from stack 
and pushing the result onto the stack 
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

int evaluatePostfix(const string expression) {
    Stack operandStack;

	int i = 0;
	char c;
    for (c = expression[i]; c != '\0'; i++) {
    	c = expression[i];
        if (c >= '0' && c <= '9') {
            operandStack.push(c - '0'); // Push operands onto the stack
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = operandStack.pop();
            int operand1 = operandStack.pop();

            switch (c) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operandStack.peek();
}

int main() {
    string postfixExpression = "122/+45*-"; // Change this to your desired postfix expression
    int result = evaluatePostfix(postfixExpression);
    cout << "Result of evaluating the postfix expression '" << postfixExpression << "': " << result << endl;
    return 0;
}
