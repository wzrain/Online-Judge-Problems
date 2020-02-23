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

// O(n) solution with deque.
// The element with a larger index and smaller value is always better,
// because it has a larger chance to be subtracted to get larger than
// K and yet smaller interval. So we just pop back every element that
// is smaller than the current one, which leads to a monotonic pattern.
// One thing is we can do binary search in this monotonic stack and find
// the nearest element that is smaller than the current one by at least K.
// However this binary search is unnecessary, because when we get an
// element that can form a larger-than-K pair with the current one, then
// every pair it forms with later ones will be longer and unnecessary to
// consider, which means we can just pop front all the elements that forms
// such a pair with the current one since they will be useless later.
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if (A.empty()) return -1;
        int sz = A.size();
        vector<int> sum(sz + 1, 0);
        for (int i = 0; i < sz; ++i) {
            sum[i + 1] = sum[i] + A[i];
        }
        deque<int> dq;
        int res = INT_MAX;
        for (int i = 0; i <= sz; ++i) {
            while (!dq.empty() && sum[i] - sum[dq.front()] >= K) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && sum[i] < sum[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};