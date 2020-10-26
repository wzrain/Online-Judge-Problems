// O(n^2) solution
// dp[i][i + w] indicates the max money from interval [i, i + w]
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            nums.push_back(nums[i]);
        }
        vector<vector<vector<int>>> dp(2 * n, vector<vector<int>>(2 * n, vector<int>(2, 0)));
        for (int w = 0; w < n; ++w) {
            for (int i = 0; i < 2 * n - 1 - w; ++i) {
                if (w > 0) dp[i][i + w][0] = max(dp[i][i + w - 1][0], dp[i][i + w - 1][1]);
                dp[i][i + w][1] = (w > 0 ? dp[i][i + w - 1][0] : 0) + nums[i + w];
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, max(dp[i][i + n - 2][0], dp[i][i + n - 2][1]));
        }
        return res;
    }
};

// We don't need to calculate every interval in the circle,
// but only consider two intervals without the first and the last
// element respectively, because the situations in other intervals 
// are all covered when updating the dp array.
// For the non-circular situation (Problem 198), the only thing
// different here is element 0 and n - 1 cannot be chosen at
// the same time. So the only modification is to choose from 0 or
// n - 1 in the first place. The dp process will settle the situation
// where they are both discarded (for example robber(0, n - 2) means 
// element 0 CAN be chosen but not necessarily will, here "CAN"
// means the adjacent one cannot be chosen).
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
    int robber(vector<int>& nums, int start, int end) {
        int p0 = 0, p1 = nums[start];
        for (int i = start + 1; i <= end; ++i) {
            int tmp = max(p0, p1);
            p1 = p0 + nums[i];
            p0 = tmp;
        }
        return max(p0, p1);
    }
};