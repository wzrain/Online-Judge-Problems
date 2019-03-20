// after finding a maximum long subarray, count the additional intervals.
class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int cnt = 0;
    int i = 0, j = 0, p = 1, len, last = -1;
    while (i <= j && j < nums.size()) {
      if (p * nums[j] < k) {
        p *= nums[j++];
      }
      else {
        if (last == -1 || i >= last) {
          len = j - i;
          if (len & 1) cnt += ((len + 1) / 2 * len);
          else cnt += (len / 2 * (len + 1));
        }
        else {
          len = j - last;
          if (len & 1) cnt += ((len + 1) / 2 * len);
          else cnt += (len / 2 * (len + 1));
          cnt += (last - i) * len;
        }
        last = j;
        p /= nums[i++];
        if (!p) p = 1;
        if (i > j) j++;
      }
    }
    if (i < last) {
      len = j - last;
      if (len & 1) cnt += ((len + 1) / 2 * len);
      else cnt += (len / 2 * (len + 1));
      cnt += (last - i) * len;
    }
    else {
      len = j - i;
      if (len & 1) cnt += ((len + 1) / 2 * len);
      else cnt += (len / 2 * (len + 1));
    }
    return cnt;
  }
};

// The start and the end of a interval matter. 
// Every time the interval expands, this newly added element
// will create j - i + 1 new interval.
class Solution_2 {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int cnt = 0;
    int i = 0, j = 0, p = 1, len, last = -1;
    while (i <= j && j < nums.size()) {
      if (p * nums[j] < k) {
        cnt += (j - i + 1);
        p *= nums[j++];
      }
      else {
        p /= nums[i++];
        if (!p) p = 1;
        if (i > j) j++;
      }
    }
    return cnt;
  }
};