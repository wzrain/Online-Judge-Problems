class Solution {
public:
  bool validPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    int del = 0, li, lj;
    while (i < j) {
      if (s[i] != s[j]) {
        if (del == 2) return false;
        if (del == 0) {
          lj = j--;
          li = i;
        }
        else {
          i = ++li;
          j = lj;
        }
        del++;
      }
      else {
        i++;
        j--;
      }
    }
    return true;
  }
};