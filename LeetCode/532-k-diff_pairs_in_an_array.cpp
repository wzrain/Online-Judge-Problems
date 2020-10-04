// two-pointer solution

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, n = nums.size(), cnt = 0;
        while (j < n) {
            int diff = nums[j] - nums[i];
            if (diff < k) {
                j++;
            }
            else {
                if (diff == k) cnt++;
                i++;
                // remove duplicates caused by identical i's
                while (i < j && nums[i] == nums[i - 1]) i++;
                if (i == j) {
                    j++;
                    if (nums[i] == nums[i - 1]) {
                        // If nums[i] == nums[i - 1], the current (i, j) has already been calculated at the previous step, otherwise this is a new pair.
                        while (j < n && nums[j] == nums[j - 1]) j++;
                    }   
                }
            }
        }
        return cnt;
    }
};