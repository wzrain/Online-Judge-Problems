class Solution {
public:
  string intToRoman(int num) {
    string res = "";
    vector<pair<int, char>> dc = {
      make_pair(1000, 'M'), make_pair(500, 'D'), make_pair(100, 'C'), 
      make_pair(50, 'L'), make_pair(10, 'X'), make_pair(5, 'V'), make_pair(1, 'I')};
    for (int i = 0; i < dc.size(); i += 2) {
      if (num / dc[i].first == 0) continue;
      int n = num /  dc[i].first;
      if (n == 9) {
        res += dc[i].second;
        res += dc[i - 2].second;
      }
      else if (n >= 5) {
        res += dc[i - 1].second;
        for (int j = 0; j < n - 5; ++j) res += dc[i].second;
      }
      else if (n == 4) {
        res += dc[i].second;
        res += dc[i - 1].second;
      }
      else for (int j = 0; j < n; ++j) res += dc[i].second;
      num %= dc[i].first;
    }
    return res;
  }
};