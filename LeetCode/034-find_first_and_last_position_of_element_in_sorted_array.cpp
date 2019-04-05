class Solution {
public:
  int bisearch1(vector<int>& nums, int l, int r, int t) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (t < nums[mid]) return bisearch1(nums, l, mid, t);
    return bisearch1(nums, mid + 1, r, t);
  }
  int bisearch2(vector<int>& nums, int l, int r, int t) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (t <= nums[mid]) return bisearch2(nums, l, mid, t);
    return bisearch2(nums, mid + 1, r, t);
  }
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};
    int mn = bisearch2(nums, 0, nums.size() - 1, target);
    if (nums[mn] != target) return {-1, -1};
    // Here no need to search all the array again, just start
    // with mn. And if we search for target + 1 instead of 
    // target, we can use only bisearch2 function.
    int mx = bisearch2(nums, mn, nums.size(), target + 1) - 1;
    return {mn, mx};
  }
};