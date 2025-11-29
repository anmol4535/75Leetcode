// Question : Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
        int i = 0,j = 0;
        int maxVol = 0;
        int v = 0;

        for(; j<nums.size() ; j++){
            if(nums[j] == 0) v++;

            while( v > 1) {
                if(nums[i] == 0) v--;
                i++;
            }

            maxVol = max(maxVol , j-i+1);
        }
        return maxVol-1;
}