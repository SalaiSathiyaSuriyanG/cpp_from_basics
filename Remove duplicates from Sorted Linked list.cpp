
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
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
        return head;
        ListNode* current = head;

        while(current->next != nullptr){
            if(current->val == current->next->val)
            current->next = current->next->next;
            else
            current = current->next;
        }
        return head;
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
        return head;
        ListNode* current = head;

        while(current->next != nullptr){
            if(current->val == current->next->val)
            current->next = current->next->next;
            else
            current = current->next;
        }
        return head;
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
    ListNode* head = nullptr;

    int n, value;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insert(head, value);
    }

    head = sol.deleteDuplicates(head);
    cout << "\nAfter Removing Duplicates:\n";
    printList(head);

    return 0;
}


