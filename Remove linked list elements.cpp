
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 /
class Solution {
public:
    ListNode* removeElements(ListNode* head, int value) {
        if(head==nullptr)
        return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        /* A dummy node is included before the head node so that we can even 
        remove the head node and handle the edge cases. / 

        while(current->next != nullptr){
            if(current->next->val == value)
            current->next = current->next->next;
            else
            current = current->next;
        }
        return dummy->next;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int value) {
        if(head==nullptr)
        return head;
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* current = dummy;
        /* A dummy node is included before the head node so that we can even 
        remove the head node and handle the edge cases. */

        while(current->next != nullptr){
            if(current->next->val == value)
            current->next = current->next->next;
            else
            current = current->next;
        }
        return dummy->next;
    }
};

ListNode* insert(ListNode* head, int value) {
    if (head == nullptr)
    return new ListNode(value);

    ListNode* temp = head;
    while (temp->next != nullptr)
    temp = temp->next;

    temp->next = new ListNode(value);
    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
        cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    int n, x, val;
    ListNode* head = nullptr;

    cout << "Enter the number of elements in the linked list : ";
    cin >> n; 

    cout << "Enter the elements of the linked list : " << endl;
    for (int i = 0; i < n; i++) {
        cin >> x;
        head = insert(head, x);
    }
    cout << "Enter the value to remove : ";
    cin >> val;

    head = sol.removeElements(head, val);
    printList(head);

    return 0;
}