// Use a mask to record the current searching "edge" that 
// can still have an effect on the overall happiness.
// Memoize the maximal happiness of searched state, and
// if the current happiness (cur) is not larger than the
// memoized happiness, just return.
class Solution {
public:
    void dfs(int pos, int m, int n, int irem, int erem, vector<vector<int>>& grid, int &res, int cur, vector<vector<vector<unordered_map<int, int>>>>& dp, int mask) {
        if (res < cur) res = cur;
        if (res >= irem * 120 + erem * 120 + cur) return;
        if (pos >= m * n) return;
        if (!irem && !erem) return;
        
        int curm = pos / n, curn = pos % n;
        
        if (dp[pos][irem][erem].find(mask) != dp[pos][irem][erem].end() && 
            dp[pos][irem][erem][mask] >= cur) return;
        dp[pos][irem][erem][mask] = cur;
        
        // introvert (1)
        if (irem) {
            int inxt = cur + 120;
            if (curm > 0) {
                if (grid[curm - 1][curn] == 1) {
                    inxt -= 60;
                }
                else if (grid[curm - 1][curn] == 0) {
                    inxt -= 10;
                }
            }
            if (curn > 0) {
                if (grid[curm][curn - 1] == 1) {
                    inxt -= 60;
                }
                else if (grid[curm][curn - 1] == 0) {
                    inxt -= 10;
                }
            }
            grid[curm][curn] = 1;
            int add = (2 << (curn * 2));
            dfs(pos + 1, m, n, irem - 1, erem, grid, res, inxt, dp, mask | add);
            grid[curm][curn] = -1;
        }
        
        // extrovert (0)
        if (erem) {
            int enxt = cur + 40;
            if (curm > 0) {
                if (grid[curm - 1][curn] == 1) {
                    enxt -= 10;
                }
                else if (grid[curm - 1][curn] == 0) {
                    enxt += 40;
                }
            }
            if (curn > 0) {
                if (grid[curm][curn - 1] == 1) {
                    enxt -= 10;
                }
                else if (grid[curm][curn - 1] == 0) {
                    enxt += 40;
                }
            }
            grid[curm][curn] = 0;
            int add = 1 << (curn * 2);
            dfs(pos + 1, m, n, irem, erem - 1, grid, res, enxt, dp, mask | add);
            grid[curm][curn] = -1;
        }
        
        dfs(pos + 1, m, n, irem, erem, grid, res, cur, dp, mask);
        
    }
    
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        vector<vector<vector<unordered_map<int, int>>>> dp(
            m * n, vector<vector<unordered_map<int, int>>>(
                introvertsCount + 1, vector<unordered_map<int, int>>(extrovertsCount + 1)
            )
        );
        int res = 0, cur = 0, mask = 0;
        dfs(0, m, n, introvertsCount, extrovertsCount, grid, res, cur, dp, mask);
        return res;
    }
};

// A proper top-down dp should memoize results after the searching finishes. So the
// dp array saves the searching result of the current state plus the added (or deducted)
// happiness out of new adjacency relationships.
// Another improvement is to get rid of the grid array and only use mask information
// to check the adjacency. Replace unordered_map with vector to gain great
// performance improvement.
class Solution {
public:
    int dfs(int pos, int m, int n, int irem, int erem, vector<vector<vector<vector<int>>>>& dp, int mask) {
        if (pos >= m * n) return 0;
        if (!irem && !erem) return 0;
        if (dp[pos][irem][erem][mask] != -1) 
            return dp[pos][irem][erem][mask];
        
        int res = INT_MIN;
        int curm = pos / n, curn = pos % n;
        int posmk = 3 << (2 * curn), clear =  ~posmk;
        if (irem) {
            int inxt = 120;
            if (curm > 0) {
                int upmk = (mask & posmk) >> (2 * curn);
                if (upmk == 2) {
                    inxt -= 60;
                }
                else if (upmk == 1) {
                    inxt -= 10;
                }
            }
            if (curn > 0) {
                int prevmk = (mask & (posmk >> 2)) >> (2 * (curn - 1));
                if (prevmk == 2) {
                    inxt -= 60;
                }
                else if (prevmk == 1) {
                    inxt -= 10;
                }
            }
            int add = (2 << (curn * 2));
            int tmp = inxt + dfs(pos + 1, m, n, irem - 1, erem, dp, (mask & clear) | add);
            res = max(res, tmp);
        }
        
        if (erem) {
            int enxt = 40;
            if (curm > 0) {
                int upmk = (mask & posmk) >> (2 * curn);
                if (upmk == 2) {
                    enxt -= 10;
                }
                else if (upmk == 1) {
                    enxt += 40;
                }
            }
            if (curn > 0) {
                int prevmk = (mask & (posmk >> 2)) >> (2 * (curn - 1));
                if (prevmk == 2) {
                    enxt -= 10;
                }
                else if (prevmk == 1) {
                    enxt += 40;
                }
            }
           
            int add = 1 << (curn * 2);
            int tmp = enxt + dfs(pos + 1, m, n, irem, erem - 1, dp, (mask & clear) | add);
            res = max(res, tmp);
        }
        
        res = max(res, dfs(pos + 1, m, n, irem, erem, dp, mask & clear));
        dp[pos][irem][erem][mask] = res;
        return res;
    }
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        vector<vector<vector<vector<int>>>> dp(
            m * n, vector<vector<vector<int>>>(
                introvertsCount + 1, vector<vector<int>>(
                    extrovertsCount + 1, vector<int>(1 << (2 * n), -1)
                )
            )
        );
        return dfs(0, m, n, introvertsCount, extrovertsCount, dp, 0);
    }
};