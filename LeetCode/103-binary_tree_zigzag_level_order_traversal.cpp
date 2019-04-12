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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> tmp;
      int sz = q.size();
      for (int s = 0; s < sz; ++s) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
        tmp.push_back(cur->val);
      }
      res.push_back(tmp);
    }
    for (int i = 1; i < res.size(); i += 2) {
      reverse(res[i].begin(), res[i].end());
    }
    return res;
  }
};