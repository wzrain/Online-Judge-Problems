// brute force big int multiplication
// too many meaningless add operation with "0"
class Solution {
public:
  void add(string& s1, string& s2) {
    int l1 = s1.length(), l2 = s2.length(), addtmp = 0, i = 0;
    while (i < l1 && i < l2) {
      int tmp = (s1[l1 - i - 1] - '0') + (s2[l2 - i - 1] - '0') + addtmp;
      addtmp = tmp / 10;
      s1[l1 - i - 1] = (char)(tmp % 10 + '0');
      i++;
    }
    while (i < l1) {
      int tmp = (s1[l1 - i - 1] - '0') + addtmp;
      addtmp = tmp / 10;
      s1[l1 - i - 1] = (char)(tmp % 10 + '0');
      i++;
    }
    while (i < l2) {
      int tmp = (s2[l2 - i - 1] - '0') + addtmp;
      addtmp = tmp / 10;
      s1 = (char)(tmp % 10 + '0') + s1;
      i++;
    }
    if (addtmp) s1 = "1" + s1;
  }
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int l1 = num1.length(), l2 = num2.length();
    string res = "0", zo = "";
    for (int i = l1 - 1; i >= 0; --i) {
      string tmps = zo;
      zo += "0";
      int addtmp = 0;
      for (int j = l2 - 1; j >= 0; --j) {
        int tmp = (num1[i] - '0') * (num2[j] - '0') + addtmp;
        addtmp = tmp / 10;
        tmps = (char)(tmp % 10 + '0') + tmps;
      }
      if (addtmp) tmps = (char)(addtmp + '0') + tmps;
      add(res, tmps);
    }
    return res;
  }
};

// num1[i] * num2[j] will only influence two digits in the result
class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int l1 = num1.length(), l2 = num2.length();
    string res(l1 + l2, '0');
    for (int i = l1 - 1; i >= 0; --i) {
      for (int j = l2 - 1; j >= 0; --j) {
        int tmp = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0');
        res[i + j] += tmp / 10; // This may be larger than 9 and temporarily be a non-digit char, but that will 
                                // be used as addtmp later. The highest digit won't be larger than 9. So no problem.
        res[i + j + 1] = (char)(tmp % 10 + '0');
      }
    }
    return res[0] == '0' ? res.substr(1) : res;
  }
};