class Solution {
public:
  string removeDuplicateLetters(string s) {
    if (s.empty()) return s;
    unordered_map<char, int> last;
    vector<char> res;
    for (int i = s.length() - 1; i >= 0; --i) {
      if (last.find(s[i]) == last.end()) last[s[i]] = i;
    }
    res.push_back(s[0]);
    unordered_set<char> has;
    has.insert(s[0]);
    for (int i = 1; i < s.length() ; ++i) {
      if (has.find(s[i]) != has.end()) continue;
      while (!res.empty() && s[i] < res.back() && 
             last[res.back()] > i) {
        has.erase(res.back());
        res.pop_back();
      }
      res.push_back(s[i]);
      has.insert(s[i]);
    }
    string ans;
    for (int i = 0; i < res.size(); ++i) ans += res[i];
    return ans;
  }
};