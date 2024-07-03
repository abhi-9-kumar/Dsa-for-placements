//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>ans;
    
    void solve(vector<int>ip,vector<int>op)
    {
        if(ip.size()==0)
        {
            int sum= accumulate(op.begin(),op.end(),0);
            ans.push_back(sum);
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;

        op2.push_back(ip[0]);

        ip.erase(ip.begin()+0);

        solve(ip,op1);
        solve(ip,op2);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int>op;
        solve(arr,op);
        return ans;
    }
    
};
 

    
        



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends