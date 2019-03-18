// segment tree solution
// passing references rather than values 
// will signicantly increase the performance
// and reduce the space cost
class NumArray {
public:
  struct node {
    int start, end, val;
    node* left, *right;
    node(int s = 0, int e = 0, int v = 0) : start(s), end(e), val(v), left(NULL), right(NULL) {}
  };
  node* root;
  
  void build(node* rt, vector<int>& nums, int l, int r) {
    if (l > r) return;
    rt->start = l;
    rt->end = r;
    if (l == r) {
      rt->val = nums[l];
      return;
    }
    int mid = (l + r) / 2;
    rt->left = new node;
    rt->right = new node;
    build(rt->left, nums, l, mid);
    build(rt->right, nums, mid + 1, r);
    rt->val = rt->left->val + rt->right->val;
  }
  
  NumArray(vector<int> nums) {
    root = new node;
    build(root, nums, 0, nums.size() - 1);
  }
  
  void ud(node* rt, int i, int val) {
    if (rt->start == rt->end) {
      rt->val = val;
      return;
    }
    int mid = (rt->start + rt->end) / 2;
    if (i <= mid) ud(rt->left, i, val);
    else ud(rt->right, i, val);
    rt->val = rt->left->val + rt->right->val;
  }

  void update(int i, int val) {
    ud(root, i, val);
  }
  
  int query(node* rt, int i, int j) {
    if (i > j) return 0;
    if (rt->start == i && rt->end == j) return rt->val;
    int mid = (rt->start + rt->end) / 2;
    if (i > mid) return query(rt->right, i, j);
    else if (j <= mid) return query(rt->left, i, j);
    else return query(rt->left, i, mid) + query(rt->right, mid + 1, j);
  }

  int sumRange(int i, int j) {
    return query(root, i, j);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */