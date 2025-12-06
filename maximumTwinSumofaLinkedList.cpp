// Question :In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
//For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin
// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        // 1. Find middle using slow–fast
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half starting from slow
        ListNode* second = reverse(slow);

        // 3. Compute max twin sum
        int maxi = INT_MIN;
        ListNode* first = head;

        while (second != nullptr) {
            int s = first->val + second->val;
            maxi = max(maxi, s);
            first = first->next;
            second = second->next;
        }

        return maxi;
    }