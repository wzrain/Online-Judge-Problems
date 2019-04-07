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

// xor solution
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int res = 0, st = 0;
    for (int i = 0; i < nums.size(); ++i) {
      res ^= nums[i];
      st ^= i;
    }
    st ^= nums.size();
    return res ^ st; // a ^ b == c => a ^ c == b
  }
};

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      res = res ^ i ^ nums[i]; // a ^ b ^ b == a
                               // xor operands can change position
    }
    res ^= nums.size();
    return res;
  }
};

// calculate sum
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      res += i;
      res -= nums[i]; // to avoid overflow
                      // If there are pluses and minuses in a series of operation,
                      // do them alternatively. Or break pluses into minuses. (a + (a - b) / 2)
    }
    res += nums.size();
    return res;
  }
};