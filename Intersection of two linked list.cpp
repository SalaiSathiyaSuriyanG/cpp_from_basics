
/* ==================== LeetCode version =========================

- Time Complexity: O(m + n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointer_A = headA;
        ListNode* pointer_B = headB;

        while(pointer_A != pointer_B){
            if(pointer_A == nullptr)
                pointer_A = headB;
            else
                pointer_A = pointer_A->next;
                
            if(pointer_B == nullptr)
                pointer_B = headA;
            else
                pointer_B = pointer_B->next;       
        }
        return pointer_A;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointer_A = headA;
        ListNode* pointer_B = headB;

        while(pointer_A != pointer_B){
            if(pointer_A == nullptr)
                pointer_A = headB;
            else
                pointer_A = pointer_A->next;
                
            if(pointer_B == nullptr)
                pointer_B = headA;
            else
                pointer_B = pointer_B->next;       
        }
        return pointer_A;
    }
};

int main() {
    Solution sol;
    int n, m;

    cout << "Enter number of elements in list1: ";
    cin >> n;

    ListNode* list1 = nullptr;
    ListNode* tail1 = nullptr;
    
    cout<<"Enter the elements for List1 : ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ListNode* newNode = new ListNode(x);

        if (!list1) {          
            list1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    cout<<"Enter number of elements in list2: ";
    cin>>m;

    ListNode* list2 = nullptr;
    ListNode* tail2 = nullptr;
    
    cout<<"Enter the elements for List2 : ";
    for (int i = 0; i < m; i++) {
        int x;
        cin>>x;
        ListNode* newNode = new ListNode(x);

        if (!list2) {
            list2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next =newNode;
            tail2 = newNode;
        }
    }

    if (list1 && list1->next)
    tail2->next = list1->next;

    ListNode* intersection = sol.getIntersectionNode(list1, list2);

    if (intersection) {
        cout << "Intersection found at node " << intersection->val;
    } else {
        cout << "No intersection found.";
    }

    return 0;
}