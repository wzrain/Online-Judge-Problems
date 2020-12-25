// O(nd) top-down dp solution
// Basically find a "longest path", but no need of building a separate graph to do dp. The "edge" can be 
// implicitly specified directly during dp, which is the same process as the graph building.
class Solution {
public:
    int dfs(vector<int>& arr, int i, vector<int>& dp, int d) {
        if (dp[i] != -1) return dp[i];
        int tmp = 0, n = arr.size();
        for (int j = i - 1; j >= max(0, i - d); --j) {
            if (arr[j] >= arr[i]) break;
            tmp = max(tmp, dfs(arr, j, dp, d));
        }
        for (int j = i + 1; j <= min(n - 1, i + d); ++j) {
            if (arr[j] >= arr[i]) break;
            tmp = max(tmp, dfs(arr, j, dp, d));
        }
        dp[i] = tmp + 1;
        return dp[i];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(arr, i, dp, d));
        }
        return res;
    }
};

// The graph can also be built via monotonous stack due to the nature of the problem.
// Note that the equal elements should be all kept inside the stack since they are not countering each other and 
// any of them can contribute to the final result. Therefore when new elements are added we need to add some 
// logic to find the most recent previous element that is strictly larger and add an edge starting from that 
// element ending at the current element to the graph.
class Solution {
public:
    int dfs(vector<vector<int>>& graph, int idx, vector<int>& dp) {
        if (dp[idx] != -1) return dp[idx];
        int sz = graph[idx].size();
        int tmp = 0;
        for (int i = 0; i < sz; ++i) {
            tmp = max(tmp, dfs(graph, graph[idx][i], dp));
        }
        dp[idx] = tmp + 1;
        return dp[idx];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> graph(n);
        deque<int> dq;
        vector<int> prev(n, -1);
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && arr[i] > arr[dq.back()]) {
                if (i - dq.back() <= d) graph[i].push_back(dq.back());
                dq.pop_back();
            }
            if (!dq.empty()) {
                prev[i] = dq.back();
                if (arr[i] == arr[dq.back()]) prev[i] = prev[dq.back()];
                if (prev[i] != -1 && i - prev[i] <= d) graph[prev[i]].push_back(i);
            }
            dq.push_back(i);
        }
        vector<int> dp(n, -1);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(graph, i, dp));
        }
        return res;
    }
};

// We can also do dp without explicitly building the graph.
// When an element i is popped out of the monotonous stack, we need to make sure that all its possible 
// contribution stays with elements still inside the monotonous stack. So we need to update the dp value of 
// its most recent previous element prev[i] that is strictly larger. This is actually a process of finding 
// the result of the right side of prev[i]. The left side is done during the push process into the stack.
// The key part of doing this kind of "in-place" dp is to make sure that when we use a dp[j] to update dp[i], dp[j] 
// has already been completely calculated. So we can't direcly update a dp value where in the previous method we 
// add an edge. In this situation when an element i is popped out, it means that every index that can be reached 
// from i has already been visited. So dp[i] can already represent the final result.
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dq;
        vector<int> prev(n, -1);
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && arr[i] > arr[dq.back()]) {
                int bk = dq.back(), pr = prev[bk];
                if (i - bk <= d) {
                    // graph[i].push_back(dq.back());
                    dp[i] = max(dp[i], dp[bk] + 1);
                }
                if (pr != -1 && bk - pr <= d) dp[pr] = max(dp[pr], dp[bk] + 1);
                dq.pop_back();
            }
            if (!dq.empty()) {
                prev[i] = dq.back();
                if (arr[i] == arr[dq.back()]) prev[i] = prev[dq.back()];
                // if (prev[i] != -1 && i - prev[i] <= d) graph[prev[i]].push_back(i);
            }
            dq.push_back(i);
        }
        while (!dq.empty()) {
            int bk = dq.back(), pr = prev[bk];
            if (pr != -1 && bk - pr <= d) dp[pr] = max(dp[pr], dp[bk] + 1);
            dq.pop_back();
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dp[i]);
        }
        return res;
    }
};