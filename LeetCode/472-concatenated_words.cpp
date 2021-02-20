class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        auto cmp = [](const string& s1, const string& s2) {
            if (s1.length() != s2.length()) return s1.length() < s2.length();
            return s1 < s2;
        };
        sort(words.begin(), words.end(), cmp);
        Node* head = new Node();
        head->isWord = false;
        vector<string> res;
        for (auto& wd : words) {
            if (exist(head, wd, 0)) res.push_back(wd);
            else {
                Node* nd = head;
                for (char c : wd) {
                    int cur = c - 'a';
                    if (!nd->next[cur]) nd->next[cur] = new Node();
                    nd = nd->next[cur];
                }
                nd->isWord = true;
            }
        }
        return res;
    }
private:
    struct Node {
        Node* next[26];
        bool isWord;
    };

    // dfs to find out whether substr(str, idx) can be concatenated 
    bool exist(Node* head, string& str, int idx) {
        int len = str.length();
        if (!len) return false;
        if (idx == len) return true;
        Node* nd = head;
        for (int i = idx; i < len; ++i) {
            int cur = str[i] - 'a';
            if (!nd->next[cur]) return false;
            nd = nd->next[cur];
            if (nd->isWord && exist(head, str, i + 1)) return true; 
        }
        return false;
    }
};