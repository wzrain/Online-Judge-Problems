// The pure brute-force O(2^n) solution is just a full search. A way to optimize the search is to divide the 
// problem in half. So when trying to find the sums of subsequences, instead of enumerating every possibility, 
// use split and merge to optimize that square of O(2^n) = O((2^(n/2))^2). This is where O(nlogn) algorithms shine 
// compared to O(n^2) ones.
class Solution {
public:
    void allsum(vector<int>& vec, vector<int>& res) {
        int n = vec.size();
        res.push_back(0);
        for (int i = 0; i < n; ++i) {
            int sz = res.size();
            for (int j = 0; j < sz; ++j) {
                res.push_back(res[j] + vec[i]);
            }
        }
        
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> n1, n2;
        for (int i = 0; i < n; ++i) {
            if (i < n / 2) n1.push_back(nums[i]);
            else n2.push_back(nums[i]);
        }
        vector<int> s1, s2;
        allsum(n1, s1);
        allsum(n2, s2);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int sz1 = s1.size(), sz2 = s2.size();
        int i = 0, j = sz2 - 1;
        int res = INT_MAX;
        while (i < sz1 && j >= 0) {
            int sum = s1[i] + s2[j];
            res = min(res, abs(sum - goal));
            if (sum > goal) j--;
            else i++;
        }
        return res;
    }
};