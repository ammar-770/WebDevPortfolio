#include<iostream>
#include "inputvalidate.cpp"
using namespace std;


void hashtableset(int arr[],int n){
	for(int i=0;i<n;i++){
		arr[i]=-1;
	}
}
void hashtabledisplay(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
}
void insertkey(int key,int arr[],int n){
		int index=key%n;
		int i=1;
		if(arr[index]==-1){
		arr[index]=key;
		}
		else{
			do{	
				index=((key%n)+i)%n;
				i++;
			}while(arr[index]!=-1);
			arr[index]=key;
		}
}


main(){
	cout << "Enter size of Hash Table: ";
	int N = inputValidate_unsignInt();
	int *hashtable=new int[N];
	hashtableset(hashtable,N);
	hashtabledisplay(hashtable,N);
	for(int i = 0; i < N; i++){
		cout << "Enter Element " << i+1 << " of Hash Table: ";
		int num = inputValidate_unsignInt();
		insertkey(num, hashtable, N);
	}

	hashtabledisplay(hashtable,N);
}
