// The key is to figure out that it's equivalent to find n/3 non-adjacent numbers that have the largest sum. Then 
// it could be solved in a similar way in Problem 213.
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size(), tgt = n / 3;
        int lf = func(slices, 0, n - 2, tgt), rt = func(slices, 1, n - 1, tgt);
        return max(lf, rt);
    }
    int func(vector<int>& slices, int start, int finish, int tgt) {
        int n = slices.size();
        vector<vector<int>> dp(n + 1, vector<int>(tgt + 1, 0));
        for (int i = start; i <= finish; ++i) {
            for (int j = 1; j <= min(tgt, i + 1); ++j) {
                dp[i + 1][j] = max(dp[i][j], (i > 0 ? dp[i - 1][j - 1] : 0) + slices[i]);
            }
        }
        return dp[finish + 1][tgt];
    }
};