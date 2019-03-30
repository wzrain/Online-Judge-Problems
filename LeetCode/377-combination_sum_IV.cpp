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
    vector<unsigned int> dp(target + 1, 0);
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

// recursive top-down solution
// Use -1 instead of 0 to indicate the unsearched results 
// since there might be a lot of unreachable values.
// For every value tgt, we go through all the possibilities
// that might sum up to tgt because of the 0~nums.size()-1
// loop, AND every time we called this function to calculate
// the number corresponding to tgt the function does exactly
// the same thing, so it's ok to store the results.
// This is the whole point of MEMOIZATION.
// By the way the reason why this solution encountered no overflow
// as the last one did is that this solution will not go check 
// those with vast number of combinations but unreachable values.
class Solution {
public:
  int dfs(vector<int>& nums, int tgt, vector<int>& mp) {
    if (mp[tgt] != -1) return mp[tgt];
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (tgt < nums[i]) continue;
      res += dfs(nums, tgt - nums[i], mp);
    }
    mp[tgt] = res;
    return mp[tgt];
  }
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> mp(target + 1, -1);
    mp[0] = 1;
    dfs(nums, target, mp);
    return mp[target];
  }
};