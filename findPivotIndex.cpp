// Question : Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
        for(int i = 1; i< nums.size(); i++){
            nums[i] += nums[i-1];
        }
        int s;
        for(int i = 0; i< nums.size() ; i++){
            if(i == 0) {
                s = 0;
            }
            if(s == (nums[nums.size()-1] - nums[i])) return i;
            s = nums[i];
        }
        return -1;
    }