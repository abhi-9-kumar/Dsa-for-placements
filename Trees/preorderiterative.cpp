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
//     void preorder(TreeNode* root,vector<int>&v)
//     {
//         if(root==nullptr)
//         return;
//         v.push_back(root->val);
//         preorder(root->left,v);
//         preorder(root->right,v);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         preorder(root,ans);
//         return ans;
//     }
// };

    class Solution{
        public:

        vector<int> preorderTraversal(TreeNode* root)
        {
            vector<int>preorder;
            if(root==nullptr)
            return preorder;
            stack<TreeNode*>st;
            st.push(root);
            while(!st.empty())
            {
                TreeNode* temp=st.top();
                st.pop();
                preorder.push_back(temp->val);
                if(temp->right!=nullptr)
                st.push(temp->right);
                if(temp->left!=nullptr)
                st.push(temp->left);
            }
            return preorder;
        }
    };