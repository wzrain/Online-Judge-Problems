// dp[i][j] indicates whether we could reach the position i after a jump of j units.
class Solution {
public:
    void dfs(unordered_map<int, unordered_set<int>>& dp, int idx, int stp, unordered_set<int>& stones) {
        for (int d = -1; d <= 1; ++d) {
            int ns = stp + d;
            int nx = ns + idx;
            if (nx <= 0) continue;
            if (stones.find(nx) != stones.end() && dp[nx].find(ns) == dp[nx].end()) {
                dp[nx].insert(ns);
                dfs(dp, nx, ns, stones);
            }
        }
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        unordered_set<int> stn;
        for (int i = 0; i < stones.size(); ++i) {
            stn.insert(stones[i]);
        }
        dfs(dp, 0, 0, stn);
        return dp.find(stones.back()) != dp.end();
    }
};

// dp[i][j] indicates whether we could reach the bank after a jump of j units to position i
class Solution {
public:
    bool dfs(unordered_map<int, unordered_map<int, int>>& dp, int idx, int stp, unordered_set<int>& stones, int tgt) {
        if (idx == tgt) return true;
        if (dp.find(idx) != dp.end() && dp[idx].find(stp) != dp[idx].end()) return dp[idx][stp]; 
        for (int d = -1; d <= 1; ++d) {
            int ns = stp + d;
            int nx = ns + idx;
            if (nx <= 0 || ns <= 0) continue;
            if (stones.find(nx) != stones.end()) {
                if (dfs(dp, nx, ns, stones, tgt)) {
                    dp[idx][stp] = 1;
                    return 1;
                }
            }
        }
        dp[idx][stp] = 0;
        return 0;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_map<int, int>> dp;
        unordered_set<int> stn;
        for (int i = 0; i < stones.size(); ++i) {
            stn.insert(stones[i]);
        }
        return dfs(dp, 0, 0, stn, stones.back());
    }
};