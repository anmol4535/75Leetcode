// Question : Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Can you solve it without sorting?

#include <bits/stdc++.h>
using namespace std;


int findKthLargest(vector<int>& nums, int k) {
      //  if(k > nums.size()) return 
        priority_queue<int> pq;
        for(auto it : nums){
            pq.push(it);
        }
        while(k-- > 1) {
            pq.pop();
        }

        return pq.top();
    }