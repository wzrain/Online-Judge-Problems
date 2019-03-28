class Solution {
public:
  int divide(int dividend, int divisor) {
    int mark = 1;
    if ((dividend ^ divisor) < 0) mark = -1;
    // Here make both dividend and divisor negative to avoid overflow from INT_MIN
    if (dividend > 0) dividend = -dividend;
    if (divisor > 0) divisor = -divisor;
    int res = 0, tmp = divisor, ele = -1;
    while (dividend <= tmp) {
      res += ele;
      dividend -= tmp;
      if (tmp < INT_MIN - tmp) break;
      tmp += tmp;
      ele += ele;
    }
    // If the loop ends because of tmp * 2 < INT_MIN, and still dividend <= tmp,
    // that means tmp == divisor. Otherwise, dividend + tmp (which equals to the
    // value of dividend before the previous step) < INT_MIN. Contradiction.
    // So dividend > tmp entering the following loop.
    // So executing tmp >>= 1 first is ok and necessary.
    while (dividend < 0 && tmp < divisor) {
      tmp >>= 1;
      ele >>= 1;
      if (dividend <= tmp) {
        dividend -= tmp;
        res += ele;
      }
    }
    // an alternative for the previous two loops:
    // while (dividend <= tmp) {
    //   while (dividend <= tmp) {
    //     res += ele;
    //     dividend -= tmp;
    //     if (tmp < INT_MIN - tmp) break;
    //     tmp += tmp;
    //     ele += ele;
    //   }
    //   ele = -1;
    //   tmp = divisor;
    // }
    if (mark == -1) return res;
    if (res == INT_MIN && mark == 1) return INT_MAX;
    return -res;
  }
};