class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    for (int i = 0; i < t.length(); ++i) mp[t[i]]++;
    int cnt = mp.size();
    int i = 0, j = 0, res = INT_MAX, st = -1;
    while (j < s.length()) {
      if (mp.find(s[j]) != mp.end()) {
        mp[s[j]]--;
        if (mp[s[j]] == 0) cnt--;
        while (!cnt) {
          if (mp.find(s[i]) != mp.end()) {
            mp[s[i]]++;
            if (mp[s[i]] > 0) {
              cnt++;
              if (res > j - i + 1) {
                res = j - i + 1;
                st = i;
              }
            }
          }
          i++;
        }
      }
      j++;
    }
    return res == INT_MAX ? "" : s.substr(st, res);
  }
};