class Solution {
public:
    int cnt = 0;
    void mergeTwoArr(vector<int>& nums, int l, int mid, int r) {
        vector<int> tmp(r - l + 1);
        int idx = 0, i1 = l, i2 = mid + 1;
        // int cur = i1;
        int cur = i2;
        while (i1 <= mid && i2 <= r) {
            if (nums[i1] < nums[i2]) {
                while (cur <= r && nums[i1] > 2 * (long)nums[cur]) cur++;
                cnt += (cur - mid - 1);
                tmp[idx++] = nums[i1++];
            }
            else {
                // while (cur <= mid && nums[cur] <= 2 * (long)nums[i2]) cur++;
                // cnt += (mid - cur + 1);
                tmp[idx++] = nums[i2++];
            }
        }
        while (i1 <= mid) {
            while (cur <= r && nums[i1] > 2 * (long)nums[cur]) cur++;
            cnt += (cur - mid - 1);
            tmp[idx++] = nums[i1++];
        }
        while (i2 <= r) {
            /*
             * The following counting is still necessary, because even if all nums[cur] < nums[i2],
             * but since nums[i2] might be negative, 2 * nums[i2] could be smaller than nums[i2],
             * so there's still chances where nums[cur] > 2 * nums[i2]
             */
            // while (cur <= mid && nums[cur] <= 2 * (long)nums[i2]) cur++;
            // cnt += (mid - cur + 1);
            tmp[idx++] = nums[i2++];
        }
        for (int i = l; i <= r; ++i) {
            nums[i] = tmp[i - l];
        }
    }
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        mergeTwoArr(nums, l, mid, r);
    }
    
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};