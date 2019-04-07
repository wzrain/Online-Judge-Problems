// similar idea from first missing positive
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    nums.push_back(-1);
    for (int i = 0; i < nums.size(); ++i) {
      int tmp = nums[i];
      while (tmp != -1 && tmp != i) {
        //swap(nums[i], nums[nums[i]]);
        int cur = nums[tmp];
        nums[tmp] = tmp;
        tmp = cur;
      }
      nums[i] = tmp;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == -1) return i;
    }
    return -1;
  }
};