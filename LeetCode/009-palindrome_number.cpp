class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return 0;
    int res = 0, tmp = x;
    while (x > 0) {
      if (res > INT_MAX / 10) return 0;
      res *= 10;
      res += x % 10;
      x /= 10;
    }
    return res == tmp;
  }
};