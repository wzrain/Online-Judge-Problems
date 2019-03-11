// segment tree implemented with pointers
class Solution {
public:
  struct segNode {
    int cnt;
    segNode *left, *right;
    segNode(int c = 0) : cnt(c), left(NULL), right(NULL){}
  };
  int query(segNode* root, int qs, int qe, int l, int r) {
    if (root == NULL) return 0;
    if (qs == l && qe == r) return root->cnt;
    int mid = (l + r) / 2;
    if (mid < qs) return query(root->right, qs, qe, mid + 1, r);
    else if (mid >= qe) return query(root->left, qs, qe, l, mid);
    else return query(root->left, qs, mid, l, mid) + 
                query(root->right, mid + 1, qe, mid + 1, r);
  }
  void update(segNode* root, int index, int l, int r) {
    
    if (l == r) {
      root->cnt += 1; 
      return;
    }
    int mid = (l + r) / 2;
    if (root->left == NULL) root->left = new segNode;
    if (root->right == NULL) root->right = new segNode;
    if (index > mid) update(root->right, index, mid + 1, r);
    else update(root->left, index, l, mid);
    root->cnt = root->left->cnt + root->right->cnt;
  }
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> sort_num = nums, res;
    unordered_map<int, int> mapping;
    sort(sort_num.begin(), sort_num.end());
    for (int i = 0; i < nums.size(); ++i) {
      mapping[sort_num[i]] = i;
    }
    segNode* root = new segNode;
    for (int i = nums.size() - 1; i >= 0; --i) {
      int idx = mapping.at(nums[i]), cnt = 0;
      if (idx) {
        cnt = query(root, 0, idx - 1, 0, nums.size() - 1);
      }
      res.push_back(cnt);
      update(root, idx, 0, nums.size() - 1);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};