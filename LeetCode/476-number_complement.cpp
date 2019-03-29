class Solution {
public:
  int findComplement(int num) {
    int res = 0, cnt = 0;
    while (num) {
      if (!(num & 1)) res += (1 << cnt);
      num >>= 1;
      cnt++;
    }
    return res;
  }
};

// bit manipulation only
// use 1 and & to find 0's
class Solution {
public:
  int findComplement(int num) {
    unsigned int mask = ~0;
    while (num & mask) mask <<= 1;
    return ~mask & ~num;
  }
};