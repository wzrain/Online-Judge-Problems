class Solution {
public:
    bool check(vector<int>& nums) {
        int less = 0, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) less++;
            if (less >= 2) return false;
        }
        // rotated only if the first element is larger than the last
        // the comparison of the first and the last can actually be integrated 
        // into the loop (nums[i] < nums[(i + 1) % n])
        return less == 0 ? true : (nums[0] >= nums[n - 1]);
    }
};