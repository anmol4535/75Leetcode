// Question : Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
  
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;            // first node
        ListNode* even = head->next;     // second node
        ListNode* evenHead = even;       // store start of even list

        // Rewire in one pass
        while (even && even->next) {
            odd->next = even->next;      // link odd to next odd
            odd = odd->next;             // move odd

            even->next = odd->next;      // link even to next even
            even = even->next;           // move even
        }

        // attach even list after odds
        odd->next = evenHead;

        return head;
    }
};
