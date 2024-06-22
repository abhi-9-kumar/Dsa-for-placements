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
    TreeNode* buildtree(vector<int>&inorder,int is,int ie,vector<int>&postorder,int ps,int pe,unordered_map<int,int>&mp)
    {
        if(ps>pe||is>ie)
        return nullptr;

        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=mp[postorder[pe]];
        int num=inroot-is;

        root->left=buildtree(inorder,is,inroot-1,postorder,ps,ps+num-1,mp);
        root->right=buildtree(inorder,inroot+1,ie,postorder,ps+num,pe-1,mp);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m=inorder.size();
        int n=postorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++)
        {
            mp[inorder[i]]=i;
        }

        TreeNode* root=buildtree(inorder,0,m-1,postorder,0,n-1,mp);
        return root;
        
    }
};