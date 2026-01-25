#include<iostream>
using namespace std;

int main(){
    int A[10][10]={0};
    int B[10][10];
    int rows,cols,n;
    
    cout<<"Enter the number of Matrices : ";
    cin>>n;

    cout<<"\nEnter the no.of rows and columns: \n";
    cin>>rows>>cols;
    
	for(int m=0;m<n;m++){
		    cout<<"\nEnter the elements of the matrix "<<m<<" : \n";
		    
	    for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<"["<<i<<"]["<<j<<"]: "<<" ";
                cin>>B[i][j];
        	    A[i][j]+=B[i][j];
        }
    }   
}
      
	cout<<"\nThe addition of all matrices is: \n"; 	
    for(int i = 0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"["<<A[i][j]<<"]"<<" ";
        }
        cout<<endl;
    }
    return 0;
}