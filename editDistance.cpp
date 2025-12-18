// Question : Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

#include <bits/stdc++.h>
using namespace std;


// Memoization 
int solve(string &a, string &b , int i , int j , vector<vector<int>> &dp) {
        if(i == a.size()) return b.size() - j;
        if(j == b.size()) return a.size() - i;
        int finalAns = INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) {
            return solve(a , b , i+1 , j+1 ,dp);
        }else{
            int rep = 1 + solve(a , b , i+1 , j+1 , dp);
            int insert = 1 + solve(a , b , i , j+1 , dp);
            int del = 1 + solve(a , b , i+1 , j , dp);
            finalAns = min(finalAns , min(rep ,min(insert , del)));
        }
        return dp[i][j] =  finalAns;
    }
    int minDistance(string word1, string word2) {

        // Tabulation

        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1 , 0));
        
        for(int i = 0; i< word1.size(); i++){
            dp[i][word2.size()] = word1.size() - i;
        }
        for(int j = 0; j < word2.size(); j++){
            dp[word1.size()][j] = word2.size() - j;
        }
        int ans = 0;

        for(int i = word1.size()-1;i>= 0; i--){
            for(int j = word2.size()-1;j>= 0;  j--){
                if(word1[i] == word2[j]) {
                    ans = dp[i+1][j+1];
                }
                else{
                    int rep = 1 + dp[i+1][j+1];
                    int insert   = 1 + dp[i][j+1];
                    int del = 1 + dp[i+1][j];
                    ans = min(rep , min(insert , del));
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }