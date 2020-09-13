// It's no good to only record the same status via the 
// turn of mouse or cat, since we could enter a loop,
// and before the actual value of the status is found
// out, we might reach the status again and then return
// a draw, which might be incorrect. 
// To fix this we could save the step instead of the turn
// and the draw is returned if the game reaches 2n steps
class Solution {
public:
    int dfs(vector<vector<int>>& graph, int mi, int ci, vector<vector<vector<int>>>& dp, int im) {
        if (mi == 0) return 1;
        if (ci == mi) return 2;
        if (im > 2 * graph.size()) return 0;
        if (dp[mi][ci][im] != -1) return dp[mi][ci][im];
        int curidx = im % 2 ? mi : ci;
        int res = INT_MAX;
        for (int i = 0; i < graph[curidx].size(); ++i) {
            int nidx = graph[curidx][i];
            if (!(im % 2) && nidx == 0) continue;
            int tmp;
            if (im % 2) tmp = dfs(graph, nidx, ci, dp, im + 1);
            else tmp = dfs(graph, mi, nidx, dp, im + 1);
            if ((im % 2) && tmp == 1) {
                dp[mi][ci][im] = 1;
                return dp[mi][ci][im];
            }
            if (!(im % 2) && tmp == 2) {
                dp[mi][ci][im] = 2;
                return dp[mi][ci][im];
            }
            res = min(tmp, res);
        }
        dp[mi][ci][im] = res;
        return res;
    }
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2 * n + 1, -1)));
        int res = dfs(graph, 1, 2, dp, 1);
        return res;
    }
};