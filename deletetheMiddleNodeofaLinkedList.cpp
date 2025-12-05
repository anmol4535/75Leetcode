// Question : You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Definition for singly-linked list.
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL) return NULL;
        ListNode* temp= head;
        ListNode* slow = temp;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast -> next != NULL ){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next;
            cout<< "Value:" << fast-> val<<endl;
            if(fast-> next == NULL || fast-> next-> next == NULL) {
                cout<< fast-> val<<endl;
                prev-> next = slow-> next;
            }
            else fast = fast -> next;
        }
        return temp;
    }
};