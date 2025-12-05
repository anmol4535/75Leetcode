// Question : Given the root of a binary tree, return its maximum depth.
//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // class to define treeNode* 
    struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };



    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(solve(root -> left ) , solve(root -> right));
    }
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};