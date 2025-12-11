// Question : Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
//The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    int ans = 0;
    void solve(TreeNode* root , long long tar ) { 
        if(root == NULL) return;
        if(tar == root -> val) {
            ans = ans+1;
        }
      
        solve(root -> left , tar-(long long)root -> val );
        solve(root -> right , tar - (long long)root -> val);
    }
    int pathSum(TreeNode* root, int targetSum) { 
        if(root) {
            solve(root , targetSum );
            pathSum(root -> right , targetSum);
            pathSum(root -> left , targetSum);
        }
        return ans;
    }