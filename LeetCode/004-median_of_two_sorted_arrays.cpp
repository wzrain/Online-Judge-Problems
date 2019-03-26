// O(m + n) time with O(m + n) space
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1 = nums1.size(), s2 = nums2.size(), div = (s1 + s2 + 1) & 1;
    int i = 0, j = 0, tgt = (s1 + s2) / 2 + 1;
    vector<int> tmp;
    while (i < s1 && j < s2 && tmp.size() < tgt) {
      if (nums1[i] < nums2[j]) tmp.push_back(nums1[i++]);
      else tmp.push_back(nums2[j++]);
    }
    while (i < s1 && tmp.size() < tgt) tmp.push_back(nums1[i++]);
    while (j < s2 && tmp.size() < tgt) tmp.push_back(nums2[j++]);
    if (!div) return tmp.back();
    return (tmp.back() + tmp[tmp.size() - 2]) / 2.0;
  }
};

// O(min(m, n)) time
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1 = nums1.size(), s2 = nums2.size(), div = (s1 + s2 + 1) & 1;
    int l1 = 0, r1 = s1 - 1, l2 = 0, r2 = s2 - 1;
    int idx1 = (s1 - 1) / 2, idx2 = (s2 - 1) / 2;
    int tgt = (s1 + s2) / 2 + ((s1 + s2) & 1);
    while(l1 <= r1 && l2 <= r2) {
      idx1 = (l1 + r1) / 2;
      idx2 = (l2 + r2) / 2;
      if (nums1[idx1] < nums2[idx2]) {
        l1 = idx1 + 1;
        r2 = idx2;
        if (l1 + l2 >= tgt) {
          l1 = tgt - l2;
          break;
        }
      }
      else {
        l2 = idx2 + 1;
        r1 = idx1;
        if (l1 + l2 >= tgt) {
          l2 = tgt - l1;
          break;
        }
      }
    }
    if (l1 + l2 < tgt) {
      if (l1 > r1) l2 = tgt - l1;
      else if (l2 > r2) l1 = tgt - l2;      
    }
    while (l2 > 0 && l1 < s1 && nums2[l2 - 1] > nums1[l1]) {
      l1++;
      l2--;
    }
    while (l1 > 0 && l2 < s2 && nums1[l1 - 1] > nums2[l2]) {
      l2++;
      l1--;
    }
    int maxl = -2147483648;
    if (l1 > 0 && nums1[l1 - 1] > maxl) maxl = nums1[l1 - 1];
    if (l2 > 0 && nums2[l2 - 1] > maxl) maxl = nums2[l2 - 1];
    if (!div) return maxl;
    int minr;
    if (l1 == s1) minr = nums2[l2];
    else if (l2 == s2) minr = nums1[l1];
    else minr = min(nums1[l1], nums2[l2]);
    return (maxl + minr) / 2.0;
  }
};