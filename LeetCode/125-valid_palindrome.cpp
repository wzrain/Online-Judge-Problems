class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      if (s[i] == s[j] ||
          (s[i] >= 'A' && s[i] - 'A' == s[j] - 'a') ||
          (s[j] >= 'A' && s[j] - 'A' == s[i] - 'a')) {
        i++;
        j--;
        continue;
      }
      if (!((s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= 'A' && s[i] <= 'Z') || 
            (s[i] >= '0' && s[i] <= '9'))) i++;
      else if (!((s[j] >= 'a' && s[j] <= 'z') || 
                 (s[j] >= 'A' && s[j] <= 'Z') ||
                 (s[j] >= '0' && s[j] <= '9'))) j--;
      else return false;
    }
    return true;
  }
};