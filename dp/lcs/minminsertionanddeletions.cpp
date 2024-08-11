class Solution {
public:
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
        //         t[i][j]=max(t[i-1][j],t[i][j-1]);

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
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int x=LCS(word1,word2,n,m);
        int ans1=word1.length()-x;
        int ans2=word2.length()-x;
        int ans=ans1+ans2;
        return ans;
    }
};