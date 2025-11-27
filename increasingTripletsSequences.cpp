// Question : Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

#include <bits/stdc++.h>
using namespace std;

// approach : T.C = O(n) , S.C = O(1);
bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX , s = INT_MAX;

        for(auto it : nums) {
            if(it <= f) f = it;
            else if(it <= s) s= it;
            else return true;
        }
        return false;
    }

    // another approach : T.C = O(n) , S.C = O(n);
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n),suf(n);
        int p = INT_MAX;
        int s = INT_MIN;
    
        for(int i = 0; i< n ; i++) {
            int j = n-i-1;
            p= min(p , nums[i]);
            pre[i] = p;
            s = max( s , nums[j]); 
            suf[j] = s;
           // cout<< pre[i]<<" "<< suf[j]<<endl;
        }

        for(int i = 1; i< n-1 ; i++) {
            if(pre[i]< nums[i]  && nums[i] < suf[i]) return true;
        }

        return false;

    }

//  this code have time complexity of o(n) and space complexity of o(1).
// this question is good for problem solving because this have that equation to find which three index you gone choose
// Looking forward to solve more this type of problem.