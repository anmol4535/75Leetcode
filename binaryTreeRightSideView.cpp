// Question : Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;

        queue<pair<int , TreeNode*>> q;
        q.push({0, root});
        map<int , int> mp;

        while(!q.empty()){
            int s = q.size();

            for(int i = 0 ; i< s; i++){
                pair<int , TreeNode*> p =q.front();
                q.pop();
                int lvl = p.first;
                TreeNode* temp = p.second;
                mp[lvl] = temp->val;
                if(temp -> left) q.push({lvl+1 , temp-> left});
                if(temp -> right ) q.push({lvl+1, temp-> right});
            }
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;

    }