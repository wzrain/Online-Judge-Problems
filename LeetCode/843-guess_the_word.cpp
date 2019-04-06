/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
  int match(string& a, string& b) {
    int res = 0;
    for (int i = 0; i < 6; ++i) {
      if (a[i] == b[i]) res++;
    }
    return res;
  }
  void findSecretWord(vector<string>& wordlist, Master& master) {
    for (int i = 0; i < 10; ++i) {
      string cur = wordlist[rand() % (wordlist.size())];
      int res = master.guess(cur);
      if (res == 6) return;
      vector<string> newlist;
      for (int j = 0; j < wordlist.size(); ++j) {
        if (match(wordlist[j], cur) == res) {  // The secret string will be in the new wordlist.
                                               // All strings that have a different match result
                                               // from the std string we selected randomly previouly
                                               // cannot be the secret string.
          newlist.push_back(wordlist[j]);
        }
      }
      wordlist = newlist;
    }
  }
};

// The key to quick guessing is to shrink the candidate pool
// as quick as possible. Last solution used random selection
// to pick a candidate and use the feature(matched character
// number with secret) to narrow the scope. It could be better
// to pick the candidate from a statistic view.
// One way is to pick the string with which there are the fewest 
// string having a distance of 0. Since the secret is also among
// these strings, it's the least likely to get the worst result.
// By the way since the strings are randomly generated, it's very
// possible that two strings have no characters matched((25/26)^6).
class Solution {
public:
  int match(string& a, string& b) {
    int res = 0;
    for (int i = 0; i < 6; ++i) {
      if (a[i] == b[i]) res++;
    }
    return res;
  }
  void findSecretWord(vector<string>& wordlist, Master& master) {
    for (int i = 0; i < 10; ++i) {
      int mincnt = INT_MAX;
      string cur;
      for (auto &ws : wordlist) {
        int cnt = 0;
        for (auto &ws2 : wordlist) {
          if (match(ws, ws2) == 0) cnt++;
        }
        if (cnt < mincnt) {
          mincnt = cnt;
          cur = ws;
        }
      }
      int res = master.guess(cur);
      if (res == 6) return;
      vector<string> newlist;
      for (int j = 0; j < wordlist.size(); ++j) {
        if (match(wordlist[j], cur) == res) {
          newlist.push_back(wordlist[j]);
        }
      }
      wordlist = newlist;
    }
  }
}; 