class Solution {
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>>t(n+1,vector<bool>(sum+1));
        
        for(int i=0;i<=n;i++)
        t[i][0]=true;
        
        for(int j=1;j<=sum;j++)
        t[0][j]=false;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }
                else
                t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        return false;
        else{
            return isSubsetSum(nums,sum/2);
        }
    }
};