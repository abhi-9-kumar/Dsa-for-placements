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
    // int maxi=0;
    // int height(TreeNode* root)
    // {
    //     if(root==nullptr)
    //     return 0;

    //     int lh=height(root->left);
    //     int rh=height(root->right);
    //     return 1+max(lh,rh);
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     // longest path between two nodes.
    //     //Naive way would be to visit each node and find lh+rh and store the maxm in a variable
    //     if(root==nullptr)
    //     return 0;
       
    //     int l=height(root->left);
    //     int r=height(root->right);
    //     maxi=max(maxi,l+r);
    //     diameterOfBinaryTree(root->left);
    //     diameterOfBinaryTree(root->right);

    //     return maxi;
        
    int height(TreeNode* root,int &diameter)
    {
        if(root==nullptr)
        return 0;

        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};