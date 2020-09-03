// The trivial solution is O(kn^2). An improvement could be inspired by the fact
// that if we reverse the word, then palindrome pairs should have the same prefix.
// So we might do not need to check all pairs, but could use two pointers on the
// original vector and the vector with reverse words. 
// Actually, the "prefix" leads to using Trie. Just do one-to-many matching for
// every reversed words on the Trie built via original words, and check whether
// the suffices are palindrome when we encounter a whole word on the Trie and after
// the prefix is matched to some original words.
class Solution {
public:
    struct Node {
        int idx = -1;
        vector<int> wds;
        vector<Node*> branch;
        Node() {
            idx = -1;
            branch = vector<Node*>(26, NULL);
        }
    };
    bool isPalindrome(string&& tmp) {
        int n = tmp.length();
        int i = 0, j = n - 1;
        while (i < j) {
            if (tmp[i] != tmp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        
        Node* root = new Node();
        
        for (int i = 0; i < n; ++i) {
            Node* cur = root;
            int len = words[i].length();
            for (int j = 0; j < len; ++j) {
                cur->wds.push_back(i);
                
                int curidx = words[i][j] - 'a';
                if(!cur->branch[curidx]) {
                    cur->branch[curidx] = new Node();
                }
                cur = cur->branch[curidx];
            }
            cur->idx = i;
        }
        
        for (int i = 0; i < n; ++i) {
            reverse(words[i].begin(), words[i].end());
            Node* cur = root;
            int len = words[i].length();
            bool flag = true;
            for (int j = 0; j < len; ++j) {
                if (cur->idx >= 0 && cur->idx != i) {
                    if (isPalindrome(words[i].substr(j, len - j))) {
                        res.push_back({cur->idx, i});
                    }
                }
                int ch = words[i][j] - 'a';
                if (!cur->branch[ch]) {
                    flag = false;
                    break;
                }
                cur = cur->branch[ch];
            }
            reverse(words[i].begin(), words[i].end());
            if (!flag) continue;
            
            for (int j = 0; j < cur->wds.size(); ++j) {
                int curidx = cur->wds[j];
                if (curidx != i && isPalindrome(words[curidx].substr(len, words[curidx].length() - len))) {
                    res.push_back({curidx, i});
                }
            }
            if (cur->idx >= 0 && cur->idx != i) {
                res.push_back({cur->idx, i});
            }
        }
        
        return res;
    }
};