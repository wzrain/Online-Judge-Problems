// Union-Find solution. Similar to how we find MSTs.
class Solution {
private:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int getIdx(int i, int j, int n) {
        return i * n + j;
    }
    int Find(vector<int>& parent, int idx) {
        int res = parent[idx];
        while (res != parent[res]) res = parent[res];
        while (idx != res) {
            int tmp = parent[idx];
            parent[idx] = res;
            idx = tmp;
        }
        return res;
    }
    void Union(vector<int>& parent, int x, int y) {
        int px = Find(parent, x), py = Find(parent, y);
        if (px != py) parent[px] = py;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n, 0);
        for (int i = 0; i < n * n; ++i) {
            parent[i] = i;
        }
        auto cmp = [&grid](const pair<int, int>& p1, const pair<int, int>& p2) {
            return grid[p1.first][p1.second] > grid[p2.first][p2.second];  
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pq.push(make_pair(i, j));
            }
        }
        int res = 0;
        while (!pq.empty() && Find(parent, 0) != Find(parent, getIdx(n - 1, n - 1, n))) {
            int i = pq.top().first, j = pq.top().second;
            pq.pop();
            int idx = getIdx(i, j, n);
            for (int d = 0; d < 4; ++d) {
                int ni = i + dir[d], nj = j + dir[d + 1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                if (grid[ni][nj] <= grid[i][j]) Union(parent, getIdx(ni, nj, n), idx);
            }
            res = grid[i][j];
        }
        return res;
    }
};