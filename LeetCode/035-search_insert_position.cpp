class Solution {
public:
  int bisearch(vector<int>& nums, int l, int r, int t) {
    if (l == r) return l;
    int mid  = (l + r) / 2;
    if (t <= nums[mid]) return bisearch(nums, l, mid, t);
    return bisearch(nums, mid + 1, r, t);
  }
  int searchInsert(vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    if (nums.back() < target) return nums.size();
    return bisearch(nums, 0, nums.size() - 1, target);
  }
};