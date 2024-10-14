/*
DSAA LAB 1
24 OCT 2023

4. Using the abstract data Type of a Matrix given below, write a program that 
    1. Input a 4*3 matrix from user in 2D array 
    2. Map this array in 1D array using Row major order 
    3. Input second matrix of 3*4 in 2D array 
    4. Map this array in 1D array using Row major order. 
    5. Now perform matrix multiplication on these 1D arrays 
    6. Save the result back in a 2D array. 
Implement this question for any number of rows and columns using class “matrix”. 

*/

#include<iostream>
#include "inputvalidate.cpp"
using namespace std;

class matrix{
    int **p;
    int r;
    int c;
    int *rowmajor;
    int multiplied1DArrayColumns;
    int *multiply1D;
    
    public:
    matrix(int row, int col){
        r=row;
        c=col;
        p = new int*[r];
        for(int i=0;i<r;i++)
        {
            p[i]=new int[c];
            for(int j=0;j<c;j++)
                p[i][j] = i + j;
        }
    // CODE FOR STORING DATA FROM
    // **P TO *rowmajor ROW MAJOR
    }
    // Constructor
    
    void disp2D(){ 
        cout << "Displaying 2D:\n";
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
    }
    // displays the elements of **p
    
    void dispRowMajor(){
        int newrow = r * c;
        rowmajor = new int[newrow];
        int index = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                rowmajor[index++] = p[i][j];
            }
        }
        
        cout << "Elements of Row Major Order:\n" ;
        for(int i = 0; i < newrow; i++){
            cout << rowmajor[i] << " ";
        }
        cout << endl;
    }
    // converts 2D into 1D using row major
    //and displays the elements Row Major Order Matrix
    
    void Multiply_rowMajor(matrix &x){
    	int *rowmajor2 = x.get1D();
        if(r*c == x.getRows() * x.getColumns()){
			multiplied1DArrayColumns = r*c;
			multiply1D = new int[r*c];
			for(int i = 0; i < r*c; i++){
				multiply1D[i] = rowmajor[i] * rowmajor2[i];
			}
        }
        else{
            multiplied1DArrayColumns = 0;
            cout << "Function: Multiply_rowMajor() failed" << endl <<
                    "Rows of Second Matrix does not matches with the Columns of First Matrix" << endl;
        }
    }
    // Multiplies Matrices in row major order and save the result in a 1D dynamic array
    
    void rowMajor_2D(){
        int a = 0;
        cout << "Elements of Row Major Order in 2D Form: " << endl;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << rowmajor[a++] << " ";
            }
            cout << endl;
        }
    }
    // Maps the elements stored in row major order to
    // the 2D array and print the results

    void display1DMultipliedArray() const{
        if(multiplied1DArrayColumns > 0){
            cout << "Elements of Multipled 1D Array: " << endl;
            for(int i = 0; i < multiplied1DArrayColumns; i++){
                cout << multiply1D[i] << " ";
            }
            cout << endl;
        }
        else{
            cout << "Multiplication of matrices was not done that's why no elements of multiplication of 1d array"
             << endl;
        }
    }
    // displaying the multiply1d array elements

    int getRows() const{
        return r;
    }

    int getColumns() const{
        return c;
    }

    int getP(int a, int b){
        return p[a][b];
    }
    
    int* get1D(){
    	return rowmajor;
	}

    ~matrix(){
        for(int i = 0; i < r; i++){
            delete[] p[i];
        }
        delete[] p;
        delete[] rowmajor;
        delete[] multiply1D;
    }
    // Destructor
};
    
int main()
{
	cout << "Enter rows of matrix A: ";
	int row = inputValidate_unsignInt();
	cout << "Enter columns of matrix A: ";
	int col = inputValidate_unsignInt();
    matrix a(row,col);
    
    a.disp2D();
    
    a.dispRowMajor();
    
    cout << "Enter rows of matrix B: ";
	row = inputValidate_unsignInt();
	cout << "Enter columns of matrix B: ";
	col = inputValidate_unsignInt();
    matrix b(row, col);
    
    b.disp2D();
    b.dispRowMajor();
    a.Multiply_rowMajor(b);
    a.display1DMultipliedArray();
    a.rowMajor_2D();

    return 0;
}
