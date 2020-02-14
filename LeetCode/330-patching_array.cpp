// The most important thing is that if we find that all
// [1, m] is good, then add m + 1 makes [1, 2m + 1] good.
// Using this essential message, the key is about the RANGE, 
// so we do not need to calculate the subsets by adding new
// elements to every calculated subset, which gives an
// exponential complexity.
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long np = 0;
        int res = 0, idx = 0;
        while (np < n) {
            if (idx < nums.size()) {
                while (np < n && np < nums[idx] - 1) {
                    np = 2 * np + 1; // patch np + 1
                    res++;
                }
                np += nums[idx++];
            }
            else {
                np = 2 * np + 1;
                res++;
            }
        }
        return res;
    }
};