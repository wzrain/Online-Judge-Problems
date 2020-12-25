class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        if (mat.empty()) return {};
        
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> res(n);
        vector<int> ret(k);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                cnt += mat[i][j];
            }
            res[i] = make_pair(cnt, i);
        }
        stable_sort(res.begin(), res.end());
        for (int i = 0; i < k; ++i) {
            ret[i] = res[i].second;
        }
        return ret;
    }
};