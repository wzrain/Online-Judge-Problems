// permutation of indices
class Solution {
public:
    int calc(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int>& idxes) {
        int n = idxes.size(), m = students[0].size(), res = 0;
        for (int i = 0; i < n; ++i) {
            int idx = idxes[i];
            for (int j = 0; j < m; ++j) {
                res += (students[i][j] == mentors[idx][j]);
            }
        }
        return res;
    }
    void perm(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int>& idxes, int& res, int curidx) {
        if (curidx == idxes.size() - 1) {
            int cur = calc(students, mentors, idxes);
            res = max(res, cur);
            return;
        }
        
        for (int i = curidx; i < idxes.size(); ++i) {
            swap(idxes[i], idxes[curidx]);
            perm(students, mentors, idxes, res, curidx + 1);
            swap(idxes[i], idxes[curidx]);
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int res = 0;
        int n = students.size(), m = students[0].size();
        vector<int> idxes(n, 0);
        for (int i = 0; i < n; ++i) {
            idxes[i] = i;
        }
        perm(students, mentors, idxes, res, 0);
        
        return res;
    }
};