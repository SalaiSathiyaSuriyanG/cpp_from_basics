
/* ==================== LeetCode version =========================
- Leetcode Problem :  
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode mergedList;
        ListNode* tail=&mergedList;

        while(list1 && list2){
            if(list1->val <= list2->val){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        if(list1!=nullptr){
        tail->next=list1;}
        else{
        tail->next=list2;}
        return mergedList.next;
    }
};

=============================================================== */ 

// ==================== Runnable Version =========================

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode mergedList;
        ListNode* tail=&mergedList;

        while(list1 && list2){
            if(list1->val <= list2->val){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        if(list1!=nullptr){
        tail->next=list1;}
        else{
        tail->next=list2;}
        return mergedList.next;
    }
};


int main() {
    int n, m;

    // ----------------------- Input list1 -----------------------
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

    // ------------------------ Input list2 ------------------------
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

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);
    
    cout << "Merged list: ";
    while (merged) {
        cout<<merged->val;
        
        if(merged->next) 
		cout<<" -> ";
        merged = merged->next;
    }
    cout<<endl;

    return 0;
}