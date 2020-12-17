// the problem could be interpreted as "finding the 
// longest subarray with a specified sum (total - x here)"
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        int target = sum - x, res = INT_MAX;
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && target > 0) {
                target -= nums[j++];
            }
            if (target == 0) res = min(res, n - (j - i));
            if (i == j) {
                i++;
                j++;
            }
            else {
                target += nums[i++];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};