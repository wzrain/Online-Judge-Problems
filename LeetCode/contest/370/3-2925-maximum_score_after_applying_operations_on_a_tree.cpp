class Solution {
public:
    long long dfs(unordered_map<int, vector<int>>& tree, vector<int>& values, vector<vector<long long>>& dp, int curr, int pre, int healthy) {
        if (dp[curr][healthy] != -1) return dp[curr][healthy];
        dp[curr][healthy] = 0;
        int numadj = tree[curr].size();
        int numchild = numadj;
        long long allHealthy = 0;
        long long haveUnhealthy = 0;
        for (int i = 0; i < numadj; ++i) {
            if (tree[curr][i] == pre) {
                numchild--;
                continue;
            }
            allHealthy += dfs(tree, values, dp, tree[curr][i], curr, 1);
            haveUnhealthy += max(dfs(tree, values, dp, tree[curr][i], curr, 1), dfs(tree, values, dp, tree[curr][i], curr, 0));
        }
        if (numchild == 0) {
            dp[curr][healthy] = (healthy ? 0 : values[curr]);
        }
        else if (healthy) {
            dp[curr][healthy] = max(haveUnhealthy, allHealthy + values[curr]);
        }
        else {
            dp[curr][healthy] = haveUnhealthy + values[curr];
        }
        return dp[curr][healthy];
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        unordered_map<int, vector<int>> tree;
        for (int i = 0; i < n - 1; ++i) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(tree, values, dp, 0, -1, 1);
    }
};