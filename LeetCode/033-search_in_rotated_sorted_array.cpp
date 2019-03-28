// The original idea included the lines in comments.
// Actually in a binary search for this sort of arrays, 
// there will always be one half that is monotonous. 
// And the value at mid compared to values at both side
// is a crucial information regardless of 
// whether this interval is totally monotonous.
class Solution {
public:
  int bisearch(vector<int>& nums, int l, int r, int t) {
    if (l > r) return -1;
    if (l == r) {
      if (t == nums[l]) return l;
      return -1;
    }
    int mid = (l + r) / 2;
    // if (nums[l] > nums[r]) {
      if (nums[mid] < nums[r]) {
        if (t > nums[mid] && t <= nums[r]) return bisearch(nums, mid + 1, r, t);
        return bisearch(nums, l, mid, t);
      }
      else {
        if (t <= nums[mid] && t >= nums[l]) return bisearch(nums, l, mid, t);
        return bisearch(nums, mid + 1, r, t);
      }
    // }
    // else {
    //   if (t <= nums[mid]) return bisearch(nums, l, mid, t);
    //   return bisearch(nums, mid + 1, r, t);
    // }
  }
  int search(vector<int>& nums, int target) {
    return bisearch(nums, 0, nums.size() - 1, target);
  }
};