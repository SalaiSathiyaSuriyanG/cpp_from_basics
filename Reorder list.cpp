
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) //Using a stack to store the second half of the list.

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
    void reorderList(ListNode* head) {
        if(!head) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<ListNode*> st;
        while(slow){
            st.push(slow);
            slow = slow->next;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(!st.empty()){
            ListNode* top = st.top();
            st.pop();

            if(curr == top) break;

            prev = curr->next;
            curr->next = top;
            top->next = prev;
            curr = top->next;
        }
        //After reordering the list, the current's next should point to nullptr to cutoff the loop.
        curr->next = nullptr;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <stack>
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
    void reorderList(ListNode* head) {
        if(!head) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<ListNode*> st;
        while(slow){
            st.push(slow);
            slow = slow->next;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(!st.empty()){
            ListNode* top = st.top();
            st.pop();

            if(curr == top) break;

            prev = curr->next;
            curr->next = top;
            top->next = prev;
            curr = top->next;
        }
        //After reordering the list, the current's next should point to nullptr to cutoff the loop.
        curr->next = nullptr;
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
    int n,x;
    ListNode* head = nullptr;

    cout <<"Enter the number of elements in the linked list : ";
    cin >> n; 

    cout <<"Enter the elements of the linked list : " << endl;
    for(int i = 0; i < n; i++) {
        cin >> x;
        head = insert(head, x);
    }

    cout <<"Original List : ";
    printList(head);
    cout << endl;

    cout <<"Reordered List : ";
    sol.reorderList(head);
    printList(head);

    return 0;
}