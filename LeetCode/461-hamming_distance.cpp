class Solution {
public:
  int hammingDistance(int x, int y) {
    int res = 0;
    unsigned int tmp = x ^ y;
    while (tmp != 0) {
      if ((tmp & 0xFFFFFFFF) >= 0x80000000) res++;
      tmp <<= 1;
    }
    return res;
  }
};