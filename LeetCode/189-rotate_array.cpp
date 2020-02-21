class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (!k) return;
        int rd = gcd(n, k);
        for (int i = 0; i < rd; ++i) {
            int idx = (i + k) % n, tmp = nums[idx];
            nums[idx] = nums[i];
            while (idx != i) {
                int nidx = (idx + k) % n;
                swap(nums[nidx], tmp);
                idx = nidx;
            }
        }
    }
};

// Rotate means put the last k elements in the front.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};