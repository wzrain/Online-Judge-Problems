// O(nlogn)
// consider negative numbers when dealing with product
class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return max(nums[n - 3] * nums[n - 2] * nums[n - 1], nums[0] * nums[1] * nums[n - 1]);
  }
};

// O(n) solution
// find kth largest number
class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> large;
    priority_queue<int> small;
    for (int i = 0; i < n; ++i) {
      if (small.size() < 2 || nums[i] < small.top()) {
        small.push(nums[i]);
        if (small.size() > 2) small.pop();
      }
      if (large.size() < 3 || nums[i] > large.top()) {
        large.push(nums[i]);
        if (large.size() > 3) large.pop();
      }
    }
    int l = 1, s = 1;
    while (!small.empty()) {
      s *= small.top();
      small.pop();
    }
    while (large.size() > 1) {
      l *= large.top();
      large.pop();
    }
    s *= large.top();
    l *= large.top();
    return max(s, l);
  }
};