// Every element contributes to the score between certain intervals.
// The intervals could be derived from its value and its initial index.
// Therefore we could transform the problem to finding the largest
// number of overlapping intervals. Note that for the normal version
// of this problem, we need to sort the starts and ends of intervals
// and scan to count (like what we do in pts in the following code).
// Note that the starts and ends are all indices between 0 and n - 1,
// we don't need to sort the intervals, but could use every index as 
// a "bucket" and put corresponding starts and ends in. Since we are
// only interested in the counts, every bucket could only save counts
// of starts and ends, which results in the deltas of the score for 
// every rotation. 
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size();
        // vector<pair<int, int>> pts;
        vector<int> delta(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            if (A[i] <= i) {
                // pts.push_back({0, 0});
                // pts.push_back({i - A[i], 1});
                delta[0]++;
                delta[i - A[i] + 1]--;
            }
        }
        for (int i = n; i < 2 * n - 1; ++i) {
            int idx = i - n;
            if (A[idx] < n) {
                // pts.push_back({idx + 1, 0});
                // pts.push_back({min(idx + n - A[idx], n - 1), 1});
                delta[idx + 1]++;
                delta[min(idx + n - A[idx], n - 1) + 1]--;
            }
        }
        
        // sort(pts.begin(), pts.end());
        int cnt = 0, mx = 0, res = 0;
        // for (int i = 0; i < pts.size(); ++i) {
        for (int i = 0; i < n; ++i) {
            cnt += delta[i];
            // if (!pts[i].second) cnt++;
            // else cnt--;
            if (cnt > mx) {
                // res = pts[i].first;
                res = i;
                mx = cnt;
            }
        }
        return res;
    }
};