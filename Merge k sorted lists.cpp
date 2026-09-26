
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n log k) //Where n is the total number of nodes in all lists and k is the number of linked lists.
- Space Complexity: O(k) //Where k is the number of linked lists.

/**
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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            // Return true if 'a' should come after 'b'
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Syntax : priority_queue<Type, Container<Type>, Custom_structure> Var_name;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        //Here, the manager(pq) uses his rule book(compare) 
        //to store the elements inside the empty container(vector<ListNode*>)
        //where ListNode* is the type of the elements stored inside the container.
        
        for(auto list : lists){
            if(list) pq.push(list);
        }

        ListNode mergedList(0); //Use stack allocation to avoid memory leakage.
        ListNode* tail = &mergedList;

        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;

            if(curr->next) pq.push(curr->next);
        }
        return mergedList.next;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <queue>
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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            // Return true if 'a' should come after 'b'
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Syntax : priority_queue<Type, Container<Type>, Custom_structure> Var_name;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        //Here, the manager(pq) uses his rule book(compare) 
        //to store the elements inside the empty container(vector<ListNode*>)
        //where ListNode* is the type of the elements stored inside the container.
        
        for(auto list : lists){
            if(list) pq.push(list);
        }

        ListNode mergedList(0); //Use stack allocation to avoid memory leakage.
        ListNode* tail = &mergedList;

        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;

            if(curr->next) pq.push(curr->next);
        }
        return mergedList.next;
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
        } 
        else{
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

int main(){
    Solution sol;
    int k;
    cout <<"Enter the number of linked lists : ";
    cin >> k;

    vector<ListNode*> lists(k);
    for(int i = 0; i < k; i++) {
        int n;
        cout <<"\nEnter the number of elements in list " << i + 1 << " : ";
        cin >> n;
        cout <<"Enter the elements of list " << i + 1 << " :"<< endl;

        lists[i] = createList(n);
    }

    ListNode* mergedList = sol.mergeKLists(lists);
    cout <<"\nMerged List : ";
    printList(mergedList);

    return 0;
}