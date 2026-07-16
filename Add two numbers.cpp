
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = carry;
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            current->next = new ListNode(sum%10); 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = carry;
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            current->next = new ListNode(sum%10); 
            current = current->next;
        }
        return dummy->next;
    }
};

ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val;
        if(head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    int n1, n2;

    cout << "Enter the number of nodes in first list: ";
    cin >> n1;
    cout << "Enter the digits in reverse order: ";
    ListNode* l1 = createList(n1);

    cout << "Enter the number of nodes in second list: ";
    cin >> n2;
    cout << "Enter the digits in reverse order: ";
    ListNode* l2 = createList(n2);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result in reverse order: ";
    printList(result);

    return 0;
}