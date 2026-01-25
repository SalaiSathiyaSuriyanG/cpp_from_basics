#include<iostream>

using namespace std;

int main()
{
    int count=0,n;
    
    cout<<"Enter an integer: ";
    cin>>n;
    
    for(int i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==2){
        cout<<n<<" is a Prime number.";
    }
    else{
        cout<<n<<" is not a Prime number.";
    }
}