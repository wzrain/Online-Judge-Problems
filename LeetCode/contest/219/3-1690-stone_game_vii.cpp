// dp[i][j] as the optimal difference
// simulate the game process for either person to play optimally
class Solution {
public:
    int dfs(vector<int>& prefix, int i, int j, int person, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        if (dp[i][j] != INT_MAX) return dp[i][j];
        int lf = (prefix[j + 1] - prefix[i + 1]) * person + dfs(prefix, i + 1, j, -person, dp);
        int rt = (prefix[j] - prefix[i]) * person + dfs(prefix, i, j - 1, -person, dp);
        if (person > 0) {
            dp[i][j] = max(lf, rt);
        }
        else dp[i][j] = min(lf, rt);
        return dp[i][j];
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = stones[i - 1] + prefix[i - 1];
        }
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return dfs(prefix, 0, n - 1, 1, dp);
    }
};

// We can implicitly alternate the person by minus dfs 
// values, and only take the max of the current stage. 
// When taking the max in the previous solution, it's 
// something like score + dfs result, and when taking 
// the min, it's -score + dfs result, which is taking 
// the max of score - dfs result. And -dfs result will 
// implicitly alternate the sign, since score - dfs = 
// score - (score2 - dfs) = score - score2 + dfs = score 
// - score2 + score3 - dfs. The dp array here saves the 
// absolute value of the difference, where in the 
// previous solution the dp array saves the actual 
// difference of alice - bob. So previously bob needs to 
// take the minimum where alice needs to take the 
// maximum of that dp array, and here they both take the 
// max of the dp array since when bob takes action, his 
// score should be higher afterwards, he need to make 
// his "advantage" bigger in order to make the final 
// difference smaller.
class Solution {
public:
    int dfs(vector<int>& prefix, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        if (dp[i][j] != INT_MAX) return dp[i][j];
        int lf = (prefix[j + 1] - prefix[i + 1]) - dfs(prefix, i + 1, j, dp);
        int rt = (prefix[j] - prefix[i]) - dfs(prefix, i, j - 1, dp);
        dp[i][j] = max(lf, rt);
        return dp[i][j];
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = stones[i - 1] + prefix[i - 1];
        }
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return dfs(prefix, 0, n - 1, dp);
    }
};