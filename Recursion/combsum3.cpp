class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int> ip, vector<int> op, int n, int k) {
        if (n == 0 && op.size() == k) {
            ans.push_back(op);
            return;
        }
        if (ip.size() == 0 || n < 0) {
            return;
        }

        // Create copies of the current state of the op vector
        vector<int> op1 = op;
        vector<int> op2 = op;

        int val = ip[0];
        ip.erase(ip.begin());

        // Include the current value in op1 if it is valid
        if (val <= n) {
            op1.push_back(val);
            solve(ip, op1, n - val, k);
        }

        // Do not include the current value in op2
        solve(ip, op2, n, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ip = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> op;
        solve(ip, op, n, k);
        return ans;
    }
};
