// For every element i, The max abs it can form with j (j > i) is (max(prefix[j]) or min(prefix[j])) - prefix[i], 
// so we can iterate from the back and record the current max/min prefix sum. The space can be optimized. 
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        // vector<int> prefix(n + 1, 0);
        // for (int i = 0; i < n; ++i) {
        //     prefix[i + 1] = prefix[i] + nums[i];
        // }
        int prefix = 0;
        for (int i = 0; i < n; ++i) prefix += nums[i];
        // int mx = prefix[n], mn = prefix[n], res = 0;
        int mx = prefix, mn = prefix, res = 0;
        for (int i = n - 1; i >= 0; --i) {
            prefix -= nums[i];
            // res = max(res, max(abs(mx - prefix[i]), abs(mn - prefix[i])));
            // mx = max(mx, prefix[i]);
            // mn = min(mn, prefix[i]);
            res = max(res, max(abs(mx - prefix), abs(mn - prefix)));
            mx = max(mx, prefix);
            mn = min(mn, prefix);
        }
        return res;
    }
};

// Actually in the previous solution, the result would come from the max prefix - min prefix
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        int mx = 0, mn = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            prefix += nums[i];
            mx = max(mx, prefix);
            mn = min(mn, prefix);
        }
        
        return mx - mn;
    }
};