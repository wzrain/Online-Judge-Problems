class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lz = 0, lnz = 0, n = nums.size();
        while (lz < n && nums[lz]) lz++;
        lnz = lz + 1;
        while (lnz < n) {
            while (lnz < n && nums[lnz] == 0) lnz++;
            if (lnz < n) {
                swap(nums[lz], nums[lnz]);
                while (lnz < n && nums[lnz] == 0) lnz++;
                while (lz < lnz && nums[lz]) lz++;
            }
        }
    }
};