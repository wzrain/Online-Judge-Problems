// O(nlogn) solution
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if (A.empty()) return -1;
        int sz = A.size();
        vector<int> sum(sz + 1, 0);
        for (int i = 0; i < sz; ++i) {
            sum[i + 1] = sum[i] + A[i];
        }
        vector<pair<int, int>> si(sz + 1);
        set<int> is;
        for (int i = 0; i <= sz; ++i) {
            si[i] = make_pair(sum[i], i);
            is.insert(i);
        }
        sort(si.begin(), si.end());
        int pt = 0;
        int res = INT_MAX;
        for (int i = 0; i <= sz; ++i) {
            while (pt <= sz && si[pt].first < si[i].first + K) {
                is.erase(si[pt++].second);
            }
            if (pt > sz) break;
            int idx = si[i].second;
            if (is.upper_bound(idx) == is.end()) continue;
            res = min(res, *(is.upper_bound(idx)) - idx);
        }
        return res == INT_MAX ? -1 : res;
    }
};