// It is obvious that the final results comes from k 1's that share a window which contains only k 1's. Therefore 
// we find those windows, each of which contain exactly k 1's, and find the minimal move inside that window.
// Then it's necessary to notice that when we try to move 1's to the median of the indices of those 1's we 
// will get a minimal number of moves. If k is even, either of the medians will actually produce the same 
// result, so only check one of them will do.
// We don't need to recalculate every value in the sliding window. We can just do updates since every time 
// we just find the next value of the current median in the array which contains the indices of 1's (vec in the 
// code), and remove the effect of the leftmost element of the current window, and add the effect of the 
// rightmost element of the next window, and update the effect of other elements in the middle.
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        if (k == 1) return 0;
        int n = nums.size();
        // indices of 1's
        vector<int> vec;
        int i = 0, res = INT_MAX;
       
        int ti = k / 2, sum = 0;
        for (; i < n && vec.size() < k; ++i) {
            if (!nums[i]) continue;
            vec.push_back(i);
        }
        
        // index of the indices array vec
        int idx = ti;

        // tgt is the current median of indices of 1's
        int tgt = vec[idx];

        // abs(tgt - vec[j]) shows the distance between a 1 and the median 1. abs(idx - j) means it is 
        // the abs(idx - j)'th element in the left/right of the median
        for (int j = idx; j >= 0; --j) {
            sum += (tgt - vec[j] - (idx - j));
        }
        for (int j = idx + 1; j < k; ++j) {
            sum += (vec[j] - tgt - (j - idx));
        }
        res = min(res, sum);
        
        // start is a index of the indices array vec, which shows the current starting point of the sliding window. 
        int start = 0;
        for (; i < n; ++i) {
            if (!nums[i]) continue;
            vec.push_back(i);
            
            // the index of the indices array vec of the median of the previous and current window
            int previdx = ti++, curidx = ti;

            // median of the previous and current window respectively
            int prev = vec[previdx], cur = vec[curidx];

            // get rid of the leftmost element in the previous window
            sum -= (prev - vec[start] - (previdx - start));
            // add the right most element of the current window
            sum += (i - cur - (start + k - curidx));
            // the number of moves that are not necessary for the elements including and at 
            // the right of the current median
            // cur - prev means the distance to the median is closer, -1 means the number at the 
            // right of the median is smaller (the 2nd element at the right of the median 
            // previously becomes the 1st element at the right of the median now)
            sum -= (cur - prev - 1) * (start + k - 1 - previdx);
            // the number of moves that are additionally necessary for the elements at the left of 
            // the current median (thus including the previous median)
            sum += (cur - prev - 1) * (previdx - start);
            res = min(res, sum);
            
            start++;
        }
        return res;
    }
};