
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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
        return head;
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
        return head;
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
};

ListNode* insert(ListNode* head, int val) {
    if (head == nullptr) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Solution sol;
    int n, x;
    cout << "Enter the number of nodes : ";
    cin >> n;

    ListNode* head = nullptr;

    cout << "Enter the values : ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        head = insert(head, x);
    }

    cout << "Original list : ";
    printList(head);

    head = sol.reverseList(head);
    cout << "Reversed list : ";
    printList(head);

    return 0;
}