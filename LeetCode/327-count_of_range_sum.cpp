// Merge sort can be used to solve general problems about 
// counting some value comparisons between arr[i] and arr[j].
// Here we need lower <= arr[j] - arr[i] <= upper, which is 
// a general question for counting reverse pairs where arr[j]
// - arr[i] < 0. We make use of the characteristic that two
// subarrays during merge process are sorted, so that if we
// know some arr[j] - arr[i], we can easily know arr[j + 1]
// - arr[i] by further extending previous results. So it does
// not add up to the overall complexity.
class Solution {
public:
    void Merge(vector<long>& vec, vector<long>& tmp, int l, int mid, int r, int& cnt, int lower, int upper) {
        int pl = l, pr = mid + 1, cur = l;
        // int up = mid + 1, lp = mid + 1;            // for each element in the left, find elements in the right
        int up = l, lp = l;                           // for each element in the right, find elements in the left
        while (pl <= mid && pr <= r) {
            if (vec[pl] <= vec[pr]) {
                // while (lp <= r && vec[lp] - lower < vec[pl]) lp++;
                // while (up <= r && vec[up] - upper <= vec[pl]) up++;
                // cnt += (up - lp);
                tmp[cur++] = vec[pl++];
            }
            else {
                while (lp <= mid && vec[lp] <= vec[pr] - lower) lp++;
                while (up <= mid && vec[up] < vec[pr] - upper) up++;
                cnt += (lp - up);
                tmp[cur++] = vec[pr++];
            }
        }
        while (pl <= mid) {
            // while (lp <= r && vec[lp] - lower < vec[pl]) lp++;
            // while (up <= r && vec[up] - upper <= vec[pl]) up++;
            // cnt += (up - lp);
            tmp[cur++] = vec[pl++];
        }
        while (pr <= r) {
            while (lp <= mid && vec[lp] <= vec[pr] - lower) lp++;
            while (up <= mid && vec[up] < vec[pr] - upper) up++;
            cnt += (lp - up);
            tmp[cur++] = vec[pr++];
        }
        for (int i = l; i <= r; ++i) {
            vec[i] = tmp[i];
        }
    }
    void MergeSort(vector<long>& vec, vector<long>& tmp, int l, int r, int& cnt, int lower, int upper) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        MergeSort(vec, tmp, l, mid, cnt, lower, upper);
        MergeSort(vec, tmp, mid + 1, r, cnt, lower, upper);
        Merge(vec, tmp, l, mid, r, cnt, lower, upper);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> vec, tmp;
        vec.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            vec.push_back(vec.back() + nums[i]);
        }
        tmp = vec;
        int cnt = 0;
        MergeSort(vec, tmp, 0, n, cnt, lower, upper);
        return cnt;
    }
};