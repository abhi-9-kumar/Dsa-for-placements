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
    void bstToGstHelper(TreeNode* root, int& rval) {
        if (root == nullptr) {
            return;
        }

        // Traverse the right subtree first
        bstToGstHelper(root->right, rval);

        // Update the current node's value and the running total (rval)
        rval += root->val;
        root->val = rval;

        // Traverse the left subtree
        bstToGstHelper(root->left, rval);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int rval = 0;
        bstToGstHelper(root, rval);
        return root;
    }
};