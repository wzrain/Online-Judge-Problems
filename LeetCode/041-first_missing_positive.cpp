// Evolved from the O(n) space solution.
// When unable to find the best solution directly, 
// try to generate it from a less perfect one.
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == i + 1) continue;
      int tmp = nums[i];
      // No need tmp != i + 1 for the while condition because if tmp == i + 1,
      // that means the current tmp will swap against the original nums[i], which
      // has already been put into the right place(nums[nums[i - 1]]), so 
      // nums[tmp - 1] != tmp will also end the loop.
      // If tmp != i + 1 is the condition we still need another assignment
      // statement to let nums[i] = tmp after the loop.
      // If the operation is swap(nums[nums[i] - 1], nums[i]), 
      // we use nums[i] directly instead of tmp to track pending values.
      // If tmp is used then nums[i] remains original until i + 1 is placed here.
      // If nums[i] is changing it always is the last elements placed here until
      // i + 1 is placed. Two ways have the same loop ending condition.
      while (tmp > 0 && tmp <= nums.size() && nums[tmp - 1] != tmp) {
        int sw = nums[tmp - 1];
        nums[tmp - 1] = tmp;
        tmp = sw;
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) return i + 1;
    }
    return nums.size() + 1;
  }
};