class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> res = {""};
    unordered_map<int, vector<char>> mp;
    mp[2] = {'a', 'b', 'c'};
    mp[3] = {'d', 'e', 'f'};
    mp[4] = {'g', 'h', 'i'};
    mp[5] = {'j', 'k', 'l'};
    mp[6] = {'m', 'n', 'o'};
    mp[7] = {'p', 'q', 'r', 's'};
    mp[8] = {'t', 'u', 'v'};
    mp[9] = {'w', 'x', 'y', 'z'};
    for (int i = 0; i < digits.length(); ++i) {
      int dg = digits[i] - '0', sz = res.size();
      for (int j = 0; j < sz; ++j) {
        for (int k = 1; k < mp[dg].size(); ++k) {
          res.push_back(res[j]);
          res.back() += mp[dg][k];
        }
        res[j] += mp[dg][0];
      }
    }
    return res;
  }
};