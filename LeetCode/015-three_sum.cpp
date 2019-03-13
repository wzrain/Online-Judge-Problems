class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i - 1] == nums[i]) continue;
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        if (nums[l] + nums[r] < -nums[i]) l++;
        else if (nums[l] + nums[r] > -nums[i]) r--;
        else {
          int lv = nums[l], rv = nums[r];
          res.push_back({nums[i], lv, rv});
          while(l < r && nums[l] == rv) l++;
          while(l < r && nums[r] == rv) r--;
        }
      }
    }
    return res;
  }
};