// Question : Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

#include <bits/stdc++.h>
using namespace std;

 void solve(int target,int k,vector<vector<int>> &ans,vector<int> &res, int index) { 
        if( target == 0 && k == 0) {
            ans.push_back(res);
            return ;
        }
        if((target != 0 && k == 0) || (target == 0 && k != 0)) {
            return;
        }

    
        for(int i = index; i<10; i++) {     
            res.push_back(i);
            solve(target-i,k-1,ans,res,i+1);
            res.pop_back(); 
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        for(int i = 1; i< 10; i++) {
            arr.push_back(i);
        }
        vector<vector<int> > ans;
        vector<int> res;

        solve(n,k,ans,res,1);
        return ans;
    }