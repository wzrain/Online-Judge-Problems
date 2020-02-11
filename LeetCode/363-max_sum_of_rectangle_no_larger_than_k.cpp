// For 2D problems, we could use prefix sums to reduce
// them to 1D versions, adding quadratic time complexity.
// So basically the problem is reduced to finding a max sum
// subarray with sum no larger than k.
// By brute force, we need to go through all n^2 subarrays
// with the help of prefix sums. In that process, for
// each element we are dealing with, say jth element,
// we need to traverse all i with 0 <= i <= j to find out 
// the sum of the corresponding subarray (i, j].
// However, since all we need is the largest sum_j - sum_i
// <= k, we only need largest sum_i >= sum_j - k, where
// sum_j - k is a constant here. So binary searching in
// previous prefix sums will solve the problem better than
// traversing does.
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int rn = matrix.size(), cn = matrix[0].size();
        vector<vector<int>> rowsum(rn, vector<int>(cn, 0));
        for (int i = 0; i < rn; ++i) {
            rowsum[i][0] = matrix[i][0];
            for (int j = 1; j < cn; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + matrix[i][j];
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < cn; ++i) {
            for (int j = i; j < cn; ++j) {
                int sum = 0;
                set<int> st;
                st.insert(0);
                for (int r = 0; r < rn; ++r) {
                    int cur = (rowsum[r][j] - (i == 0 ? 0 : rowsum[r][i - 1]));
                    sum += cur;
                    auto it = st.lower_bound(sum - k);
                    if (it != st.end()) res = max(res, sum - (*it));
                    st.insert(sum);
                }
            }
        }
        return res;
    }
};


// Merge sort solution. Idea from 327.
class Solution {
public:
    void Merge(vector<int>& vec, vector<int>& tmp, int l, int mid, int r, int k, int& res) {
        int pl = l, pr = mid + 1, cur = l;          
        // int kp = l;     
        int kp = mid + 1;
        while (pl <= mid && pr <= r) {
            if (vec[pl] <= vec[pr]) {
                while (kp <= r && vec[kp] <= vec[pl] + k) kp++;
                if (kp != mid + 1) res = max(res, vec[kp - 1] - vec[pl]);
                tmp[cur++] = vec[pl++];
            }
            else {
                // while (kp <= mid && vec[kp] < vec[pr] - k) kp++;
                // if (kp <= mid) res = max(res, vec[pr] - vec[kp]);
                tmp[cur++] = vec[pr++];
            }
        }
        while (pl <= mid) {
            while (kp <= r && vec[kp] <= vec[pl] + k) kp++;
            if (kp != mid + 1) res = max(res, vec[kp - 1] - vec[pl]);
            tmp[cur++] = vec[pl++];
        }
        while (pr <= r) {
            // while (kp <= mid && vec[kp] < vec[pr] - k) kp++;
            // if (kp <= mid) res = max(res, vec[pr] - vec[kp]);
            tmp[cur++] = vec[pr++];
        }
        for (int i = l; i <= r; ++i) {
            vec[i] = tmp[i];
        }
    }
    void MergeSort(vector<int>& vec, vector<int>& tmp, int l, int r, int k, int& res) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        MergeSort(vec, tmp, l, mid, k, res);
        MergeSort(vec, tmp, mid + 1, r, k, res);
        Merge(vec, tmp, l, mid, r, k, res);
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int rn = matrix.size(), cn = matrix[0].size();
        vector<vector<int>> rowsum(rn, vector<int>(cn, 0));
        for (int i = 0; i < rn; ++i) {
            rowsum[i][0] = matrix[i][0];
            for (int j = 1; j < cn; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + matrix[i][j];
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < cn; ++i) {
            for (int j = i; j < cn; ++j) {
                vector<int> sum, tmp;
                sum.push_back(0);
                for (int r = 0; r < rn; ++r) {
                    int cur = (rowsum[r][j] - (i == 0 ? 0 : rowsum[r][i - 1]));
                    sum.push_back(sum.back() + cur);
                }
                tmp = sum;
                MergeSort(sum, tmp, 0, rn, k, res);
            }
        }
        return res;
    }
};