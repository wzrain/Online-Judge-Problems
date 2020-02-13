class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    struct TrieNode {
        string word;
        TrieNode* next[26];
        TrieNode() {
            for (int i = 0; i < 26; ++i) {
                next[i] = NULL;
            }
        }
    };
    void insert(TrieNode* root, string& word) {
        TrieNode* cur = root;
        for (char wd : word) {
            int idx = wd - 'a';
            if (cur->next[idx] == NULL) {
                cur->next[idx] = new TrieNode();
            }
            cur = cur->next[idx];
        }
        cur->word = word;
    }
    void dfs(vector<vector<char>>& board, int i, int j, vector<string>& res, TrieNode* cur) {
        int rn = board.size(), cn = board[0].size();
        if (cur->word != "") {
            res.push_back(cur->word);
            cur->word = "";
        }
        for (int d = 0; d < 4; ++d) {
            int ni = i + dir[d], nj = j + dir[d + 1];
            if (ni < 0 || nj < 0 || ni >= rn || nj >= cn || board[ni][nj] == 'X') continue;
            if (cur->next[board[ni][nj] - 'a'] == NULL) continue;
            char c = board[ni][nj];
            board[ni][nj] = 'X';
            dfs(board, ni, nj, res, cur->next[c - 'a']);
            board[ni][nj] = c;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            insert(root, word);
        }
        vector<string> res;
        int rn = board.size(), cn = board[0].size();
        for (int i = 0; i < rn; ++i) {
            for (int j = 0; j < cn; ++j) {
                if (root->next[board[i][j] - 'a'] == NULL) continue;
                char c = board[i][j];
                board[i][j] = 'X';
                dfs(board, i, j, res, root->next[c - 'a']);
                board[i][j] = c;
            }
        }
        return res;
    }
};