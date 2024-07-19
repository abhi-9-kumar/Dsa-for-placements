//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
        // int t[N+1][W+1];
        
        // for(int i=0;i<N+1;i++)
        // {
        //     for(int j=0;j<W+1;j++)
        //     {
        //         if(i==0) t[i][j]=0;
        //         if(j==0) t[i][j]=0;
        //     }
        // }
        // for(int i=1;i<N+1;i++)
        // {
        //     for(int j=1;j<W+1;j++)
        //     {
        //         if(wt[i-1]<=j)
        //         {
        //             t[i][j]=max((val[i-1]+t[i][j-wt[i-1]]),t[i-1][j]);
        //         }
        //         else
        //         t[i][j]=t[i-1][j];
        //     }
        // }
        // return t[N][W];
        
    std::vector<int> prev(W + 1, 0);
    std::vector<int> curr(W + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (wt[i - 1] <= j) {
                curr[j] = std::max(prev[j], val[i - 1] + curr[j - wt[i - 1]]);
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends