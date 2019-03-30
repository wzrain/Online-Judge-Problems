// O(n^3) dp
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    vector<vector<unsigned long long>> dp(nums.size(), vector<unsigned long long>(target + 1, 0));
    for (int i = 0; i < nums.size(); ++i) if (nums[i] <= target) dp[i][nums[i]] = 1;
    // or dp[0][0] = 1 and the condition in the following if is j >= nums[i]
    for (int j = 1; j <= target; ++j) {
      for (int i = 0; i < nums.size(); ++i) {
        if (j > nums[i]) {
          for (int k = 0; k < nums.size(); ++k) {
            dp[i][j] += dp[k][j - nums[i]]; // Σdp[k][j - ni] is actually the current
                                            // total ways to sum up to j - ni, which 
                                            // could be memorized and the complexity
                                            // would be O(n^2) as follows.
          }
        }
      }
    }
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) res += dp[i][target];
    return res;// / nums.size();
  }
};

// O(n^2) dp
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int j = 1; j <= target; ++j) {
      for (int i = 0; i < nums.size(); ++i) {
        // exactly the same process as the infinite knapsack problem
        if (j < nums[i]) continue;
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[target];
  }
};