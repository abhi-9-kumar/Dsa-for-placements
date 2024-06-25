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
   void inorderTraversal(TreeNode* root, int& k, int& result) {
        if (root == nullptr) return;

        inorderTraversal(root->left, k, result);

        // Process the current node
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }

        inorderTraversal(root->right, k, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = -1;  // Initialize result to a default value
        inorderTraversal(root, k, result);
        return result;
    }
};