// binary search solution
class Solution {
public:
  int mySqrt(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int l = 0, r = x;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (mid <= x / mid) l = mid + 1;
      else r = mid;
    }
    return l - 1;
  }
};

// bit manipulation
// fill as much 1's as possible to the answer
class Solution {
public:
  int mySqrt(int x) {
    int bits = 1 << 15, res = 0;
    while (bits > 0) {
      if ((res | bits) <= x / (res | bits)) res |= bits; // here | equals to +
      bits >>= 1;
    }
    return res;
  }
};