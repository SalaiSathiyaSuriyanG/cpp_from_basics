#include<iostream>

using namespace std;

int main()
{
    int count=0,n;
    
    cout<<"Enter an integer: ";
    cin>>n;
    
    for(int i=1;i<=n;i++){
        if(n%i==0){
        	cout<<i<<"  ";
        }
    }
    cout<<" are the factors of the number "<<n;
    
    return 0;
}