
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
        return false;

        ListNode* slower = head;
        ListNode* faster = head;

        while(faster != nullptr && faster->next != nullptr){
            slower = slower->next;
            faster = faster->next->next;  

            if(slower == faster)
            return true;
        }
        return false;   
    } 
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
        return false;

        ListNode* slower = head;
        ListNode* faster = head;

        while(faster != nullptr && faster->next != nullptr){
            slower = slower->next;
            faster = faster->next->next;  

            if(slower == faster)
            return true;
        }
        return false;   
    } 
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if(n <= 0) {
        cout << "false\n";
        return 0;
    }
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter node values:\n";
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        ListNode* newNode = new ListNode(val);

        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int m;
    cout << "Create cycle? (1 = yes, 0 = no): ";
    cin >> m;

    if(m == 1) {
        tail->next = head;   
    }
    cout << (sol.hasCycle(head) ? "true" : "false") << endl;

    return 0;
}