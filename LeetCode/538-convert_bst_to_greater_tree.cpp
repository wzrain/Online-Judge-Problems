/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// values that is larger than a certain node are not only in its right tree!
// iterative reverse inorder traversal
class Solution {
public:
  int sum(TreeNode* root) {
    if (root == NULL) return 0;
    int rt = sum(root->right), prev = root->val;
    root->val += rt;
    return rt + sum(root->left) + prev;
  }
  TreeNode* convertBST(TreeNode* root) {
    if (!root) return NULL;
    int sum = 0;
    vector<TreeNode*> stk;
    stk.push_back(root);
    TreeNode* tmp = root->right;
    while (!stk.empty() || tmp) {
      while (tmp) {
        stk.push_back(tmp);
        tmp = tmp->right;
      }
      while (!stk.empty() && !stk.back()->left) {
        int prev = stk.back()->val;
        stk.back()->val += sum;
        sum += prev;
        stk.pop_back();
      }
      if (!stk.empty()) {
        tmp = stk.back()->left;
        int prev = stk.back()->val;
        stk.back()->val += sum;
        sum += prev;
        stk.pop_back();
      }
    }
    return root;
  }
};

// recursive solution
class Solution {
public:
  void traverse(TreeNode* rt, int& sum) {
    if (rt == NULL) return;
    traverse(rt->right, sum);
    int prev = rt->val;
    rt->val += sum;
    sum += prev;
    traverse(rt->left, sum);
  }
  TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    traverse(root, sum);
    return root;
  }
};