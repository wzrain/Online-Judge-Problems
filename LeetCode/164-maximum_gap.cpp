// bucket-sort solution
// The minimum final result res definitely satisfies min + (n - 1) * res
// >= max, which means res >= ceiling((max - min) / (n - 1)). Therefore
// if we use buckets with the size of that gap, we don't need to consider 
// elements inside a same bucket cuz the distance between the max and min 
// of one bucket is less than gap. So we only need to check the adjacent
// non-empty buckets to see the distance between the left one's max and
// right one's min.
class Solution {
public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int n = nums.size();
    int mx = max(nums[0], nums[1]), mn = min(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
      mx = max(mx, nums[i]);
      mn = min(mn, nums[i]);
    }
    if (mx == mn) return 0;
    int gap = (mx - mn) / (n - 1) + ((mx - mn) % (n - 1) == 0 ? 0 : 1);
    // mn + (n - 1) * gap >= mx, so to cover all the elements with
    // gap-sized bucket, n buckets are needed.
    vector<vector<int>> bucket(n, {INT_MAX, INT_MIN});
    for (int i = 0; i < n; ++i) {
      int idx = (nums[i] - mn) / gap;
      bucket[idx][0] = min(bucket[idx][0], nums[i]);
      bucket[idx][1] = max(bucket[idx][1], nums[i]);
    }
    int res = 0, i = 0;
    while (i + 1 < n) {
      int next = i + 1;
      while (next < n && bucket[next][0] == INT_MAX) next++;
      if (next < n) res = max(res, bucket[next][0] - bucket[i][1]);
      i = next;
    }
    return res;
  }
};

// radix sort solution
// Sort according to every 4 bits and get "partly" correct order every time
class Solution {
public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    vector<int> radix(16);
    vector<int> tmp(nums.size());
    for (int b = 0; b < 32; b += 4) {
      for (int ix = 0; ix < 16; ++ix) radix[ix] = 0;
      for (int i = 0; i < nums.size(); ++i) {
        radix[(nums[i] >> b) & 15]++;
      }
      // Instead of saving the results in an actual bucket, just save the number
      // of elements in each bucket. Then it's easy to get the index range of elements
      // in the new order in each bucket.
      for (int ix = 1; ix < 16; ++ix) radix[ix] += radix[ix - 1];
      for (int i = nums.size() - 1; i >= 0; --i) {
        tmp[--radix[(nums[i] >> b) & 15]] = nums[i];
      }
      nums = tmp;
    }
    int res = 0;
    for (int i = 1; i < nums.size(); ++i) {
      res = max(res, nums[i] - nums[i - 1]);
    }
    return res;
  }
};