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
    /*
     * In the previous two-loop solution, after the first loop, 
     * the dividend(here assume the value are all positive for convenience) 
     * is no greater than divisor * (1 + 2 + ... + 2 ^ n) where divisor * 2 ^ (n + 1) == tmp
     * because dividend < tmp = divisor * (1 + 2 + ... + 2 ^ n) - 1.
     * So the add sequence is like 1 + 2 + ... + 2 ^ k + 2 ^ k + ... + 2 + 1.
     * While this solution is like 1 + 2 + ... + 2 ^ k + 1 + 2 + ... + 2 ^ m + 1 ...
     * So if the answer is like 1 + 2 + 4 + ... 2 ^ k, Then this solution needs no more
     * execution, but the previous solution still have to calculate tmp >>= 1 and 
     * ele >>= 1 until tmp == divisor.
     * If the answer is like 1 + 2 + 4 + ... + 2 ^ k + 2 ^ k, this solution will 
     * calculate a lot of 1 + 2 + ... to fill that extra 2 ^ k, but the previous solution
     * will just add 2 ^ k and break.
     * However if there are remainders, the previous solution will still have to calculate
     * until tmp == divisor.  
     */
    if (mark == -1) return res;
    if (res == INT_MIN && mark == 1) return INT_MAX;
    return -res;
  }
};