
/* ================================== LeetCode Version ======================================

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
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;  // Tracks the last known element without duplicates.
        ListNode* curr = head;  // The scout we use to walk through the list.
        
        while(curr != nullptr && curr->next != nullptr){
            // Case 1 : If duplicate element found
            if(curr->val == curr->next->val){
                // Move curr forward as long as the duplicate streak continues.
                while(curr->next && (curr->val == curr->next->val)){
                    curr = curr->next;
                }

                // curr now points to the very last duplicate node.
                // By setting prev->next point to curr->next, we move to the new unseen element.
                prev->next = curr->next;   
            }

            // Case 2 : If no duplicate found
            else prev = prev->next;

            // Move our scout forward to continue scanning the rest of the list.
            curr = curr->next;
        }
        return dummy->next;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

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
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;  // Tracks the last known element without duplicates.
        ListNode* curr = head;  // The scout we use to walk through the list.
        
        while(curr != nullptr && curr->next != nullptr){
            // Case 1 : If duplicate element found
            if(curr->val == curr->next->val){
                // Move curr forward as long as the duplicate streak continues.
                while(curr->next && (curr->val == curr->next->val)){
                    curr = curr->next;
                }

                // curr now points to the very last duplicate node.
                // By setting prev->next point to curr->next, we move to the new unseen element.
                prev->next = curr->next;   
            }

            // Case 2 : If no duplicate found
            else prev = prev->next;

            // Move our scout forward to continue scanning the rest of the list.
            curr = curr->next;
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
    ListNode* head = nullptr;
    int n, val; 

    cout <<"Enter the number of elements : ";
    cin >> n;

    cout <<"Enter the sorted elements :" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insert(head, val);
    }

    head = sol.deleteDuplicates(head);
    cout <<"\nAfter Removing Duplicates : ";
    printList(head);

    return 0;
}