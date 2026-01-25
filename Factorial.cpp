#include<iostream>

using namespace std;

int main()
{
	int n;
	
	cout<<"Enter an integer: ";
	cin>>n;
	
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    cout<<"The Factorial of "<<n<<" is "<<fact;
    
return 0;    
}