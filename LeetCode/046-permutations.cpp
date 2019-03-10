class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 0) return {};
    if (nums.size() == 1) return {nums};
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
      swap(nums[i], nums.front());
      vector<int> remain(nums.begin() + 1, nums.end());
      vector<vector<int>> tmp = permute(remain);
      for (int j = 0; j < tmp.size(); ++j) {
        tmp[j].push_back(nums.front());
        res.push_back(tmp[j]);
      }
    }
    return res;
  }
};