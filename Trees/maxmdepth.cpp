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


    int maxDepth(TreeNode* root) {
    ////recursive approach
    //    if(root==nullptr)
    //    return 0;

    //    int lh=maxDepth(root->left);
    //    int rh=maxDepth(root->right);
    //    return 1+max(lh,rh);

    // level order approach
    int depth=0;
    if(root==nullptr)
    return depth;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        depth++;
        for(int i=0;i<size;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        
    }
    return depth;
    }
};
