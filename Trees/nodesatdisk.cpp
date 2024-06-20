/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    void addParent(TreeNode* root) {
    if (!root)
        return;

    // Process the current node: Set parent pointers for the left and right children
    if (root->left)
        parent[root->left] = root;

    // Traverse the left subtree
    addParent(root->left);

    if (root->right)
        parent[root->right] = root;

    // Traverse the right subtree
    addParent(root->right);
    }

    void findDistance(TreeNode* root,TreeNode* target,int k,vector<int>&result)
    {
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,int> vis;
        vis[target]=1;

        while(!q.empty())
        {
            int size=q.size();
            if(k==0)
            break;

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left&& !vis[node->left])
                {
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right&& !vis[node->right])
                {
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(parent[node]&&!vis[parent[node]])
                {
                    vis[parent[node]]=1;
                    q.push(parent[node]);
                }
            }
            k--;
        }
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            result.push_back(temp->val);
        } 
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        addParent(root);
        vector<int>result;
        findDistance(root,target,k,result);
        return result;

    }
};