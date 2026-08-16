
/* ================================== LeetCode version ======================================

- Time Complexity: O(1) 
- Space Complexity: O(1) 

class MyHashMap {
public:
    int hash[1000001];
    MyHashMap() {
        fill(hash, hash + 1000001, -1);
    }
    
    void put(int key, int value) {
        hash[key] = value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <algorithm>
using namespace std;

class MyHashMap {
public:
    static int hash[1000001];  //Variable declaration
    MyHashMap() {
        fill(hash, hash + 1000001, -1);
    }
    
    void put(int key, int value) {
        hash[key] = value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
};

int MyHashMap::hash[1000001];  //Variable definition

int main() {
    MyHashMap myHashMap;
    int n;
    cout <<"Enter number of operations : ";
    cin >> n;

    cout <<"\nOperations :\n";
    cout <<"1 key value -> Add/Update key with value\n";
    cout <<"2 key -> Remove key\n";
    cout <<"3 key -> Get value of key\n";

    for (int i = 0; i < n; i++) {
        int operation, key;

        cout <<"\nEnter operation and key : ";
        cin >> operation >> key;

        if (operation == 1) {
            int value;
            cout <<"Enter value : ";
            cin >> value;

            myHashMap.put(key, value);
            cout <<"Key-value pair added.\n";
        }
        else if (operation == 2) {
            myHashMap.remove(key);
            cout <<"Key removed.\n";
        }
        else if (operation == 3) {
            int value = myHashMap.get(key);

            if (value != -1)
                cout <<"Value = " << value << "\n";
            else
                cout <<"Key does not exist.\n";
        }
        else {
            cout <<"Invalid operation.\n";
        }
    }
    return 0;
}