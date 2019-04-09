// dp solution with O(n^2) space
// Keep characters that are in both word1 and word2 as much as possible
// to save edits. So this problem is quite similar to LCS, but the difference
// is characters in LCS might be in different position so it can't be just 
// replace every character that is not in LCS and remove(or insert) the rest.
// There might be both insert and remove operations.
// But the idea of LCS can be borrowed. At a certain position where two characters
// are the same, the total edits would not be added. Else we choose the minimum
// among insert(dp[i][j + 1]), remove(dp[i + 1][j]), or replace(dp[i][j]).
class Solution {
public:
  int minDistance(string word1, string word2) {
    int l1 = word1.length(), l2 = word2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i <= l1; ++i) dp[i][0] = i;
    for (int j = 0; j <= l2; ++j) dp[0][j] = j;
    for (int i = 0; i < l1; ++i) {
      for (int j = 0; j < l2; ++j) {
        if (word1[i] == word2[j]) dp[i + 1][j + 1] = dp[i][j];
        else dp[i + 1][j + 1] = min(dp[i][j + 1], min(dp[i + 1][j], dp[i][j])) + 1;
      }
    }
    return dp[l1][l2];
  }
};