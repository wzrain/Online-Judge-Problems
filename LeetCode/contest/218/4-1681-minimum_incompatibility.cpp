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