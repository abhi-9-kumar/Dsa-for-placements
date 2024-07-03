//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string>ans;
    
    void solve(string s,string op){
        if(s.size()==0)
        {
            ans.push_back(op);
            return;
        }
        
        string op1=op;
        string op2=op;
        
        op1.push_back('s[0]');
        
        op2.push_back(' ');
        op2.push_back('s[0]');
    
        
        s.erase(s.begin()+0);
        
        solve(s,op1);
        solve(s,op2);
        return;
    }
    vector<string> permutation(string s) {
        // Code Here
        
        string op=" ";
        op.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,op);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}

// } Driver Code Ends