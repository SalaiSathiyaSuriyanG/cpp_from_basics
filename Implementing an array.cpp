#include<iostream>
using namespace std;
int main(){
	int rows,columns;
	int arr[10][10];
	
	cout<<"Enter the number of rows and columns :\n";
	cin>>rows>>columns;
	cout<<"\nEnter the elements of the array: \n";
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cout<<"["<<i<<"]["<<j<<"] : ";
			cin>>arr[i][j];
		}
		
	}
	
	cout<<"\nThe "<<rows<<"X"<<columns<<" array is : \n";
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cout<<"["<<arr[i][j]<<"]"<<" ";
		}
		cout<<endl;
	}
	return 0;
	
}