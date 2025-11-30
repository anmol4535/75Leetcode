// Questiion : Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
//A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

#include <bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> mp;
    int n = grid.size();

    for (int i = 0; i < n; ++i) {
        mp[grid[i]]++;            // use the row directly
    }

    int ans = 0;
    for (int c = 0; c < n; ++c) {
        vector<int> col(n);
        for (int r = 0; r < n; ++r) col[r] = grid[r][c];
        auto it = mp.find(col);
        if (it != mp.end()) ans += it->second;
    }
    return ans;
}