// dfs solution with memoization and pruning
class Solution {
public:
  int dfs(vector<int>& nums, int idx, vector<int>& dp) {
    if (dp[idx] != -1) return dp[idx];
    if (idx == nums.size() - 1) return 0;
    int res = INT_MAX;
    for (int i = 1; i <= nums[idx]; ++i) {
      if (i + idx >= nums.size()) break;
      if (i + idx != nums.size() - 1 && nums[i + idx] < nums[i + idx - 1]) continue;
      if (i + idx != nums.size() - 1 && nums[i + idx] < nums[idx] - i) continue;
      int sp = dfs(nums, idx + i, dp);
      if (sp != -1) res = min(res, sp + 1);
    }
    if (res == INT_MAX) return -1;
    dp[idx] = res;
    return dp[idx];
  }
  int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return dfs(nums, 0, dp);
  }
};

// When dealing with MINIMUM distance or steps problems like
// this it's better to try bfs. In dfs above, even if we find
// the final answer, we may still need to do a lot of meaningless
// comparisons to identify that that answer IS the final answer.
// Actually in 322_coin_change using memoized bfs is also ok, but
// in every searching node there are too many directions to go
// so the complexity is not good. Here in every step there are 
// not that many directions(we can't jump to all the indices but
// only some of them).
class Solution {
public:
  int jump(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    queue<int> q;
    q.push(0);
    int step = 1;
    while (!q.empty()) {
      int sz = q.size();
      for (int nn = 0; nn < sz; ++nn) {
        int idx = q.front(), stp = nums[idx];
        nums[idx] = -1; // to indicate that this index has been reached
                        // so that if we meet this index again later
                        // it won't go into the following loop
        q.pop();
        for (int i = stp; i >= 1; --i) {
          if (i + idx >= nums.size()) continue;
          if (i + idx == nums.size() - 1) return step; // check the tail rather than the head of the queue
          q.push(i + idx);
        }
      }
      step++;
    }
    return -1;
  }
};

// In the pruning of dfs we can find that what really matter are 
// those indices that can jump quite far to cover some of its later
// indices, which will save some search operations. This gives an
// important information that it's good to check how far we can
// go in each step in bfs. A key feature of this jumping process
// is that you can jump 1 to nums[idx] steps as you wish, so if the 
// farthest we can go is beyond the array, we can finish the searching.
// This also means that every time the elements in the queue is continuous
// in the array, so instead of using a queue, just use two pointers to
// track the start and the end of the elements that should be in the queue,
// a.k.a. elements that could be reached within the same step.
class Solution {
public:
  int jump(vector<int>& nums) {
    int step = 0, last = -1, maxd = 0;
    while (maxd < nums.size() - 1) {
      step++;
      int tmp = maxd;
      for (int i = last + 1; i <= tmp; ++i) {
        maxd = max(maxd, i + nums[i]);
      }
      last = tmp;
    }
    return step;
  }
};