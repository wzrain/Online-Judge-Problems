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

// record the last index where a character appeared
// if the current character's last index is larger than 
// the left index of the sliding window, there occurs duplicates.
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0, left = 0;
    vector<int> st(200, -1);
    for (int i = 0; i < s.length(); ++i) {
      if (st[s[i]] >= left) {
        if (res < i - left) res = i - left;
        left = st[s[i]] + 1;
      }
      st[s[i]] = i;
    }
    if (res < s.length() - left) res = s.length() - left;
    return res;
  }
};