class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      res ^= nums[i];  // a ^ a == 0, a ^ 0  == a
    }
    return res;
  }
};