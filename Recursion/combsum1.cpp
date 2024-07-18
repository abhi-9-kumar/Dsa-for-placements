#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void Sum(vector<int> ip, vector<int> op, int target) {
        if (target == 0) {
            ans.push_back(op);
            return;
        }
        if (ip.empty()) {
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;

        // Decision to include the first element in ip
        if (ip[0] <= target) {
            op2.push_back(ip[0]);
            Sum(ip, op2, target - ip[0]);
        }

        // Decision to exclude the first element in ip
        ip.erase(ip.begin());
        Sum(ip, op1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear(); // Clear the result vector for fresh calculations
        vector<int> op;
        Sum(candidates, op, target);
        return ans;
    }
};

// Considering all subsets (power set), the time complexity is influenced by the number of subsets, which is 2^n
//  , where n is the number of elements in the input array. Additionally, each subset requires  O(n) time to be constructed and checked.

// Thus, the time complexity of the combinationSum function is approximately: n*2^n



// Space Complexity:
// The space complexity is determined by the maximum depth of the recursion tree and the space needed to store the results:

// Recursion Depth: The depth of the recursion tree can go up to n in the worst case.
// Result Storage: The result ans can store all possible combinations, each of which can have up to n elements.
// Thus, the space complexity is approximately:

// O(n) for recursion depth+O(2^n*n) for storing results