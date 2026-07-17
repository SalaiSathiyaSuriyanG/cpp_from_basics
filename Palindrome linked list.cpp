
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(n) 

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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        string s = "";

        while (head) {
            s += to_string(head->val);
            head = head->next;
        }
        string rev = s;
        reverse(rev.begin(), rev.end());

        return s == rev;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <string>
#include <algorithm>
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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        string s = "";

        while (head) {
            s += to_string(head->val);
            head = head->next;
        }
        string rev = s;
        reverse(rev.begin(), rev.end());

        return s == rev;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "Palindrome\n";
        return 0;
    }
    int x;
    cout << "Enter values: ";
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }
    if (sol.isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}