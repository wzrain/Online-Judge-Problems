// O(nlogn) binary search solution
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, n = nums.size(), r = n + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int sum = 0, mxsum = 0;
            for (int i = 0; i < mid; ++i) {
                sum += nums[i];
            }
            mxsum = sum;
            for (int i = mid; i < n; ++i) {
                sum += (nums[i] - nums[i - mid]);
                mxsum = max(mxsum, sum);
                if (mxsum >= s) break;
            }
            if (mxsum >= s) r = mid;
            else l = mid + 1;
        }
        return l == n + 1 ? 0 : l;
    }
};

// O(n) two-pointer solution
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, res = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            while (l < r && sum >= s) {
                res = min(res, r - l);
                sum -= nums[l++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};