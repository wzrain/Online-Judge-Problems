class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        int res = -1;
        vector<int> bitmap = vector<int>(n, 0);
        for (int i = 0; i < m; ++i) {
            bitmap[edges[i][1]] = 1;
        }
        for (int i = 0; i < n; ++i) {
            if (!bitmap[i]) {
                if (res == -1) {
                    res = i;
                }
                else {
                    return -1;
                }
            }
        }
        return res;
    }
};