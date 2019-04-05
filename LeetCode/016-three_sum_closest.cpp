class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int gap = INT_MAX, mark = 1;
    for (int i = 0; i < nums.size() - 2; ++i) {
      int tgt = target - nums[i];
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        while (l < r && nums[l] + nums[r] > tgt) r--;
        if (l != r) {
          if (gap > abs(tgt - (nums[l] + nums[r]))) {
            mark = -1;
            gap = abs(tgt - (nums[l] + nums[r]));
          }
        }
        if (r != nums.size() - 1) {
          if (gap > abs(tgt - (nums[l] + nums[r + 1]))) {
            mark = 1;
            gap = abs(tgt - (nums[l] + nums[r + 1]));
          }
        }
        while (l < r && nums[l] + nums[r] < tgt) l++;
        if (l != r) {
          if (gap > abs(tgt - (nums[l] + nums[r]))) {
            gap = abs(tgt - (nums[l] + nums[r]));
            mark = 1;
          }
        }
        if (l != i + 1) {
          if (gap > abs(tgt - (nums[l - 1] + nums[r]))) {
            mark = -1;
            gap = abs(tgt - (nums[l - 1] + nums[r]));
          }
        }
        if (!gap) return target;
      }
    }
    //cout<<mark;
    return target + mark * gap;
  }
};