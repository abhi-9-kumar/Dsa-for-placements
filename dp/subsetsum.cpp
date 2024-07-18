// recurive solution (TLE)
    // bool solve(vector<int>arr, int sum,int n,int i){
    //     if( sum==0 ){
    //          return true;
    //     } 
    //     if(i==n)
    //     return false;
    //     bool notpick = solve(arr,sum,n,i+1);
    //     bool pick= solve(arr,sum-arr[i],n,i+1);
    //     return (pick or  notpick);
        
        
    // }
    // bool isSubsetSum(vector<int>arr, int sum){
    //     // code here 
    //     int n= arr.size();
    //   return solve(arr,sum,n,0);
        
    // }
    
    
    
     // MEMORIZATION
     
//   bool solve(const vector<int>& arr, int sum, int n, int i,vector<vector<int>>& t) {
//     if (sum == 0) {
//         return true;
//     }
//     if (i == n) {
//         return false;
//     }
//     if (t[i][sum] != -1) {
//         return t[i][sum];
//     }
//     bool notpick = solve(arr, sum, n, i + 1, t);
//     bool pick = false;
//     if (sum - arr[i] >= 0) {
//         pick = solve(arr, sum - arr[i], n, i + 1, t);
//     }
//     return t[i][sum] = (pick || notpick);
// }

// bool isSubsetSum(const std::vector<int>& arr, int sum) {
//     int n = arr.size();
//     vector<vector<int>> t(n, vector<int>(sum + 1, -1));
//     return solve(arr, sum, n, 0, t);
// }


//TOP DOWN DP

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
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
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends

/*
bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        vector<bool> curr(sum + 1, false);

        // Base case initialization
        prev[0] = true;

        for (int i = 1; i <= n; i++) {
            curr[0] = true; // There's always a subset with sum 0
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    curr[j] = prev[j - arr[i - 1]] || prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            // Move current row to previous row for the next iteration
            prev = curr;
        }

        return prev[sum];

*/