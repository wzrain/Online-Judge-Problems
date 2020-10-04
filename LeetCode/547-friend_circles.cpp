// bfs solution
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        // vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            // if (visited[i]) continue;
            if (!M[i][i]) continue;
            queue<int> q;
            q.push(i);
            // visited[i] = 1;
            M[i][i] = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < n; ++j) {
                    if (!M[j][j] || !M[cur][j]) continue;
                    // visited[j] = 1;
                    M[j][j] = 0;
                    q.push(j);
                }
            }
            cnt++;
        }
        return cnt;
    }
};

// union-find solution
class Solution {
public:
    int Find(int x, vector<int>& parent) {
        int res = parent[x];
        while (res != parent[res]) res = parent[res];
        while (x != res) {
            int tmp = parent[x];
            parent[x] = res;
            x = tmp;
        }
        return res;
    }
    void Union(int x, int y, vector<int>& parent) {
        int px = Find(x, parent), py = Find(y, parent);
        parent[px] = py;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> parent(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j]) Union(i, j, parent);
            }
        }
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(Find(i, parent));
        }
        return st.size();
    }
};