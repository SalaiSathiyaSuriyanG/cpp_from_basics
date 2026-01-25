#include<iostream>

using namespace std;

int main()                                 //if the sum of factors of the number is equal to twice of the number,then it is a Perfect number.
{
    int sum=0,n;
     
    cout<<"Enter an integer: ";
    cin>>n;
    
    for(int i=1;i<=n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum==n*2){
        cout<<n<<" is a Perfect Number";
    }
    else{
        cout<<n<<" is not a Perfect Number";
    }
return 0;
}