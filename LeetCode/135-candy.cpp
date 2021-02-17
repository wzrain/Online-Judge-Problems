// Two-pass solution for calculating ups and downs respectively. The ridges only need one, and the number 
// just increments along the ups/downs. The max is mainly for the peak.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> res(n, 1);
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && ratings[i] > ratings[i - 1]) cur++;
            else cur = 1;
            res[i] = max(res[i], cur);
        }
        cur = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) cur++;
            else cur = 1;
            res[i] = max(res[i], cur);
        }
        int ans = 0;
        for (auto r : res) ans += r;
        return ans;
    }
};

// O(1) space one-pass solution
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 0, ans = 0;
        bool end_with_peak = false;
        while (i + 1 < n) {
            int cur = 1;
            
            // ups
            while (i + 1 < n && ratings[i] < ratings[i + 1]) {
                ans += (cur++);
                i++;
                end_with_peak = true;
            }
            int dist = cur; // candidate candy for peak value
            cur = 1;

            // downs
            while (i + 1 < n && ratings[i] > ratings[i + 1]) {
                ans += (cur++);
                i++;
                end_with_peak = false;
            }

            // min candy from both ups and downs
            ans += max(cur, dist);

            // flat
            while (i + 1 < n && ratings[i] == ratings[i + 1]) {
                ans++;
                i++;
                end_with_peak = false;
            }

            // If the current loop does not end with peak value, that means we will calculate the 
            // candy of the last value twice (because we will add it another time in the next loop or 
            // after the outer loop finishes), so we need to subtract it here in advance.
            if (!end_with_peak) ans--;
        }
        
        // If the last element is the peak element, we've already added its candy in "ans += max
        // (cur, dist)". Otherwise it will need one candy that has yet to be added.
        if (!end_with_peak) ans++;
        return ans;
    }
};