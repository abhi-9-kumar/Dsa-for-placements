class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));

        // Fill the LCS table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }

        // Construct the shortest common supersequence
        int i = n, j = m;
        string s;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                s.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (t[i][j - 1] > t[i - 1][j]) {
                s.push_back(str2[j - 1]);
                j--;
            } else {
                s.push_back(str1[i - 1]);
                i--;
            }
        }

        // Add remaining characters from str1 or str2
        while (i > 0) {
            s.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            s.push_back(str2[j - 1]);
            j--;
        }

        // Reverse the constructed string as we built it from the end
        reverse(s.begin(), s.end());
        return s;
    }
};
