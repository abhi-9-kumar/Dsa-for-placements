//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

// 	int mod = (int)(1e9 + 7); // Initialize mod value for
//                               // calculations
//     int N; // Size of the array

//     int fun(int pos, int sum, int arr[])
//     {
//         if (pos >= N)
//             return sum == 0; // Check if sum is zero when
//                              // array position reaches end

//         int ans = 0; // Initialize answer with zero

//         ans += fun(pos + 1, sum,
//                   arr); // Recursively call function for
//                          // next position with sum unchanged
//         ans %= mod; // Take modulo of the answer to avoid
//                     // overflow
//         if (arr[pos] <= sum)
//             ans += fun(pos + 1, sum - arr[pos], arr),
//                 ans
//                 %= mod; // Recursively call function for
//                         // next position with reduced sum

//         return ans; // Return the calculated answer
//     }

// public:
//     int perfectSum(int arr[], int n, int sum)
//     {
//         N = n; // Assign n to N variable

//         return fun(0, sum, arr); // Call recursive function
//                                  // with initial parameters
//     }
// };
    public:
    long long mod=1e9+7;
	long cnt=0;
	void solve(vector<int>ip,vector<int>op,int sum)
	{   
	    if(ip.size()==0)
	    {
	    if(sum==0)
	    {
	        cnt++;
	        return;
	    }
	    return;
	    }
	    
	    
	   vector<int>op1=op;
	   vector<int>op2=op;
	   
	   op2.push_back(ip[0]);
	   int val=ip[0];
	   ip.erase(ip.begin()+0);
	   
	   solve(ip,op1,sum);
	   solve(ip,op2,sum-val);
	   return;
	   
	}
	
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<int>v;
        for(int i=0;i<n;i++)
        v.push_back(arr[i]);
        vector<int>op;
        solve(v,op,sum);
        return cnt;
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends