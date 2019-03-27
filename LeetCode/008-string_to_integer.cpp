class Solution {
public:
  int myAtoi(string str) {
    int i = 0, mark = 1, res = 0;
    while (i < str.length() && (str[i] < '0' || str[i] > '9')) {
      if (str[i] != ' ' && str[i] != '-' && str[i] != '+') return 0;
      if (str[i] == '-' || str[i] == '+') break;
      i++;
    }
    if (i == str.length()) return 0;
    if (str[i] == '-' || str[i] == '+') {
      if (str[i] == '-') mark = -1;
      i++;
    }
    while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
      if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) {
        if (mark == 1) return INT_MAX;
        if (mark == -1) return INT_MIN;
      }  
      res *= 10;
      res += (str[i] - '0');
      i++;
    }
    return mark * res;
  }
};