class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0, n = arr.size(), res = 0;
        for (int i = 0; i < k; ++i) {
            cnt += arr[i];
        }
        if (cnt / k >= threshold) res++;
        for (int i = k; i < n; ++i) {
            cnt += (arr[i] - arr[i - k]);
            if (cnt / k >= threshold) res++;
        }
        return res;
    }
};