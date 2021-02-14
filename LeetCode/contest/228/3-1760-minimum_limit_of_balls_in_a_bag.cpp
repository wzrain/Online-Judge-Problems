// The greedy solution with priority queue will not work, because we can't make sure how much to divide on that max 
// value. Use binary search on the answer instead, because to reach a certain minimax, we can calculate how 
// many operations are needed at least.
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        if (nums.empty()) return 0;
        long sum = 0;
        int n = nums.size(), mx = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            mx = max(mx, nums[i]);
        }
        int mn = (sum / (n + maxOperations)) + (sum % (n + maxOperations) != 0);
        while (mn < mx) {
            int mid = (mn + mx) / 2;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid) continue;
                cnt += ((nums[i] / mid) - (nums[i] % mid == 0));
                if (cnt > maxOperations) break;
            }
            if (cnt > maxOperations) mn = mid + 1;
            else mx = mid;
        }
        return mn;
    }
};