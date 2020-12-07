class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        // sort for deduplication and also simplify the search process
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        unordered_set<int> dp;
        int visited = 0;
        dfs(nums, visited, k, nums.size() / k, res, 0, INT_MAX, INT_MIN, 0, k, dp);
        return res == INT_MAX ? -1 : res;
    }
    void dfs(vector<int>& nums, int visited, int k, int n, int& res, int idx, int curmn, int curmx, int cur, int org_k, unordered_set<int>& dp) {
        if (k == 0) {
            if (res > cur) res = cur;
            return;
        }
        // pruning
        // For every finished group search, record the
        // searched state (visited) so that there's no need 
        // to search again. Even if the result for the 
        // current visited is not the optimal, there is 
        // still one chance to search again when later we 
        // search the currently unvisited values first and 
        // then come back to search the front, for example, 
        // for [1,1,2,2,3,3,6,8,9,10], k == 5, we might not 
        // reach an optimal solution for [1,1,2,2,3,3,6,8], 
        // but when we start to search from [9,10] there is 
        // still chances to research another time.
        // We can't record for every record where the 
        // grouping is still ongoing, for example k == 4 
        // and there are 5 visited numbers, because the 
        // visited numbers might belong to a different 
        // group now and might contribute to the final 
        // result later.
        // This can also be done in the "if (n == 0)" logic,
        // but it might influence the k == 0 situation 
        // because there's no more re-search again for all 
        // values visited. So we need to make sure that 
        // every possible solution for k == 0 is checked.
        if (n == nums.size() / org_k) {
            if (dp.find(visited) != dp.end()) return;
            dp.insert(visited);
        }

        // pruning
        if (cur >= res) return;

        if (n == 0) {
            dfs(nums, visited, k - 1, nums.size() / org_k, res, 0, INT_MAX, INT_MIN, curmx - curmn + cur, org_k, dp);
            return;
        }
        if (idx >= nums.size()) return;
        for (int i = idx; i < nums.size();) {
            if (visited & (1 << i)) {
                i++;
                continue;
            }
            visited |= (1 << i);
            int nxt = i + 1;
            while (nxt < nums.size() && nums[nxt] == nums[i]) nxt++;
            dfs(nums, visited, k, n - 1, res, nxt, min(curmn, nums[i]), max(curmx, nums[i]), cur, org_k, dp);
            visited ^= (1 << i);
            i = nxt;
        }
    }
};

// dp solution
// The idea is to find subproblems with bit masks. 
// Bitmasks can be traversed via a single for loop.
// When a submask is being examined, just subtract
// to find the complement bitmask, which correspond
// to the two subparts of the problem.
// We need to first calculate the situations with
// only one group, since the for loop does not go
// through the bitmasks in the order of increasing
// problem scale (e.g 0111b < 1000b).
// The submask traversal can be optimized into O(3^N).
// When finding a submask of mk, just find every
// number p that is smaller than mk and p & mk == mk.
// So we could use (p - 1) & mk to find the next submask.
// Here every bit is either included in both mk and p, or
// only included in mk, or not included in mk. So there
// are 3^n different combinations for n bits.
class Solution {
private:
    int countBits(int mask) {
        int res = 0;
        while (mask) {
            res += (mask & 1);
            mask >>= 1;
        }
        return res;
    }
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size(), m = n / k;
        unordered_map<int, int> incomp;
        vector<int> dp((1 << n), INT_MAX);
        dp[0] = 0;
        for (int mk = 0; mk < (1 << n); ++mk) {
            if (countBits(mk) != m) continue;
            int mx = INT_MIN, mn = INT_MAX;
            // unordered_set<int> visited;
            int visited = 0;
            bool good = true;
            for (int i = 0; i < n; ++i) {
                if (mk & (1 << i)) {
                    // if (visited.find(nums[i]) != visited.end()) {
                    if (visited & (1 << nums[i])) {
                        good = false;
                        break;
                    }
                    // visited.insert(nums[i]);
                    visited |= (1 << nums[i]);
                    mx = max(nums[i], mx);
                    mn = min(nums[i], mn);
                }
            }
            if (good) dp[mk] = mx - mn;
        }
        for (int mk = 0; mk < (1 << n); ++mk) {
            if (countBits(mk) % m) continue;
            for (int sm = mk; sm; sm = (sm - 1) & mk) {
                if (countBits(sm) != m) continue; // necessary optimization
                if (dp[sm] == INT_MAX || dp[mk - sm] == INT_MAX) continue;
                dp[mk] = min(dp[mk], dp[sm] + dp[mk - sm]);
            }
        }
        return dp[(1 << n) - 1] == INT_MAX ? -1 : dp[(1 << n) - 1];
    }
};