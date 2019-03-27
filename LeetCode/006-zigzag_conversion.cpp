class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    vector<string> res(numRows, "");
    string ans;
    int r = 0, fb = 0;
    for (int i = 0; i < s.length(); ++i) {
      res[r] += s[i];
      if (r == 0) {
        r++;
        fb = 0;
      }
      else if (r == numRows - 1) {
        r--;
        fb = 1;
      }
      else if (!fb) r++;
      else if (fb) r--;
    }
    for (int i = 0; i < numRows; ++i) ans += res[i];
    return ans;
  }
};