// general recursive solution for n-sum
class Solution {
public:
  void dfs(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int>& tmp, int tgt, int n) {
    if (n == 2) {
      int l = idx, r = nums.size() - 1;
      while (l < r) {
        if (nums[l] + nums[r] < tgt) {
          l++;
          while (l < r && nums[l] == nums[l - 1]) l++;
        }
        else if (nums[l] + nums[r] > tgt) {
          r--;
          while (l < r && nums[r] == nums[r + 1]) r--;
        }
        else {
          res.push_back(tmp);
          res.back().push_back(nums[l]);
          res.back().push_back(nums[r]);
          l++;
          while (l < r && nums[l] == nums[l - 1]) l++;
          r--;
          while (l < r && nums[r] == nums[r + 1]) r--;
        }
      }
      return;
    }
    for (int i = idx; i < nums.size() - n + 1; ++i) {
      if (i > idx && nums[i] == nums[i - 1]) continue;
      if (tgt < n * nums[i]) break;
      tmp.push_back(nums[i]);
      dfs(nums, i + 1, res, tmp, tgt - nums[i], n - 1);
      tmp.pop_back();
    }
  }
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    dfs(nums, 0, res, tmp, target, 4);
    return res;
  }
};