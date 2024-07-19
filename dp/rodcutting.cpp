//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        // int length[n];
        // for(int i=1;i<=n;i++)
        // {
        //     length[i-1]=i;
        // }
        // int l=n;
        
        // int t[n+1][l+1];
        
        // for(int i=0;i<n+1;i++)
        // {
        //     for(int j=0;j<l+1;j++)
        //     {
        //         if(i==0) t[i][j]=0;
        //         if(j==0) t[i][j]=0;
        //     }
        // }
        
        // for(int i=1;i<n+1;i++)
        // {
        //     for(int j=1;j<l+1;j++)
        //     {
        //         if(length[i-1]<=j)
        //         {
        //             t[i][j]=max((price[i-1]+t[i][j-length[i-1]]),t[i-1][j]);
        //         }
        //         else
        //         t[i][j]=t[i-1][j];
        //     }
        // }
        // return t[n][l];
        
        int length[n];
        for(int i=1;i<=n;i++)
        {
            length[i-1]=i;   //making length array
        }
        std::vector<int> prev(n + 1, 0);
        std::vector<int> curr(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (length[i-1] <= j) {
                curr[j] = std::max(prev[j], price[i - 1] + curr[j - length[i-1]]);
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return prev[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends