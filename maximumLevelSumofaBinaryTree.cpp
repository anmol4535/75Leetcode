// Question : Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

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

    struct Compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first == b.first)
            return a.second > b.second; // ascending order of second
        return a.first < b.first;       // max heap based on first
    }
};

    int maxLevelSum(TreeNode* root){
        if(root == NULL) return {};
        vector<int> ans;

        queue<pair<int , TreeNode*>> q;
        q.push({1, root});
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;


        while(!q.empty()){
            int s = q.size();
            int sum  = 0;
            int lvl;
            for(int i = 0 ; i< s; i++){
                pair<int , TreeNode*> p =q.front();
                q.pop();
                lvl = p.first;
                TreeNode* temp = p.second;
                sum += temp->val;
                if(temp -> left) q.push({lvl+1 , temp-> left});
                if(temp -> right ) q.push({lvl+1, temp-> right});
            }
            pq.push({sum ,lvl});
        }
        
        return pq.top().second;
    }
    