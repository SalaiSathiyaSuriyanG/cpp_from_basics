#include<iostream>
using namespace std;

int main()
{
    int rev=0,n;
    int r;
    int m;
    
    cout<<"Enter a number: ";
    cin>>n;
    
    m=n;
    
    while(n>0){
        r=n%10;
        n=n/10;
        rev=rev*10+r;
    }
    if(m==rev){
        cout<<m<<" is a Palindrome";
    }
    else{
        cout<<m<<" is not a Palindrome";
    }
return 0;
}