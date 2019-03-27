// brute force O(n^2) solution
class Solution {
public:
  int maxArea(vector<int>& height) {
    int res = 0;
    for (int i = 0; i < height.size() - 1; ++i) {
      for (int j = i + 1; j < height.size(); ++j) {
        int tmp = (j - i) * (min(height[i], height[j]));
        if (res < tmp) res = tmp;
      }
    }
    return res;
  }
};

// The brute force solution ignored a fact that the heights inside a container
// which are lower than both its left and right bound can never form a larger container.
// So we only need to find those heights that higher than one of the container's bound.
// Meanwhile, if one bound of a container is lower than the other, then this very container
// is the largest container it could form with heights inside this container.
// O(n) two-pointer solution
class Solution {
public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1, res = 0;
    while (l < r) {
      int vol = (r - l) * (min(height[l], height[r]));
      if (res < vol) res = vol;
      if (height[l] < height[r]) {
        int tmp = height[l];
        while (l < r && height[l] <= tmp) l++;
      }
      else {
        int tmp = height[r];
        while (l < r && height[r] <= tmp) r--;
      }
    }
    return res;
  }
};