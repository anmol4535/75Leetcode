// Question : Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(key < root -> val) {
            root -> left = deleteNode(root -> left , key);
        }else if(key > root -> val){
            root -> right =  deleteNode(root -> right , key);
        }else {
            if(!root -> left && !root -> right){
                delete root ;
                return NULL;
            }else if(!root -> left) {
                TreeNode* right = root -> right;
                delete root;
                return right;
            }else if(!root -> right) {
                TreeNode* left = root -> left;
                delete root;
                return left;
            }else {
                TreeNode* temp = root -> left;
                while(temp -> right) {
                    temp = temp -> right;
                }
                root -> val = temp-> val;
                root -> left = deleteNode(root -> left , temp -> val);
            }
        }
        return root;
    }

// Always remember that the deleted node be return if there is atmost one chile present otherwise 
// it append to root -> right or root -> left according to the question condition.