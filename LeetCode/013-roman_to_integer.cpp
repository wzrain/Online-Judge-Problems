class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> dc = {
      make_pair('I', 1), make_pair('V', 5), make_pair('X', 10), make_pair('L', 50), 
      make_pair('C', 100), make_pair('D', 500), make_pair('M', 1000)};
    int res = 0, i = s.length() - 1;
    // while (i >= 0) {
    //   if (i > 0 && 
    //       ((s[i - 1] == 'I' && (s[i] == 'V' || s[i] == 'X')) ||
    //        (s[i - 1] == 'X' && (s[i] == 'L' || s[i] == 'C')) ||
    //        (s[i - 1] == 'C' && (s[i] == 'D' || s[i] == 'M')))) {
    //     res += (dc[s[i]] - dc[s[i - 1]]);
    //     i -= 2;
    //   }
    //   else res += dc[s[i--]];
    // }
    for (int i = 0; i < s.length(); ++i) {
      // The special case is different for the reverse order.
      // So no need to check the particular character. Only check the order.
      if (i < s.length() + 1 && dc[s[i]] < dc[s[i + 1]]) res -= dc[s[i]];
      else res += dc[s[i]];
    }
    return res;
  }
};