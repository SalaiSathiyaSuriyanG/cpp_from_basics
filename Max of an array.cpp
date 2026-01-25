#include<iostream>
using namespace std;
				
void Max()
	{
 int A[]={4,6,27,15,31,22,30,29,8,16};
int max=A[0];
int arr_size = sizeof(A)/sizeof(A[0]);

 for(int i=0;i<arr_size;i++){
 	if(max<A[i]){
 	max = A[i];}
 }
cout<<max;
}

int main(){
	Max();
    return 0;
	}
