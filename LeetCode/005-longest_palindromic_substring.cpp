class Solution {
public:
  string longestPalindrome(string s) {
    string res;
    int len = 0;
    for (int i = 0; i < s.length(); ++i) {
      int l = i - 1, r = i + 1;
      while (l >= 0 && r < s.length() && s[l] == s[r]) {
        l--;
        r++;
      }
      if (r - l - 1 > len) {
        len = r - l - 1;
        res = s.substr(l + 1, len);
      }
      if (i < s.length() - 1 && s[i] == s[i + 1]) {
        l = i - 1, r = i + 2;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
          l--;
          r++;
        }
        if (r - l - 1 > len) {
          len = r - l - 1;
          res = s.substr(l + 1, len);
        }
      }
    }
    return res;
  }
};