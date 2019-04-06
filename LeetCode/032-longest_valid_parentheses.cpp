// Use a stack to record the index rather than the character itself
// So when characters match we can know how far these two charcters are.
class Solution {
public:
  int longestValidParentheses(string s) {
    vector<int> sz(s.size() + 1, -1); // sz[i] the last index where
                                      // there are i '('s remaining
                                      // unmatched
    int res = 0, top = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == ')') {
        if (!top) sz[0] = i; // no way there are valid parentheses
        else res = max(res, i - sz[--top]); // get a valid one
      }
      else sz[++top] = i; // Only update sz[1+] when new '(' comes
                          // to get situations like "()()" considered.
    }
    return res;
  }
};