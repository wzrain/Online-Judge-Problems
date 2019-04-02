// judge if there exists a loop
// instead of using hashset use two pointers to chase each other.
class Solution {
public:
  int sqrSum(int n) {
    int sum = 0;
    while (n > 0) {
      sum += ((n % 10) * (n % 10));
      n /= 10;
    }
    return sum;
  }
  bool isHappy(int n) {
    int s = sqrSum(n), f = sqrSum(s);
    while (s != f) {
      s = sqrSum(s);
      f = sqrSum(f);
      f = sqrSum(f);
    }
    return s == 1;
  }
};