class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int idx = nums.size() - 1, n = nums.size();
    while (idx > 0 && nums[idx] <= nums[idx - 1]) idx--;
    reverse(nums.begin() + idx, nums.end());
    if (!idx) return;
    int l = idx, r = n - 1, tgt = nums[idx - 1];
    while (l < r) {
      int mid = (l + r) / 2;
      if (tgt < nums[mid]) r = mid;
      else l = mid + 1;
    }
    swap(nums[idx - 1], nums[l]);
  }
};