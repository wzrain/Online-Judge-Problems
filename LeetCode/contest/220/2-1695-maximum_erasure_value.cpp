class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, res = 0;
        int i = 0, j = 0, len = nums.size();
        unordered_set<int> cnt;
        while (j < len) {
            while (i < j && cnt.find(nums[j]) != cnt.end()) {
                sum -= nums[i];
                cnt.erase(nums[i++]);
            }
            sum += nums[j];
            cnt.insert(nums[j]);
            j++;
            res = max(res, sum);
        }
        return res;
    }
};