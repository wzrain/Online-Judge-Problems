// The intuition is greedily finding an interval
// with its max value no larger than the min value
// of the suffix of the original array, which means
// this interval could make a chunk. Then for the
// remaining part of the array just repeat this 
// process.
// And the thing is we don't need to use a new mx
// to record the max value for the new interval, 
// because the previous mx is guaranteed to be no
// larger than the max value of the new interval.
// So just using one value to record the max value
// at the current position will do.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> min_suffix(n, 0);
        min_suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = min(min_suffix[i + 1], arr[i]);
        }
        int idx = 0, cnt = 0;
        int mx = arr[idx];
        for (int i = 0; i < n - 1; ++i) {
            mx = max(mx, arr[i]);
            if (mx <= min_suffix[i + 1]) {
                cnt++;
            }
        }
        cnt++;
        // while (idx < n) {
        //     int mx = arr[idx];
        //     int i = idx;
        //     for (; i < n - 1; ++i) {
        //         mx = max(mx, arr[i]);
        //         if (mx <= min_suffix[i + 1]) {
        //             break;
        //         }
        //     }
        //     cnt++;
        //     idx = i + 1;
        // }
        return cnt;
    }
};