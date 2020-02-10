class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, n = nums.size();
        // Here is actually a dp array where dp[i] 
        // recording the largest sum array ending with nums[i].
        // dp[i] only depends on dp[i - 1] so dp could be
        // replaced by a single variable sum.
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) sum = nums[i];
            else sum = nums[i] + max(sum, 0);
            res = max(sum, res);
        }
        return res;
    }
};