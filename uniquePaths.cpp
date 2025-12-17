// Question : There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

#include <bits/stdc++.h>
using namespace std;

int M, N;

    int solve(int r, int c, vector<vector<int>>& dp) {
        if (r >= M || c >= N) return 0;

        if (r == M - 1 && c == N - 1)
            return 1;

        if (dp[r][c] != -1)
            return dp[r][c];

        return dp[r][c] = solve(r + 1, c, dp) + solve(r, c + 1, dp);
    }

    int uniquePaths(int m, int n) {
        // M = m;
        // N = n;
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(0, 0, dp);

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: first row & first column
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;

        // Fill the dp table
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
