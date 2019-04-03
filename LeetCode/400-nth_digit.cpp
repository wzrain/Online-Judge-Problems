class Solution {
public:
  int findNthDigit(int n) {
    int bd = 0, i = 1, base = 1; // If the statement is like pow(base, i) where i increases within the loop,
                                 // it's good to set a base and multiply with base every loop.
                                 // pow(k, i) returns double values which are of larger range than int. 
    for (i = 1; i < 9; ++i) {
      if (n > bd + 9 * i * base) {
        bd += 9 * i * base;
        base *= 10;
        continue;
      }
      break;
    }
    // similar loop
    // while (INT_MAX / 10 > 9 * i * (base / 10)) {
    //   if (n > bd + 9 * i * base) {
    //     bd += 9 * i * base;
    //     i++;
    //     base *= 10;
    //     continue;
    //   } 
    //   break;
    // }
    n -= bd;
    int idx = (n - 1) / i, cnt = (n - 1) % i;
    int num = base + idx;
    while (i - cnt > 1) {
      num /= 10;
      cnt++;
    }
    return num % 10;
  }
};