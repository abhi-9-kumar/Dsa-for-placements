#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void Sum(vector<int> candidates, vector<int>op, int target, int index) {
        if (target == 0) {
            ans.push_back(op);
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }

        // Include the current element
        op.push_back(candidates[index]);
        Sum(candidates, op, target - candidates[index], index + 1);
        op.pop_back();

        // Skip all duplicates for the current element
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            ++index;
        }
        
        // Exclude the current element
        Sum(candidates, op, target, index + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        vector<int> op;
        ans.clear(); // Clear the result vector for fresh calculations
        Sum(candidates, op, target, 0);
        return ans;
    }
};
