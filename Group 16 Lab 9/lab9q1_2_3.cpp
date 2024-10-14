#include<iostream>
#include <limits>
#include "inputvalidate.cpp"
using namespace std;
// A binary tree node has data, pointer to left child and a pointer to right child
struct Node {
 int data;
 struct Node *left, *right;
};
// Utility function to create a new tree node
Node* newNode(int data) {
 Node* temp = new Node;
 temp->data = data;
 temp->left = temp->right = NULL;
 return temp;
}
/* Given a binary tree, print its nodes in inorder*/
void inorder(struct Node* node) {
 if (node == NULL)
 return;
 /* first recur on left child */
 inorder(node->left);
 /* then print the data of node */
 cout << node->data << " ";
 /* now recur on right child */
 inorder(node->right);
}
void preorder(struct Node* node) {
 if (node == NULL)
 return;
 /* then print the data of node */
 cout << node->data << " ";
 /* first recur on left child */
 preorder(node->left);
 /* now recur on right child */
 preorder(node->right);
}

void postorder(struct Node* node) {
 if (node == NULL)
 return;
 /* first recur on left child */
 postorder(node->left);
 /* now recur on right child */
 postorder(node->right);
 /* then print the data of node */ 
 cout << node->data << " ";
}

//VALIDATION
bool isValueInTree(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (value == root->data) {
        return true;
    } else if (value < root->data) {
        return isValueInTree(root->left, value);
    } else {
        return isValueInTree(root->right, value);
    }
}
Node* insertnode(Node* head,int data){
  Node* newnode=newNode(data);
  if (head== nullptr){
   return newnode;
  }
  if (head->data>data){
   head->left=insertnode(head->left,data);
  }
 if (head->data<data){
   head->right=insertnode(head->right,data);
  }
  return head;//for connectivity in the recursive lines
}

Node* buildTreeFromUserInput() {
    Node* root = nullptr;
    int nodes;
    cout << "Enter the number of nodes in the binary search tree: ";
    //validation starts
 while (!(cin>>nodes)) {
            // Clear the error flag for cin and discard invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer.\n";
        }
    //validation end
 for (int i = 0; i < nodes; ++i) {
        int value;
        std::cout << "Enter value for node " << i + 1 << ": ";
 //validation starts
    while (!(cin >> value)|| isValueInTree(root, value)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       cout << "Invalid input. Please enter an integer for the node value: ";
    }
    //validation end
    root = insertnode(root, value);
    }
    return root;
}

/* Driver code*/
int main()
{ 
	
 Node* root = buildTreeFromUserInput() ; // Initialize the root node
 char c;
	
	
// Function call
 while(1){
 cout<<"enter which type of traversal you want\n";
 cout<<" a)inorder b)preorder c)postorder";
 c = inputValidate_char();
 switch(c){
  case 'a':
   cout << "\nInorder traversal of binary tree is \n";
   inorder(root);
  break;
  case 'b':
   cout << "\nPreorder traversal of binary tree is \n";
   preorder(root);
  break;
  case 'c':
   cout << "\nPostorder traversal of binary tree is \n";
   postorder(root);
  break;
  default:
   cout<<"enter correct c/n";
   continue;
 }
 break;
 }

 return 0;
}