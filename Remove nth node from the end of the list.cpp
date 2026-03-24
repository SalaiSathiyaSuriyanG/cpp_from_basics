
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return head;
        ListNode dummy;
        dummy.next = head;
        /* A dummy node is included before the head node so that 
        we can even remove the head node and handle the edge cases./

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for(int i = 0; i<=n; i++) // moves fast n+1 times
            fast = fast->next;

        while(fast != nullptr){  // moves both fast and slow till fast is null
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* eleTodelete = slow->next; // To delete the element we want to, cause it's just after slow
        slow->next = slow->next->next;
        delete eleTodelete;

        return dummy.next;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

// Improved a little bit from LeetCode version to handle edge cases.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return head;
        ListNode dummy;
        dummy.next = head;
        /* A dummy node is included before the head node so that 
        we can even remove the head node and handle the edge cases.*/

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for(int i = 0; i<n; i++){  // moves fast n times if n is not greater than list size
            if (fast->next == nullptr) 
                return head;
            fast = fast->next;  
        }

        while(fast->next != nullptr){  // moves both fast and slow till fast->next is null
            fast = fast->next;
            slow = slow->next;
        }

        if (slow->next != nullptr){
        ListNode* eleTodelete = slow->next; // To delete the element we want to, cause it's just after slow
        slow->next = slow->next->next;
        delete eleTodelete;
        }
        return dummy.next;
    }
};

ListNode* createList(int n) {
    if (n == 0) 
    return nullptr;
    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution sol;
    int n,m;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the elements: ";
    ListNode* head = createList(n);

    cout << "Enter the position of the node to remove from the end: ";
    cin >> m;

    cout << "Original list: ";
    printList(head);

    head = sol.removeNthFromEnd(head, m);
    cout << "List after removing the node from end : ";
    printList(head);

    return 0;
}
