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
    // void getpath(TreeNode* root,vector<vector<int>>&ans,vector<int>&v)
    // {
        
    //     if(!root) // if input node is null ptr
    //     return;
        
    //     v.push_back(root->val);
    //     if(!root->left && !root->right)
    //     {
    //         ans.push_back(v);
    //         v.pop_back();
    //         return;
    //     }
        
    //     getpath(root->left,ans,v);
    //     getpath(root->right,ans,v);
    //     v.pop_back();
    // }
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     vector<int> v;
    //     vector<vector<int>>ans;
    //     getpath(root,ans,v);
    //     vector<string>result;
    //     for(auto v:ans){
    //         string t = "";
    //         for(int i=0;i<v.size()-1;i++){
    //             t += to_string(v[i]);
    //             t += "->";
    //         }
    //         t += to_string(v[v.size()-1]);
    //         result.push_back(t);
    //     }
    //     return result;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
     void getpath(TreeNode* root, vector<string>& ans, string path) {
        if (!root) // if input node is null ptr
            return;
        
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);
        
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }
        
        getpath(root->left, ans, path);
        getpath(root->right, ans, path);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        getpath(root, ans, "");
        return ans;

    }
};
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
class Solution {
  public:
    void getpath(Node* root,vector<vector<int>>&ans,vector<int>&v)
    {
        
        if(!root) // if input node is null ptr
        return;
        
        v.push_back(root->data);
        if(!root->left && !root->right)
        {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        
        getpath(root->left,ans,v);
        getpath(root->right,ans,v);
        v.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int>v;
        vector<vector<int>>ans;
        getpath(root,ans,v);
        return ans;
        
    }
};
*/
/*
class Solution {
  public:
    void solve(Node* root, vector<int>v,vector<vector<int>>&ans){
        if(root==NULL)return;
        v.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(v);
        }
        
         solve(root->left,v,ans);
         solve(root->right,v,ans);
         v.clear();
    }
    vector<vector<int>> Paths(Node* root) {
       vector<vector<int>>ans;
       solve(root,{},ans);
       return ans;
    }
};
*/