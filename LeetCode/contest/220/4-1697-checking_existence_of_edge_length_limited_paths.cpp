class Solution {
private:
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
    bool Unioned(int x, int y, vector<int>& parent) {
        int px = Find(x, parent), py = Find(y, parent);
        return px == py;
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int esz = edgeList.size(), qsz = queries.size();
        for (int i = 0; i < qsz; ++i) {
            queries[i].push_back(i);
        }
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[2] < v2[2];
        };
        sort(edgeList.begin(), edgeList.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);
        
        int ei = 0;
        vector<bool> res(qsz);
        vector<int> parent(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for (int i = 0; i < qsz; ++i) {
            int curlen = queries[i][2], qx = queries[i][0], qy = queries[i][1];
            while (ei < esz && edgeList[ei][2] < curlen) {
                int ex = edgeList[ei][0], ey = edgeList[ei][1];
                Union(ex, ey, parent);
                ei++;
            }
            res[queries[i][3]] = Unioned(qx, qy, parent);
        }
        return res;
    }
};