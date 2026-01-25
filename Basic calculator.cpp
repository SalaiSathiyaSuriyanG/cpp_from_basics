#include<iostream>

using namespace std;

int main()
{
    int x,y,choice;
    cout<<"Enter 2 integers: ";
    cin>>x>>y;
    cout<<"\n1.Add\n"<<"2.Sub\n"<<"3.Mult\n"<<"4.Div\n";
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch(choice){
        case 1:
        cout<<x+y;
        break;
        case 2:
        cout<<x-y;
        break;
        case 3:
        cout<<x*y;
        break;
        case 4:
        cout<<x/y;
        break;
        default:
        cout<<"Invalid option";
    }
return 0;    
}
