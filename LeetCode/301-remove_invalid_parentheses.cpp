class Solution {
public:
  vector<int> lvec, rvec;
  vector<string> remove(string& s, int idx, int invl, int invr, int prev, int rem) {
    vector<string> res;
    if (invl < lvec[idx] ||      // every invalid ( in the suffix should be invalid originally
        invr > rvec[idx])        // some )s might not be invalid, so invr should <= rvec[idx]
      return res;
    if (invl == 0 && invr == 0) {
      return {s.substr(idx, s.length() - idx)};
    }
    
    if (idx == s.length()) {
      return res;
    }
    int r = 0, p = 0;
    if (s[idx] != '(' && s[idx] != ')') r = 1;
    else if (s[idx] == ')') p = 1;
    res = remove(s, idx + 1, invl, invr, p, r);
    for (auto &str : res) {
      str = s[idx] + str;
    }
    if ((s[idx] == '(' && (prev == 1 || rem == 1)) ||
        (s[idx] == ')' && (prev == 0 || rem == 1))) {
      for (auto &str : remove(s, idx + 1, invl - (s[idx] == '('), invr - (s[idx] == ')'), p, 1)) {
        res.push_back(str);
      }
    }   
    return res;
  }
  vector<string> removeInvalidParentheses(string s) {
    int invl = 0, invr = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
      lvec.push_back(invl);
      rvec.push_back(invr);
      if (s[i] != '(' && s[i] != ')') continue;
      if (s[i] == ')') invr++;
      else if (!invr) invl++;
      else invr--;
    }
    lvec.push_back(invl);
    rvec.push_back(invr);
    reverse(lvec.begin(), lvec.end());
    reverse(rvec.begin(), rvec.end());
    return remove(s, 0, invl, invr, 0, 1);
  }
};