/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// recursive solution
class Solution_recursive {
public:
  void preorder(TreeNode* root, vector<int>& res) {
    if (root == NULL) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
  }
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
  }
};

// non-recursive solution
class Solution_nonRecur {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == NULL) return res;
    vector<TreeNode*> stk;
    stk.push_back(root);
    while (!stk.empty()) {
      TreeNode* top = stk.back();
      res.push_back(top->val);
      TreeNode* l = top->left;
      while (l) {
        res.push_back(l->val);
        stk.push_back(l);
        l = l->left;
      }
      while (!stk.empty() && stk.back()->right == NULL) stk.pop_back();
      if (!stk.empty()) {
        TreeNode* tmp = stk.back();
        stk.pop_back();
        stk.push_back(tmp->right);
      }
    }
    return res;
  }
};