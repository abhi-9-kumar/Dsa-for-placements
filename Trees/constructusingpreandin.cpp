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
class Solution {
public:
    TreeNode* buildtree(vector<int>&preorder,int ps,int pe,vector<int>&inorder,int is,int ie,unordered_map<int,int>&mp)
    {
        if(ps>pe||is>ie)
        return nullptr;

        TreeNode* root= new TreeNode(preorder[ps]);

        int inroot=mp[root->val];
        int num=inroot-is;

        root->left=buildtree(preorder,ps+1,ps+num,inorder,is,inroot-1,mp);
        root->right=buildtree(preorder,ps+num+1,pe,inorder,inroot+1,ie,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m=preorder.size();
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[inorder[i]]=i;

        TreeNode* root=buildtree(preorder,0,m-1,inorder,0,n-1,mp);
        return root;
    }
};