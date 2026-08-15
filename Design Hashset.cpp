
/* ================================== LeetCode version ======================================

- Time Complexity: O(1) 
- Space Complexity: O(1) 

class MyHashSet {
public:
    vector<bool> hash;
    MyHashSet() {
        hash = vector<bool>(1000001,false); 
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
public:
    vector<bool> hash;
    MyHashSet() {
        hash = vector<bool>(1000001,false); 
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    bool contains(int key) {
        return hash[key];
    }
};


int main() {
    MyHashSet myHashSet;

    int n;
    cout <<"Enter number of operations : ";
    cin >> n;

    cout <<"\nOperations :\n";
    cout <<"1 key -> Add key\n";
    cout <<"2 key -> Remove key\n";
    cout <<"3 key -> Check if key exists\n";

    for (int i = 0; i < n; i++) {
        int operation, key;

        cout <<"\nEnter operation and key : ";
        cin >> operation >> key;

        if(operation == 1) {
            myHashSet.add(key);
            cout <<"Key added.\n";
        }
        else if(operation == 2) {
            myHashSet.remove(key);
            cout <<"Key removed.\n";
        }
        else if(operation == 3) {
            if (myHashSet.contains(key))
                cout <<"Key exists.\n";
            else
                cout <<"Key does not exist.\n";
        }
        else{
            cout <<"Invalid operation.\n";
        }
    }
    return 0;
}