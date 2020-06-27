// Do binary search on the answer. We need to find
// a solution that could be produced via a "distance"
// of a pair, which is essentially finding the 
// smallest answer that makes k pairs whose
// distance is less than k.
// The pair counting could be done via binary search
// as well, in which the largest index is searched,
// or we can use a sliding window to get rid of
// that log because the right index of the window
// is monotonically increasing.
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front(), n = nums.size();
        while (l < r) {
            int mid = (l + r) / 2, cnt = 0;
            int j = 0;
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] <= nums[i] + mid) j++;
                cnt += j - i - 1;
                // int tgt = nums[i] + mid;
                // int ll = i, rr = n;
                // while (ll < rr) {
                //     int mm = (ll + rr) / 2;
                //     if (nums[mm] <= tgt) ll = mm + 1;
                //     else rr = mm;
                // }
                // cnt += ll - i - 1;
                if (cnt > k) break;
            }
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};