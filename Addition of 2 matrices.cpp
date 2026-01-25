#include<iostream>
using namespace std;

int main(){
    int A[10][10];
    int B[10][10];
    int C[10][10];
    int rows,cols;

    cout<<"\nEnter the no.of rows and columns: \n";
    cin>>rows>>cols;
    
    cout<<"\nEnter the elements of the matrix A: \n";
	for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"["<<i<<"]["<<j<<"] : ";
            cin>>A[i][j];
        }
    }
    
    cout<<"\nEnter the elements of the matrix B: \n";
	for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"["<<i<<"]["<<j<<"] : ";
            cin>>B[i][j];
        }
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
        	C[i][j]=A[i][j]+B[i][j];
        }
    }
    
	cout<<"\nThe addition of matrix A and B is: \n"; 
	
    for(int i = 0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"["<<C[i][j]<<"]"<<" ";
        }
        cout<<endl;
    }
    return 0;
}