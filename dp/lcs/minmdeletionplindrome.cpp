//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int LCS(string a,string b,int n,int m)
{
    // int t[n+1][m+1];
    // for(int i=0;i<n+1;i++)
    // {
    //     for(int j=0;j<m+1;j++)
    //     {
    //         if(i==0||j==0) t[i][j]=0;
    //     }
    // }
    // for(int i=1;i<n+1;i++)
    // {
    //     for(int j=1;j<m+1;j++)
    //     {
    //         if(a[i-1]==b[j-1])
    //         t[i][j]=1+t[i-1][j-1];
    //         else
    //         t[i][j]=max(t[i][j-1],t[i-1][j]);
    //     }
    // }
    // return t[n][m];
     vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(curr[j - 1], prev[j]);
            }
            prev = curr;
        }
        return prev[m];
}
int minDeletions(string str, int n) { 
    //complete the function here 
    string str2=str;
    reverse(str2.begin(),str2.end());
    int LPS=LCS(str,str2,n,n);
    int ans=n-LPS;
    return ans;
    
} 