// maintain a monotonous stack
class Solution {
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