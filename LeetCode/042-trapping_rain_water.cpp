// maintain a monotonous stack
class Solution_1 {
public:
  int trap(vector<int>& height) {
    int r = 0, res = 0;
    // Initializing a big array as q would take a lot of time,
    // so use a vector or define the array outside the function.
    vector<int> q;
    for (int i = 0; i < height.size(); ++i) {
      while (!q.empty() && height[i] >= height[q.back()]) {
        int idx = q.back();
        q.pop_back();
        if (!q.empty()) {
          res += (min(height[i], height[q.back()]) - height[idx]) * (i - q.back() - 1);
        }
      }
      q.push_back(i);
    }
    return res;
  }
};

// two pointers
class Solution_2 {
public:
  int trap(vector<int>& height) {
    int l = 0, r = height.size() - 1, res = 0;
    while (l < r) {
      int h = height[l] < height[r] ? height[l] : height[r];
      while (l < r && height[l] <= h) res += (h - height[l++]);
      while (l < r && height[r] <= h) res += (h - height[r--]);
    }
    return res;
  }
};