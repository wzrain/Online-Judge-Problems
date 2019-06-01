// Moore Voting Algorithm
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int cnt = 0, res;
    for (auto num : nums) {
      if (!cnt) res = num;
      if (res == num) cnt++;
      else cnt--;
    }
    return res;
  }
};

// bit manipulation
// Every bit of the majority number appears more than n / 2 times.
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unsigned int mask = 1;
    int res = 0;
    while (mask) {
      int cnt = 0;
      for (auto n : nums) {
        if (n & mask) cnt++;
      }
      if (cnt > nums.size() / 2) res |= mask;
      mask <<= 1;
    }
    return res;
  }
};