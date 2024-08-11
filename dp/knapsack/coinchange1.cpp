class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // int t[n+1][amount+1];

        // for(int i=0;i<n+1;i++)
        // {
        //     for(int j=0;j<amount+1;j++)
        //     {
        //         if(i==0) t[i][j]=0;
        //         if(j==0) t[i][j]=1;
        //     }
        // }
        // for(int i=1;i<n+1;i++)
        // {
        //     for(int j=1;j<amount+1;j++)
        //     {
        //         if(coins[i-1]<=j)
        //         {
        //             t[i][j]=t[i-1][j]+t[i][j-coins[i-1]];
        //         }
        //         else
        //         t[i][j]=t[i-1][j];
        //     }
        // }
        // return t[n][amount];

       std::vector<int> prev(amount + 1, 0);
    std::vector<int> curr(amount + 1, 0);

    // Initialize base case
    prev[0] = 1;  // There is one way to make the amount 0

    for (int i = 1; i <= n; i++) {
        curr[0] = 1;  // There is one way to make the amount 0

        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] <= j) {
                curr[j] = prev[j] + curr[j - coins[i - 1]];
            } else {
                curr[j] = prev[j];
            }
        }
        // Copy curr to prev for the next iteration
        prev = curr;
    }

    return prev[amount];
    }
};