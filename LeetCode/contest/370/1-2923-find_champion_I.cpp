class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int res = -1, n = grid.size();
        for (int i = 0; i < n; ++i) {
            int j = 0;
            for (; j < n; ++j) {
                if (i != j && !grid[i][j]) {
                    break;
                }
            }
            if (j == n) {
                res = i;
                break;
            }
        }
        return res;
    }
};