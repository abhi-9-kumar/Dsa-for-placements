class Solution {
public:
    void solve(vector<int>nums,vector<int>op,vector<vector<int>>&ans)
    {
        if(nums.size()==0)
        {
            sort(op.begin(),op.end());
            ans.push_back(op);
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;

        op2.push_back(nums[0]);

        nums.erase(nums.begin()+0);

        solve(nums,op1,ans);
        solve(nums,op2,ans);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(nums,op,ans);
        set<vector<int>>s;
        // return ans;
        for(int i=0;i<ans.size();i++)
        s.insert(ans[i]);

        vector<vector<int>>v;
        for(auto i:s)
        v.push_back(i);

        return v;
        
    }
};