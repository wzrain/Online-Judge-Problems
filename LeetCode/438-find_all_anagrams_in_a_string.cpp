class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    if (s.length() < p.length()) return {};
    vector<int> res;
    unordered_map<char, int> ps;
    for (int i = 0; i < p.length(); ++i) {
      if (ps.find(p[i]) == ps.end()) ps[p[i]] = 1;
      else ps[p[i]]++;
    }
    int l = 0, r = 0, cnt = ps.size();
    while (r <s.length()) {
      if (l == r && ps.find(s[l]) == ps.end()) {
        l++;
        r++;
        continue;
      }
      if (ps.find(s[r]) != ps.end()) {
        while (l != r && ps[s[r]] == 0) { // certain letter more than expected
          if (!ps[s[l]]) cnt++;
          ps[s[l++]]++;
        }
        ps[s[r]]--;
        if (!ps[s[r]]) cnt--;
        if (!cnt) {
          res.push_back(l);
          ps[s[l++]]++;
          cnt++;
        }
        r++;
      }
      else { // none of the substring in the current window would be an answer
        while (l != r) {
          if (!ps[s[l]]) cnt++;
          ps[s[l++]]++;
        }
        l++;
        r++;
      }
    }
    if (!cnt) {
      res.push_back(l);
    }
    return res;
  }
};