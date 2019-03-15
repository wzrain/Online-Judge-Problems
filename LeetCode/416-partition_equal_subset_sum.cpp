// actually there is f[j][i] indicating 
// whether the sum i can be summed from the first j numbers.
// and the first dimension concerning j could be reused
// so the space cost can be reduced.
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    if (nums.empty()) return true;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) sum += nums[i];
    if (sum & 1) return false;
    int half = sum / 2;
    vector<int> f(half + 1, 0);
    f[0] = 1;
    for (int j = 0; j < nums.size(); ++j) {
      for (int i = half; i >= 0; --i) {
        if (nums[j] > half) return false;
        if(i >= nums[j] && f[i - nums[j]]) f[i] = 1;
      }
    }
    return f[half];
  }
};