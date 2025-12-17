// Question : You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include <bits/stdc++.h>
using namespace std;

// Memoization
    int solve(vector<int> &nums , int ind , vector<int> &dp){
        if(ind >= nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        // take
        int a =  nums[ind] + solve(nums , ind+2 ,dp);

        // not Take
        int b =  solve(nums , ind+1 , dp);
        return dp[ind] =  max(a , b);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        // vector<int> dp(nums.size() +1 , -1);
        // return max(solve(nums , 0 , dp) , solve(nums , 1 , dp));

// Tabulation
        vector<int> dp(nums.size() + 3 , 0);
        for(int i = nums.size()-1; i>= 0; i--){
            dp[i] = max(dp[i+2] , dp[i+3]) + nums[i];
        }

        return max(dp[0] , dp[1] );
        
    }