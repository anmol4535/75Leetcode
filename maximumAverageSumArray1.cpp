// Question : You are given an integer array nums consisting of n elements, and an integer k.
//Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, ans = INT_MIN;
        for(int i = 1; i<nums.size() ; i++){
            nums[i] += nums[i-1];
        }
        int i = 0; int j = k-1;
        while(j< nums.size()){
            int v = 0;
            if(i>0) v = nums[i-1];
            sum = nums[j] -v;
            ans = max(ans , sum/k);
            i++;
            j++;
        }
        return ans;
}