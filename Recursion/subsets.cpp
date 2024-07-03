class Solution {
public:
    void solve(vector<int>nums,vector<int>v, vector<vector<int>>&ans){
        
        if(nums.size()==0)
        {
            ans.push_back(v);
            return;
        }
        vector<int>op1=v;
        vector<int>op2=v;

        op2.push_back(nums[0]);

        nums.erase(nums.begin()+0);

        solve(nums,op1,ans);
        solve(nums,op2,ans);
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(nums,v,ans);
        return ans;
    }
};
/*
class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>nums,vector<int>&op){
        if(nums.size() == 0){
            res.push_back(op);
            return;
        }
        vector<int>op1 = op;
        vector<int>op2 = op;
        op2.push_back(nums[nums.size() - 1]);
        nums.pop_back();
        solve(nums,op1);
        solve(nums,op2);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
        solve(nums,op);
        return res;
    }
};

start from the last element and use pop_back() which will cost you O(1) time only*/