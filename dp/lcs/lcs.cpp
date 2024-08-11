class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ans=LCS(text1,text2,text1.size(),text2.size());
        return ans;
       
    }

//recursive implementation
    // int LCS(string x,string y,int n,int m)
    // {
    //     if(n==0||m==0)
    //     return 0;

    //     if(x[n-1]==y[m-1])
    //     return 1+LCS(x,y,n-1,m-1);

    //     else
    //     return max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
    // }

    // memoized implementation
//     class Solution {
// public:
//      int t[1001][1001];

//     int longestCommonSubsequence(string text1, string text2) {
//         memset(t,-1,sizeof(t));
//         int ans=LCS(text1,text2,text1.size(),text2.size());
//         return ans;
       
//     }

//     int LCS(string x,string y,int n,int m)
//     {
//         if(n==0||m==0)
//         return 0;
        
//         if(t[m][n]!=-1)
//         return t[m][n];

//         if(x[n-1]==y[m-1])
//         return t[m][n]=1+LCS(x,y,n-1,m-1);

//         else
//         return t[m][n]= max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
//     }
// };

//     int LCS(string x,string y,int n,int m)
//     {
//        int t[n+1][m+1];
//        for(int i=0;i<n+1;i++)
//        {
//         for(int j=0;j<m+1;j++)
//         {
//             if(i==0||j==0)
//             t[i][j]=0;
//         }
//        }
//        for(int i=1;i<n+1;i++)
//        {
//         for(int j=1;j<m+1;j++)
//         {
//             if(x[i-1]==y[j-1])
//             t[i][j]=1+t[i-1][j-1];
//             else
//             t[i][j]=max(t[i][j-1],t[i-1][j]);
//         }
//        }
//        return t[n][m];
//     }
// };


//space optimization

    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.size();
    //     int m = text2.size();
        
    //     // If either string is empty, LCS length is 0
    //     if (n == 0 || m == 0) return 0;
        
    //     // Create two arrays to store current and previous row results
    //     vector<int> prev(m + 1, 0);
    //     vector<int> curr(m + 1, 0);
        
    //     for (int i = 1; i <= n; ++i) {
    //         for (int j = 1; j <= m; ++j) {
    //             if (text1[i - 1] == text2[j - 1]) {
    //                 curr[j] = 1 + prev[j - 1];
    //             } else {
    //                 curr[j] = max(prev[j], curr[j - 1]);
    //             }
    //         }
    //         // Move current row results to previous row for the next iteration
    //         swap(prev, curr);
    //     }
        
    //     return prev[m];
    // }
};



};