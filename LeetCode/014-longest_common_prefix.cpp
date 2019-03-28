class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string res;
    int idx = 0;
    while (1) {
      for (int i = 0; i < strs.size(); ++i) {
        if (idx >= strs[i].length() || strs[i][idx] != strs[0][idx]) return res; 
      }
      res += strs[0][idx++];
    }
    return res;
  }
};