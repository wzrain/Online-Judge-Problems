// Find the maximum array with length i and k - i in both arrays respectively and merge them together.
// When finding in one array, use and reuse mono stack.
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res1(k + 1), res2(k + 1);
        onearray(nums1, res1, k);
        onearray(nums2, res2, k);
        vector<int> res;
        for (int i = 0; i <= k; ++i) {
            if (i > nums1.size() || k - i > nums2.size()) continue;
            vector<int> tmp(k);
            mrg(res1, res2, tmp, i, k);
            if (res.empty()) res = tmp;
            else {
                int idx = 0;
                while (idx < k && tmp[idx] == res[idx]) idx++;
                if (idx < k && res[idx] < tmp[idx]) res = tmp;
            }
        }
        return res;
        
    }
    void mrg(vector<vector<int>>& r1, vector<vector<int>>& r2, vector<int>& res, int idx, int k) {
        int i = 0, j = 0, n1 = r1[idx].size(), n2 = r2[k - idx].size();
        while (i < n1 && j < n2) {
            if (r1[idx][i] < r2[k - idx][j]) {
                res[i + j] = r2[k - idx][j];
                j++;
            }
            else if (r1[idx][i] > r2[k - idx][j]) {
                res[i + j] = r1[idx][i];
                i++;
            }
            else {
                int ii = i + 1, jj = j + 1;
                while (ii < n1 && jj < n2 && r1[idx][ii] == r2[k - idx][jj]) {
                    ii++;
                    jj++;
                }
                if (jj >= n2 || (ii < n1 && r1[idx][ii] > r2[k - idx][jj])) {
                    res[i + j] = r1[idx][i];
                    i++;
                }
                else {
                    res[i + j] = r2[k - idx][j];
                    j++;
                }
            }
        }
        while (i < n1) {
            res[i + j] = r1[idx][i];
            i++;
        }
        while (j < n2) {
            res[i + j] = r2[k - idx][j];
            j++; 
        }
    }
    void onearray(vector<int>& nums, vector<vector<int>>& res, int k) {
        vector<int> tmp = nums;
        int n = nums.size();
        int mxsz = min(n, k);
        vector<int> stk;
        for (int i = mxsz; i > 0; --i) {
            int tsz = tmp.size();
            for (int j = 0; j < tsz; ++j) {
                while (!stk.empty() && stk.back() < tmp[j] && stk.size() - 1 + tsz - j >= i) stk.pop_back();
                if (stk.size() < i) stk.push_back(tmp[j]);
            }
            res[i] = stk;
            tmp = stk;
            stk = vector<int>();
        }
    }
};