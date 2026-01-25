#include<iostream>
using namespace std;

int main()
{
    int sum=0,n;
    
    cout<<"Enter an integer : ";
    cin>>n;
    
    for(int i=1;i<=n;i++){
        sum+=i;  
    }
   cout<<"Sum of First "<<n<<" Natural numbers is "<<sum;
    return 0;
}