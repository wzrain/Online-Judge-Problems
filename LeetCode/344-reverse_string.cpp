// use xor to swap elements
class Solution {
public:
  void reverseString(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
      int j = s.size() - i - 1;
      s[i] = s[i] ^ s[j];
      s[j] = s[i] ^ s[j];
      s[i] = s[i] ^ s[j];
    } //swap(s[i], s[s.size() - i - 1]);
  }
};