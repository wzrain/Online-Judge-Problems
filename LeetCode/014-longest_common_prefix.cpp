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

// Trie solution. The common prefix stops at latest at isWord.
class Solution {
public:
    struct TrieNode {
        int idx;
        bool isWord;
        TrieNode* next[26];
        TrieNode() {
            idx = -1;
            isWord = false;
            for (int i = 0; i < 26; ++i) {
                next[i] = NULL;
            }
        }
    };
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        TrieNode* root = new TrieNode();
        for (int i = 0; i < strs.size(); ++i) {
            TrieNode* cur = root;
            for (char c : strs[i]) {
                int idx = c - 'a';
                if (!cur->next[idx]) {
                    if (cur->idx >= 0 || cur->isWord) break;
                    cur->idx = idx;
                    cur->next[idx] = new TrieNode();
                }
                cur = cur->next[idx];
            }
            cur->isWord = true;
        }
        TrieNode* cur = root;
        while (cur && cur->idx >= 0 && !cur->isWord) {
            char c = cur->idx + 'a';
            res += c;
            cur = cur->next[cur->idx];
        }
        return res;
    }
};