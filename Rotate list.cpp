
/* ================================== LeetCode version ======================================

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;

        //To find the no.of elements in the list    
        ListNode* temp = head;
        int n = 1;    
        while(temp->next){
            temp = temp->next;
            n++;
        } 

        //Make a circular link   
        temp->next = head;

        /*We reduce k (no.of rotations). Because for n no.of elements
        every nth time,the list comes back to its original state /
        k = k % n;
        int steps = n - k;

        //Move temp to the new tail (n - k - 1 steps from head)
        temp = head;
        for(int i = 1; i < steps; i++){
            temp = temp->next;
        }

        //Set new head and break the link to get the rotated list    
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return newHead;
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;

        //To find the no.of elements in the list    
        ListNode* temp = head;
        int n = 1;    
        while(temp->next){
            temp = temp->next;
            n++;
        } 

        //Make a circular link   
        temp->next = head;

        /*We reduce k (no.of rotations). Because for n no.of elements
        every nth time,the list comes back to its original state*/
        k = k % n;
        int steps = n - k;

        //Move temp to the new tail (n - k - 1 steps from head)
        temp = head;
        for(int i = 1; i < steps; i++){
            temp = temp->next;
        }

        //Set new head and break the link to get the rotated list    
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return newHead;
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


int main(){
    Solution sol;
    ListNode* head = nullptr;

    int n,value,k;
    cout <<"Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter the elements of the linked list: ";
    for(int i = 0; i < n; i++){
        cin >> value;
        head = insert(head,value); 
    }
    
    cout <<"Enter the number of rotations: ";
    cin >> k;
    
    cout << "Original List : ";
    printList(head);

    cout << "Rotated List : ";
    head = sol.rotateRight(head,k);
    printList(head);

    return 0;
}