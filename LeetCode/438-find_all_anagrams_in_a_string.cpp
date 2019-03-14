// If there's on single mismatch, narrow or leap the window.
class Solution_1 {
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

// let the character num match, check the length
class Solution_2 {
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
    while (r < s.length()) {
      if (ps.find(s[r]) != ps.end()) {
        ps[s[r]]--;
        if (!ps[s[r]]) cnt--;
      }
      ++r;
      while (!cnt) {
        if (r - l == p.length()) {
          res.push_back(l);
        }
        if (ps.find(s[l]) != ps.end()) {
          if (!ps[s[l]]) cnt++;
          ps[s[l]]++;
        }
        l++;
      }
    }
    return res;
  }
};

// set the length, check whether the characters match.
class Solution_3 {
public:
  vector<int> findAnagrams(string s, string p) {
    if (s.length() < p.length()) return {};
    vector<int> res;
    vector<int> pv(26, 0), sv(26, 0);
    for (int i = 0; i < p.length(); ++i) {
      sv[s[i] - 'a']++;
      pv[p[i] - 'a']++;
    }
    if (sv == pv) res.push_back(0);
    for (int i = p.length(); i < s.length(); ++i) {
      sv[s[i] - 'a']++;
      sv[s[i - p.length()] - 'a']--;
      if (sv == pv) res.push_back(i - p.length() + 1);
    }
    return res;
  }
};