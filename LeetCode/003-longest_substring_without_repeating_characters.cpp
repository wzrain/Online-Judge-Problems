class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    vector<int> st(200, 0);
    int i = 0, j = 0;
    while (j < s.length()) {
      if (!st[s[j] - '\0']) st[s[j++] - '\0'] = 1;
      else {
        if (res < j - i) res = j - i;
        while (st[s[j] - '\0']) st[s[i++] -'\0'] = 0;
      }
    }
    if (res < j - i) res = j - i;
    return res;
  }
};