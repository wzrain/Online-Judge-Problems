class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                res += nums[i];
                mp[nums[i]] = 1;
            }
            else if (mp[nums[i]] == 1) {
                res -= nums[i];
                mp[nums[i]] = 2;
            }
        }
        return res;
    }
};