
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(n) // Because,the queue stores all the elements

class MyStack {
public:
    queue<int> q;
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 /
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;  

    while (n--) {
        string op;
        cout << "Enter operation (push / pop / top / empty): ";
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            st.push(x);
        } 
        else if (op == "pop") {
            if (!st.empty())
                cout << st.pop() << endl;
            else
                cout << "Stack is empty" << endl;
        } 
        else if (op == "top") {
            if (!st.empty())
                cout << st.top() << endl;
            else
                cout << "Stack is empty" << endl;
        } 
        else if (op == "empty") {
            cout << (st.empty() ? "true" : "false") << endl;
        }
    }

    return 0;
}