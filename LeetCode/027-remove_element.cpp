// put to-be-dicarded elements in the back
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int idx = nums.size() - 1; // the last place that is not val
    for (int i = 0; i <= idx; ++i) {
      while (nums[i] == val && i <= idx) {
        swap(nums[i], nums[idx--]); // put val to the end of the vector
      }
    }
    return idx + 1;
  }
};

// put remaining elements in the front
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) nums[res++] = nums[i];
    }
    return res;
  }
};