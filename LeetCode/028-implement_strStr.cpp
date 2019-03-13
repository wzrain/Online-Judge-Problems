class Solution {
public:
    int strStr(string haystack, string needle) {
      if (needle.empty()) return 0;
      vector<int> next(needle.length(), 0);
      next[0] = -1;
      for (int j = 1; j < needle.length(); ++j) {
        int tmp = next[j - 1];
        while (tmp != -1 && needle[tmp] != needle[j - 1]) {
          tmp = next[tmp];
        }
        if (tmp == -1) next[j] = 0;
        else next[j] = tmp + 1;
      }
      int st = -1, i = 0, j = 0;
      for (int idx = 0; idx < next.size(); ++idx)cout<< next[idx]<<endl;
      while (st == -1 && i < haystack.length()) {
        if (haystack[i] == needle[j]) {
          i++;
          j++;
        }
        else {
          j = next[j];
          if (j == -1) {
            i++;
            j = 0;
          }
        }
        if (j == needle.length()) {
          st = i - j;
        }
      }
      return st;
    }
};