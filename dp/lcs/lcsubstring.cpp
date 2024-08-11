//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        int ans=0;
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++) t[i][0]=0;
        for(int j=0;j<m+1;j++) t[0][j]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                t[i][j]=1+t[i-1][j-1];
                ans=max(ans,t[i][j]);
                }
                else
                {
                    t[i][j]=0;
                }
                
            }
        }
        return ans;
        
    }
};
///space optimization
// class Solution{
//     public:
    
//     int longestCommonSubstr (string t1, string t2, int n, int m)
//     {
//         vector<int> prev(m+1,0), cur(m+1,0);
//         int ans=0;

//         //nested loops..
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(t1[i-1]==t2[j-1]){ 
//                     cur[j]=1+prev[j-1];
//                     ans=max(ans,cur[j]);
//                 }
                
//                 else{
//                     cur[j]=0;
//                 }
//             }
//             prev=cur;
//         }
//         return ans;
//     }
// };

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends