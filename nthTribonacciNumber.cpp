// Question : The Tribonacci sequence Tn is defined as follows: 
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

#include <bits/stdc++.h>
using namespace std;

//  Memoization
    int solve(int n , vector<int> & dp){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = solve(n-1 , dp) + solve(n-2 , dp) + solve(n-3 , dp);
        dp[n] = ans;
        return dp[n];
    }
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        // vector<int> dp(n+1 , -1);
        // return solve(n , dp);

        // Tabulation
        vector<int> dp(n+1 );
        dp[1] = dp[2] = 1;
        dp[0] = 0;

        for(int i = 3; i<=n ; i++ ){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }