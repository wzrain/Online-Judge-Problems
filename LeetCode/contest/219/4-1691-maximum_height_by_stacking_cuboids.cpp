// The height can always be the edge with largest length.
// The relation between two cuboids is a total order. So 
// just form a graph and find the longest path.
// Alternatively just sort the original array and find the
// dp value in place without the need of searching in a
// graph.
class Solution {
public:
    int dfs(vector<vector<int>>& cuboids, int idx, vector<vector<int>>& graph, vector<int>& dp) {
        if (dp[idx] != -1) return dp[idx];
        int nexts = graph[idx].size();
        int res = 0;
        for (int i = 0; i < nexts; ++i) {
            int nx = graph[idx][i];
            res = max(res, dfs(cuboids, nx, graph, dp));
        }
        dp[idx] = res + cuboids[idx][2];
        return dp[idx];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (int i = 0; i < n; ++i) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        vector<vector<int>> graph(n);
        vector<int> starts(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (i == j) continue;
                if (cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2]) {
                    graph[i].push_back(j);
                    starts[j] = 0;
                }
                else if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    graph[j].push_back(i);
                    starts[i] = 0;
                }
            }
        }
        int res = 0;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; ++i) {
            if (starts[i]) res = max(res, dfs(cuboids, i, graph, dp));
        }
        return res;
    }
};