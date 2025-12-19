// Question : Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(string & a , string & b , int i , int j,vector<vector<int>> &dp){
        if(i == a.size() || j == b.size()) return 0;
        int ans = 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == b[j]) {
            ans =  1+solve(a,b,i+1, j+1 , dp);
        }else{
            int fir =  solve(a,b,i+1 , j+1 , dp);
            int sec = solve(a,b ,i, j+1 , dp);
            int third = solve(a,b, i+1 , j , dp);
            ans = max(ans , max(fir,max(third, sec)));
        }
        return dp[i][j] =  ans;  
    }


    int longestCommonSubsequence(string text1, string text2) { 
        // vector<vector<int>> dp(text1.size()+1 , vector<int> (text2.size() , -1));
        // return  solve(text1 , text2 , 0 , 0 ,dp);

        
        // Tabulation
        vector<vector<int>> dp(text1.size()+1 , vector<int> (text2.size()+1 , 0));
        
        // base case
        for(int i = 0; i< text1.size() ;i++){
            dp[i][text2.size()] = 0;
        }
        for(int j = 0; j< text2.size() ;j++){
            dp[text1.size()][j] = 0;
        }
        int ans = 0;
        for(int i = text1.size()-1; i>= 0; i--){
            for(int j = text2.size()-1 ; j>= 0; j--){
                if(text1[i] == text2[j]){
                    ans = 1 + dp[i+1][j+1];
                }else{
                    int fir =  dp[i+1][j+1];
                    int sec = dp[i][j+1];
                    int third = dp[i+1][j];
                    ans =  max(fir,max(third, sec));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }