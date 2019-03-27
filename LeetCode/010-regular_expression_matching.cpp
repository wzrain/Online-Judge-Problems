// recursive solution
class Solution {
public:
  bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    if (s.empty()) {
      for (int i = 0; i < p.length(); ++i) {
        if (p[i] != '*' && (i + 1 >= p.length() || p[i + 1] != '*')) return false;
      }
      return true;
    }
    if (s[0] == p[0] || p[0] == '.') {
      if (p.length() <= 1 || p[1] != '*') {
        return isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
      } 
      else {
        if (isMatch(s, p.substr(2, p.length() - 2))) return true;
        for (int i = 0; i < s.length(); ++i) {
          if (p[0] != '.' && s[i] != p[0]) break;
          if (isMatch(s.substr(i + 1, s.length() - i - 1), p.substr(2, p.length() - 2))) return true;
        }
        return false;
      }           
    }
    else if (p.length() > 1 && p[1] == '*') return isMatch(s, p.substr(2, p.length() - 2));
    return false;
  }
};