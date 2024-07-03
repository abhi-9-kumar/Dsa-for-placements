//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    vector<string>v;
    
    void solve(int ones,int zeroes,int n,string &op)
    {
        if(n==0)
        {
            v.push_back(op);
            return;
        }
        
        string op1=op;
        op1.push_back('1');
        solve(ones+1,zeroes,n-1,op1);
        
        if(ones>zeroes)
        {
            string op2=op;
            op2.push_back('0');
            solve(ones,zeroes+1,n-1,op2);
        }
        return;
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    string op="";
	    int ones=0;
	    int zeroes=0;
	    solve(ones,zeroes,n,op);
	    return v;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends