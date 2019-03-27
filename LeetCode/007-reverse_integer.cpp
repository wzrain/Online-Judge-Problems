class Solution {
public:
  int reverse(int x) {
    if (x == INT_MIN) return 0;
    if (x < 0) return -reverse(-x);
    int res = 0;
    while (x > 0) {
      res *= 10;
      res += x % 10;
      x /= 10;
      if (x > 0 && res > INT_MAX / 10) return 0;
    }
    return res;
  }
};