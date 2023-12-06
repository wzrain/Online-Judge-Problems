class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        long long res = -10e9;
        int n = nums.size();
        map<int, long long> sums;
        for (int i = 0; i < n; ++i) {
            res = max(res, (long long)nums[i]);
            if (nums[i] <= 0) continue;
            auto ub = sums.upper_bound(nums[i] - i);
            auto iter = ub;
            if (iter != sums.begin()) {
                sums[nums[i] - i] = (--ub)->second + nums[i];
            }
            else {
                sums[nums[i] - i] = nums[i];
            }
            long long cursum = sums[nums[i] - i];
            res = max(res, cursum);
            while( iter != sums.end() ) {
                auto todel = iter++;
                if (cursum >= todel->second) {
                    sums.erase(todel->first);
                }
            }
        }
        return res;
    }
};