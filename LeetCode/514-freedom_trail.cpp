// O(mn^2) dp
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int rlen = ring.length(), klen = key.length();
        vector<vector<int>> pos(26);
        for (int i = 0; i < rlen; ++i) {
            int let = ring[i] - 'a';
            pos[let].push_back(i);
        }
        vector<vector<int>> dp(rlen, vector<int>(klen + 1, INT_MAX));
        for (int i = 0; i < rlen; ++i) {
            dp[i][klen] = 0;
        }
        for (int j = klen - 1; j >= 0; --j) {
            int curlet = key[j] - 'a';
            for (int i = 0; i < rlen; ++i) {
                for (int p : pos[curlet]) {
                    int lf = min(i, p), rt = max(i, p);
                    int dis = min(rt - lf, lf + rlen - rt);
                    dp[i][j] = min(dp[i][j], dis + 1 + dp[p][j + 1]);
                }   
            }
        }
        return dp[0][0];
    }
};

// no need to traverse every position for every key character because the prev state can only
// be at the characters of the previous key char
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int rlen = ring.length(), klen = key.length();
        vector<vector<int>> pos(27);
        for (int i = 0; i < rlen; ++i) {
            int let = ring[i] - 'a';
            pos[let].push_back(i);
        }
        pos[26].push_back(0);
        vector<vector<int>> dp(rlen, vector<int>(klen + 1, INT_MAX));
        for (int i = 0; i < rlen; ++i) {
            dp[i][klen] = 0;
        }
        for (int j = klen - 1; j >= 0; --j) {
            int curlet = key[j] - 'a';
            int prev = j > 0 ? key[j - 1] -'a' : 26;
            for (int pv : pos[prev]) {
                for (int p : pos[curlet]) {
                    int lf = min(pv, p), rt = max(pv, p);
                    int dis = min(rt - lf, lf + rlen - rt);
                    dp[pv][j] = min(dp[pv][j], dis + 1 + dp[p][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};

// top down dp
// only visit possible states like the second bottom-up dp
class Solution {
public:
    int dfs(string& ring, string& key, int ri, int ki, vector<vector<int>>& dp, vector<vector<int>>& pos) {
        if (ki == key.length()) return 0;
        if (dp[ri][ki] != -1) return dp[ri][ki];
        int curlet = key[ki] - 'a';
        int res = INT_MAX;
        for (int p : pos[curlet]) {
            int lf = min(p, ri), rt = max(p, ri);
            int dis = min(rt - lf, lf + (int)ring.length() - rt);
            res = min(res, dis + 1 + dfs(ring, key, p, ki + 1, dp, pos));
        }
        dp[ri][ki] = res;
        return res;
    }
    int findRotateSteps(string ring, string key) {
        int rlen = ring.length(), klen = key.length();
        vector<vector<int>> pos(26);
        for (int i = 0; i < rlen; ++i) {
            int let = ring[i] - 'a';
            pos[let].push_back(i);
        }
        vector<vector<int>> dp(rlen, vector<int>(klen, -1));
        return dfs(ring, key, 0, 0, dp, pos);
    }
};