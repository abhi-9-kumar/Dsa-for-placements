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
   bool isSameTree(TreeNode* p, TreeNode* q){
        //any traversal would work. Here we are going for preorder traversal
        // if(p==nullptr||q==nullptr)
        // return (p==q);

        // return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    if(p == nullptr && q == nullptr) return true;

    else if(p == nullptr || q == nullptr ) return false;

    else if(p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};