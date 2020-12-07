// two pointers
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if (nums.size() < 2) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int cur = nums[i] + nums[j];
            if (cur == k) {
                res++;
                i++;
                j--;
            }
            else if (cur < k) {
                i++;
            }
            else {
                j--;
            }
        }
        return res;
    }
};