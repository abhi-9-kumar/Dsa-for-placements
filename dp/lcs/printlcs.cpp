//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
	public:
	  //printing all unique Longest Common Subsequence
	  set<string> helper(int i, int j, string s1, string s2, vector<vector<int>>& dp, unordered_map<string,set<string>>& mp){
         
         set<string> set;
         string key = to_string(i)+"-"+to_string(j); //making key for map
                  
         if(mp.find(key) != mp.end()){ //if key is present already in map then return from here
             return mp[key];
        }
         //else generate the pattern
         //same code for printing 1 longest subsequence but in recursive way
         if(i==0 || j==0) set.insert("");
         
         else if(s1[i-1]==s2[j-1]){
             auto result = helper(i-1,j-1,s1,s2,dp,mp);
             
             for(auto it: result){
                 set.insert(it + s1[i-1]);
             }
	  
         }
         
          else {
                 if(dp[i-1][j]>=dp[i][j-1]){
                      auto s2g = helper(i-1,j,s1,s2,dp,mp);
                     set.insert(s2g.begin(),s2g.end());
                  }
                  
                  if(dp[i][j-1]>=dp[i-1][j]){
                      auto s1g = helper(i,j-1,s1,s2,dp,mp);
                      set.insert(s1g.begin(),s1g.end());
                  }
       
	           }  
		//after generating all the sequence in form of set, just push that in map	   
	    mp[key] = set;        
	    return set;        
         
    }         
	
	 //first we generate the dp using tabulation then we use that for printing all LCS
	 vector<string> all_longest_common_subsequences(string s1, string s2)
		{
		 int n = s1.size();
         int m = s2.size();
        
        //for base-case in tabulation we write shifiting of index in right drxn
        //for every `i` should be treated as `i-1` and and same for `j` as `j-1` 
        //so we see base case in memo the i and j is negative so here treat them as 0, we shifted the indexes just right side
        //and because of shifting of index in right side we increase the size of dp by 1
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
		//if index2 is zero(in original words negative, after shifting index to right) or index 1 is anything our answer will be 0 always. because there will be no possiblity for subsequence
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        
        //if index1 zero then also
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                //so indexes shifted to right side but orignally not for in string so we compare string by decreasing indexes by 1 value
                if(s1[i-1]==s2[j-1]) dp[i][j] = (1 + dp[i-1][j-1]);
                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                 
                 
            }
        }
        
        unordered_map<string,set<string>> mp; //it is like dp for finding out all overlapping indexes with string sequence
        set<string> result = helper(n,m,s1,s2,dp,mp);
        vector<string> ans;
        
        for(auto it:result){
            ans.push_back(it);
        }
        
         return ans;  
	}
};
 


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends