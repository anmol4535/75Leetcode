// Question : You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

#include <bits/stdc++.h>
using namespace std;

// Memoization
    int solve(vector<int> & cost , int i , vector<int> & dp) {
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        if(i == cost.size()-1 || i == cost.size()-2) return cost[i];
        

        return dp[i] =  min(solve(cost , i+1 , dp) , solve(cost , i+2 , dp)) + cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Tabulation 
        vector<int> dp(cost.size()+2 , 0);
        
        for(int i = cost.size() -1 ; i>= 0; i--){
            dp[i] = min(dp[i+1] , dp[i+2]) + cost[i];
        } 

        return min(dp[0] , dp[1]); 
    }