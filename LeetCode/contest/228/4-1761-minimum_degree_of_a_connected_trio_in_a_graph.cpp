// sort the number of nodes in a trio to avoid duplicates
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> grph(n + 1, vector<int>(n + 1, 0));
        vector<int> dg(n + 1, 0);
        int en = edges.size(), res = INT_MAX;
        for (int i = 0; i < en; ++i) {
            int u = edges[i][0], v = edges[i][1];
            grph[min(u, v)][max(u, v)] = 1;
            dg[u]++;
            dg[v]++;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!grph[i][j]) continue;
                for (int k = j + 1; k <= n; ++k) {
                    if (grph[i][k] && grph[j][k]) {
                        res = min(res, dg[i] + dg[j] + dg[k] - 6);
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};