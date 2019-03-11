// similar to problem 46. After sorting the vector, 
// we can just swap the numbers that haven't shown up
// to the first place for recursion.
// Or it's ok to use an unordered_set to save the shown numbers(More space though).
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 0) return res;
    if (nums.size() == 1) return {nums};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (i && nums[i] <= nums.front()) continue;
      swap(nums[i], nums.front());
      vector<int> remain(nums.begin() + 1, nums.end());
      vector<vector<int>> tmp = permuteUnique(remain);
      for (int j = 0; j < tmp.size(); ++j) {
        tmp[j].push_back(nums.front());
        res.push_back(tmp[j]);
      }
    }
    return res;
  }
};