// Union-Find solution
// we can manage remove every point except for the parent
// inside one union
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
    int removeStones(vector<vector<int>>& stones) {
        int num = stones.size();
        vector<int> parent(num, 0);
        for (int i = 0; i < num; ++i) {
            parent[i] = i;
        }
        unordered_map<int, int> rm, cm;
        for (int i = 0; i < num; ++i) {
            int r = stones[i][0], c = stones[i][1];
            if (rm.find(r) == rm.end()) {
                rm[r] = i;
            }
            else {
                Union(rm[r], i, parent);
            }
            if (cm.find(c) == cm.end()) {
                cm[c] = i;
            }
            else {
                Union(cm[c], i, parent);
            }
        }
        int cnt = num;
        for (int i = 0; i < num; ++i) {
            if (i == Find(i, parent)) cnt--;
        }
        return cnt;
    }
};