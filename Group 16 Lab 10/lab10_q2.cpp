#include <iostream>
#include "inputvalidate.cpp"
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

class BST
{
    Node *root;

    Node *createLeaf2(Node *r, int data)
    {
        Node *newNode = createNode(data);
        if (r == NULL)
        {
            return newNode;
        }
        if (data < r->data)
        {
            r->left = createLeaf2(r->left, data);
        }
        if (data > r->data)
        {
            r->right = createLeaf2(r->right, data);
        }
        return r;
    }

    

public:
    BST()
    {
        root = NULL;
    }

    void createLeaf(int data)
    {
        root = createLeaf2(root, data);
    }

    /* 
    find function will take 3 variables as parameters in which one variable's value will be taken as pass by value
    and addresses of pointers will be taken by pass by reference in the rest 2 parameters.
    The variable whose value will taken will be the data which needs to be searched and it's name is i
    The name of the varaibles whose address will be taken will be loc and par, where loc will hold the address of
    any node and par will hold the address of parent of loc node
    */
    void find(int i, Node **par, Node **loc)
    {
        /*
        2 temporary variables: ptr and ptrsave are also created to keep the track of any node and it's parent node while
        searching
        */
        Node *ptr, *ptrsave;
        /*
        Case 1: 
        If root is NULL, it means that tree is empty, so loc and par both variables will be set to 
        NULL as tree is empty
        */
        if (root == NULL)
        {
            *loc = NULL;
            *par = NULL;
            return;
        }
        /*
        Case 2:
        If root has that value that needs to be searched, so loc will be set to address of root, and 
        it has no parent so par will be set to NULL.
        */
        if (i == root->data)
        {
            *loc = root;
            *par = NULL;
            return;
        }
        /*
        Case 3:
        If the value exists in somewhere else in the tree, then pointer ptr will be moved to the left node of root 
        if searching value is smaller than the root value otherwise pointer ptr will be set to the right 
        node of root. In this case, ptr is moving down the tree, so ptrsave will be initialized to the 
        parent of ptr which will be root in this case
        */
        if (i < root->data)
            ptr = root->left;
        else
            ptr = root->right;
        ptrsave = root;
        /*
        now, this while loop will run till the time when ptr equals to NULL
        
        first there is an if condition, which will check whether the value in ptr node is equal
        to the target value, 
        if yes, 
        then loc double pointer variable will point to that searched node (or 'ptr') and
        par double pointer variable value will be set to the address of parent of that searched node 
        (or 'ptrsave') and loop will end

        otherwise ptrsave address will be set to ptr address
        and there is one condition that if the target value is lesser than the value in ptr->data, then
        set the address of ptr to left node of ptr otherwise set it to ptr of right node.
        */
        while (ptr != NULL)
        {
            if (i == ptr->data)
            {
                *loc = ptr;
                *par = ptrsave;
                return;
            }
            ptrsave = ptr;
            if (i < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        /*
        Case 4: 
        If the tree does not contains that target value and the ptr become equal to NULL,
        then the loc double pointer variable will point to NULL means value not found and 
        the par double pointer variable will point to ptrsave means the last node where the ptr was 
        gone till during the above while loop in searching the target value.
        */
        *loc = NULL;
        *par = ptrsave;
    }

    /*
    Search function will take a variable value (means pass by value)
    That variable value will be the targetted value that needs to be searched.
    There are 2 cases in Search Function: Case 1: Data found and Case 2: Data not found
    Additional thing in this function is that if Data is found, then it will tell the depth
    of that targetted node.
    */
    void search(int data){
        int depth = 0;
        Node* temp = (struct Node*) malloc (sizeof(struct Node));
        temp = root;

        while(temp != NULL){
            depth++;
            if(temp->data == data){
                cout << "\nData found at depth " << depth << endl;
                return; 
            }
            else if(temp->data > data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        cout << "Data not found" << endl;
        return;
    }

    void findAndSearch_CombinedFunction(int data, Node** targetNode, Node** parentTargetNode){
        Node *ptr, *ptrsave;
        int depth = 0;
        if (root == NULL)
        {
            *targetNode = NULL;
            *parentTargetNode = NULL;
            cout << "Tree is empty" << endl;
            return;
        }
        depth++;
        if (data == root->data)
        {
            *targetNode = root;
            *parentTargetNode = NULL;
            cout << "Data found at depth " << depth << endl;
            return;
        }

        if (data < root->data)
            ptr = root->left;
        else
            ptr = root->right;
        ptrsave = root;
        while (ptr != NULL)
        {
            depth++;
            if (data == ptr->data)
            {
                *targetNode = ptr;
                *parentTargetNode = ptrsave;
                cout << "Data found at depth " << depth << endl;
                return;
            }
            ptrsave = ptr;
            if (data < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        cout << "Data not found" << endl;
        *targetNode = NULL;
        *parentTargetNode = ptrsave;
    }

    void inorder2(Node* r){
        if(r == NULL){
            return;
        }
        inorder2(r->left);
        cout << r->data << " ";
        inorder2(r->right);
    }

    void inorder(){
        inorder2(root);
    }
};

int main()
{
    BST B1;
    cout << "Find Function: \n\tCase 1: Empty Tree: " << endl;
    Node* parentTarget, *targettedNode;
    B1.find(5, &parentTarget, &targettedNode);
    if(parentTarget == NULL && targettedNode == NULL){
        cout << "Empty Tree" << endl;
    }
    
    B1.createLeaf(5);
    B1.createLeaf(3);
    B1.createLeaf(1);
    B1.createLeaf(2);
    B1.createLeaf(4);
    B1.createLeaf(8);
    B1.createLeaf(6);
    B1.createLeaf(9);

    B1.inorder();

    cout << "Find Function: \n\tCase 2: Tree as a targetted node: " << endl;
    B1.find(5, &parentTarget, &targettedNode);
    if(targettedNode && (parentTarget == NULL)){
        cout << "Tree is a targetted Node" << endl;
        cout << "Targetted Node: " << targettedNode << ", Targetted Node data : " << targettedNode->data << endl;
        cout << "Parent Node: " << parentTarget << endl;
    }

    cout << "Find Function: \n\tCase 3: Targetted node is present: " << endl;
    B1.find(9, &parentTarget, &targettedNode);
    if(targettedNode && (parentTarget)){
        cout << "Targetted Node is present: " << endl;
        cout << "Targetted Node: " << targettedNode << ", Targetted Node data : " << targettedNode->data << endl;
        cout << "Parent Node: " << parentTarget << ", Parent Node data: " << parentTarget->data << endl;
    }

    cout << "Find Function: \n\tCase 4: Targetted Node not present: " << endl;
    B1.find(10, &parentTarget, &targettedNode);
    if(!targettedNode && (parentTarget)){
        cout << "Targetted Node not present: " << endl;
        cout << "Targetted Node: " << targettedNode << endl;
        cout << "Parent Node: " << parentTarget << ", Parent Node data: " << parentTarget->data << endl;
    }

    cout << "Search Function: 2 Cases:\n\t Case 1: Data Found: " << endl;
    cout << "Finding 6: ";
    B1.search(6);
    cout << "\t Case 2: Data not found: " << endl;
    cout << "FInding 11: ";
    B1.search(11);

    cout << "Lab 10 Question 2: " << endl;
    B1.findAndSearch_CombinedFunction(3, &targettedNode, &parentTarget);
    return 0;

}