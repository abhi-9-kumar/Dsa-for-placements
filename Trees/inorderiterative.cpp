/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     void inorder(TreeNode* root,vector<int>&v)
//     {
//         if(root==nullptr)
//         return;
        
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
        
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         inorder(root,ans);
//         return ans;
        
//     }
// };
#include<bits/stdc++.h>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        stack<TreeNode*>st;
        TreeNode* node=root;
        while(!st.empty()||node!=nullptr)
        {
            if(node!=nullptr)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                //if(st.empty()==true) break;
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
 }
};
