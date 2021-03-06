/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    vector<TreeNode*> stk;
    stk.push_back(root);
    while (!stk.empty()) {
      TreeNode* l = stk.back()->left;
      while (l) {
        stk.push_back(l);
        l = l->left;
      }
      while (!stk.empty() && !stk.back()->right) {
        res.push_back(stk.back()->val);
        stk.pop_back();
      }
      if (!stk.empty()) {
        TreeNode* tmp = stk.back();
        stk.pop_back();
        res.push_back(tmp->val);
        stk.push_back(tmp->right);
      }
    }
    return res;
  }
};