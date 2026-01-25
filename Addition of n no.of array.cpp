#include<iostream>
using namespace std;

int main(){
    int A[10][10];
    int B[10][10];
    int C[10][10];
    int rows,cols,n;

    cout<<"Enter the number of matrix you want : ";
    cin>>n;
    
    for(int i=0;i<n;i++){
    cout<<"\nEnter the no.of rows and columns: \n";
    cin>>rows>>cols;
    }

    cout<<"The "<<rows<<"X"<<cols<<" matrix is: \n";
	    for(int i = 0;i<rows;i++){
        for(int j=0;j<cols;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    
    for(int i = 0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<C[i][j];
        }
        cout<<endl;
    }
    return 0;
}