
/* ==================== LeetCode version =========================

- Time Complexity: O(n) //Push is O(1).pop and peek are O(1) amortized, 
                        but O(n) in the worst case due to stack transfer form s1 to s2.
- Space Complexity: O(n) // we store n elements in the stack.

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue(){}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x; 
    }
    
    int peek() {
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/*
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 /
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue(){}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x; 
    }
    
    int peek() {
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;  

    while (n--) {
        string op;
        cout << "Enter operation (push / pop / peek / empty): ";
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            q.push(x);
        } 
        else if (op == "pop") {
            if (!q.empty())
                cout << q.pop() << endl;
            else
                cout << "Queue is empty" << endl;
        } 
        else if (op == "peek") {
            if (!q.empty())
                cout << q.peek() << endl;
            else
                cout << "Queue is empty" << endl;
        } 
        else if (op == "empty") {
            cout << (q.empty() ? "true" : "false") << endl;
        }
    }

    return 0;
}