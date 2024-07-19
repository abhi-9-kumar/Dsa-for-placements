 #define MOD 1000000007

    int solveRec(int arr[],int sum,int index,int n){
        if(index>=n){
            return (sum==0);
        } 
        int incl=0;  //The variable incl is explicitly initialized to 0 to handle the case where the current element arr[idx] cannot be included in the subset because it exceeds the remaining target sum (tar).
        if(sum>=arr[index]){
            incl=solveRec(arr,sum-arr[index],index+1,n);
        }
        int excl=solveRec(arr,sum,index+1,n);
        return incl+excl;
    }
    int solveMem(int arr[],int sum,int index,int n,vector<vector<int>> &dp){
        if(index>=n){
            return (sum==0);
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        int incl=0;
        if(sum>=arr[index]){
            incl=solveMem(arr,sum-arr[index],index+1,n,dp)%MOD;
        }
        int excl=solveMem(arr,sum,index+1,n,dp)%MOD;
        dp[index][sum]= (incl%MOD +excl%MOD)%MOD;
        return dp[index][sum];
    }
    int solveTab(int arr[],int n,int sumi){
        vector<vector<int>> dp(n+1,vector<int>(sumi+1,0));
        for(int index=0;index<=n;index++){
            dp[index][0]=1;
        }
        for(int index=n-1;index>=0;index--){
            for(int sum=0;sum<=sumi;sum++){
                int incl=0;
                if(sum>=arr[index]){
                    incl=dp[index+1][sum-arr[index]]%MOD;
                }
                int excl=dp[index+1][sum]%MOD;
                dp[index][sum]= (incl%MOD +excl%MOD)%MOD;
            }
        }
        return dp[0][sumi];
    }
    int spaceOpt(int arr[],int n,int sumi){
        vector<int> curr(sumi+1,0);
        vector<int> next(sumi+1,0);
        curr[0]=1;
        next[0]=1;
        for(int index=n-1;index>=0;index--){
            for(int sum=0;sum<=sumi;sum++){
                int incl=0;
                if(sum>=arr[index]){
                    incl=next[sum-arr[index]]%MOD;
                }
                int excl=next[sum]%MOD;
                curr[sum]= (incl%MOD +excl%MOD)%MOD;
            }
            next=curr;
        }
        return curr[sumi];
    }


    /*
        int mod=1e9+7;
        
        int perfectSum(int arr[], int n, int sum){
            int t[n+1][sum+1];
            for(int i=0;i<n+1;i++)
            t[i][0]=1;
            for(int j=1;j<sum+1;j++)
            t[0][j]=0;
            
            for(int i=1;i<n+1;i++)
            {
                for(int j=0;j<sum+1;j++)
                {
                    if(arr[i-1]<=j){
                        t[i][j]=(t[i-1][j-arr[i-1]]+t[i-1][j])%mod;
                    }
                    else{
                        t[i][j]=(t[i-1][j])%mod;
                    }
                }
            }
            return t[n][sum];
        }
    
    */