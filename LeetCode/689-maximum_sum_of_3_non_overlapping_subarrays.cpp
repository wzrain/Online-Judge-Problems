// O(n) space dp solution. The pos vector was supposed to 
// record the current best positions. But since the suffix
// positions are just from the previous calculation, we could
// just record the current best starting position of dp[i][j].
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n - k + 1, 0);
        int sm = 0;
        for (int i = 0; i < k; ++i) {
            sm += nums[i];
        }
        sum[0] = sm;
        for (int i = k; i < n; ++i) {
            sum[i - k + 1] = sum[i - k] + nums[i] - nums[i - k];
        }
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        vector<vector<int>> pos(n + 1, vector<int>(4, -1));
        for (int j = 1; j <= 3; ++j) {
            for (int i = n - j * k; i >= 0; --i) {
                if (sum[i] + dp[i + k][j - 1] >= dp[i + 1][j]) {
                    pos[i][j] = i;
                    dp[i][j] = sum[i] + dp[i + k][j - 1];
                }
                else {
                    dp[i][j] = dp[i + 1][j];
                    pos[i][j] = pos[i + 1][j];
                }
            }
        }
        vector<int> res;
        int idx = 0;
        for (int j = 3; j > 0; --j) {
            res.push_back(pos[idx][j]);
            idx = pos[pos[idx][j] + k][j - 1];
        }
        return res;
    }
};