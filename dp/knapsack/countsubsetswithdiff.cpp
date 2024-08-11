
        //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0, mod=1e9+7;
        for(int x:arr){
            sum+=x;
        }
        if((sum+d)%2){
            return 0;
        }
        sum=(sum+d)/2;
        
      
        int t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                t[i][j]=(t[i-1][j-arr[i-1]]+t[i-1][j])%mod;
                else
                t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum]%mod;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*
int countPartitions(int n, int d, vector<int>& arr) {
    int sum = 0,mod=1e9+7;
    for (auto x : arr) {
        sum += x;
    }
    
    // Check if (sum - d) is non-positive or odd
    if (sum - d < 0 || (sum - d) % 2 != 0) {
        return 0;
    }
    
    int k = (sum - d) / 2;
    
    vector<int> prev(k + 1, 0), curr(k + 1, 0);
    
    // Step 1: Base cases
    if (arr[0] == 0) {
        prev[0] = 2;
    } else {
        prev[0] = 1;
    }
    if (arr[0] != 0 && arr[0] <= k) {
        prev[arr[0]] = 1;
    }
    
    // Step 2: Represent all the states
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            // Step 3: Copy recursion
            int notTake = prev[j];
            int take = 0;
            if (arr[i] <= j) {
                take = prev[j - arr[i]];
            }
            curr[j] = (take + notTake) % mod;
        }
        prev = curr;
    }
    
    return prev[k];
}

*/