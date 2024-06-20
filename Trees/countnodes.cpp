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
    /*
    void inorder(TreeNode* root,int &count)
    {
        if(root==nullptr)
        return;

        count++;

        inorder(root->left,count);
        inorder(root->right,count);

    }
    int countNodes(TreeNode* root) {
        int ans=0;
        inorder(root,ans);
        return ans;
    }
    */

    int findleftheight(TreeNode* node)
    {
        int height=0;
        while(node)
        {
            height++;
            node=node->left;
        }
        return height;
    }
    int findrightheight(TreeNode* node)
    {
        int height=0;
        while(node)
        {
            height++;
            node=node->right;
        }
        return height;
    }


    int countNodes(TreeNode* root) {
        if(root==nullptr)
        return 0;
        int lh=findleftheight(root);
        int rh=findrightheight(root);
        if(lh==rh)
        return (1<<lh)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};