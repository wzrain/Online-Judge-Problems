class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, int> mp = {
      make_pair('(', 1), make_pair(')', -1),
      make_pair('[', 2), make_pair(']', -2),
      make_pair('{', 3), make_pair('}', -3),
    };
    vector<int> stk;
    for (int i = 0; i < s.length(); ++i) {
      if (mp[s[i]] > 0) stk.push_back(mp[s[i]]);
      else if (!stk.empty() && mp[s[i]] + stk.back() == 0) { // Always check whether the container is empty
                                                             // when trying to fetch elements from it.
        stk.pop_back();
      }
      else return false;
    }
    return stk.empty();
  }
};