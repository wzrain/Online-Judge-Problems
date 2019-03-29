class Solution {
public:
  double myPow(double x, int n) {
    if (!x) return 0;
    unsigned int nn = n;
    if (n < 0) {
      nn = ~n;
      nn += 1;
      x = 1 / x;
    }
    double tmp = x, res = 1;
    while (nn) {
      if (nn & 1) res *= tmp;
      tmp *= tmp;
      nn >>= 1;
      if (!res) return 0;
    }
    return res;
  }
};

class Solution {
public:
  double myPow(double x, int n) {
    if (!n) return 1;
    if (n & 1) {
      if (n > 0) return x * myPow(x, n - 1);
      return (1 / x) * myPow(x, n + 1);
    }
    return myPow(x * x, n / 2);
  }
};