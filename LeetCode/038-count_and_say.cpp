class Solution {
public:
  string countAndSay(int n) {
    if (n == 1) return "1";
    string tmp = countAndSay(n - 1), res = "";
    int cnt = 0;
    tmp += "a";
    for (int i = 0; i < tmp.length(); ++i) {
      if (i > 0 && tmp[i] != tmp[i - 1]) {
        res += to_string(cnt);
        res += tmp[i - 1];
        cnt = 1;
      }
      else cnt++;
    }
    return res;
  }
};