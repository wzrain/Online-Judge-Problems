// non recursive
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back({});
    sort(nums.begin(), nums.end());
    int sz = res.size();
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] != nums[i - 1]) sz = res.size();
      int end = res.size();
      for (int j = end - sz; j < end; ++j) {
        res.push_back(res[j]);
        res.back().push_back(nums[i]);
      }
    }
    return res;
  }
};

//backtracking
class Solution {
public:
  void dfs(vector<int>& nums, int i, vector<int> tmp, vector<vector<int>>& res) {
    res.push_back(tmp);
    for (int j = i; j < nums.size(); ++j) {
      if (j > i && nums[j]==nums[j - 1]) continue;
      tmp.push_back(nums[j]);
      dfs(nums, j + 1, tmp, res);
      tmp.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    dfs(nums, 0, {}, res);
    return res;
  }
};