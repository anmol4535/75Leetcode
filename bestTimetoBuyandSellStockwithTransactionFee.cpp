// Question : You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
// Note:
// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& prices,int i , int fee , bool flag , vector<vector<int>> &dp){
        if(i >= prices.size()) return 0;
        int ans = INT_MIN;

        if(dp[i][flag] != -1) return dp[i][flag];
        if(!flag){
            int take = -prices[i] + solve(prices, i+1, fee, !flag , dp);
            int notTake = solve(prices , i+1, fee, flag  , dp);

            ans = max(ans , max(take , notTake));
        }else{
            int take = +prices[i] + solve(prices, i+1, fee, !flag , dp) - fee;
            int notTake = solve(prices , i+1, fee, flag , dp);

            ans = max(ans , max(take , notTake));
        }
        return dp[i][flag] =  ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() , vector<int> (2, -1));
        return solve(prices ,0, fee , 0, dp);
    }