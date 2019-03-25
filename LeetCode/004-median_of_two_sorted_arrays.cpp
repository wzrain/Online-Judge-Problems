class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    double res;
    vector<int> tmp;
    int i = 0, j = 0;
    while (tmp.size() != (total >> 1) +1 && i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) tmp.push_back(nums1[i++]);
      else tmp.push_back(nums2[j++]);
    }
    while (tmp.size() != (total >> 1) + 1 && i < nums1.size()) tmp.push_back(nums1[i++]);
    while (tmp.size() != (total >> 1) + 1 && j < nums2.size()) tmp.push_back(nums2[j++]);
    if (total & 1) res = tmp[tmp.size() - 1];
    else res = ((tmp[tmp.size() - 1] + tmp[tmp.size() - 2]) * 1.0 / 2);
    return res;
  }
};