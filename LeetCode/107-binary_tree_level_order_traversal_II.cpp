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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        tmp.push_back(cur->val);
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
      res.push_back(tmp);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

// dfs to calculate level
class Solution {
public:
  void level(TreeNode* cur, vector<vector<int>>& res, int l) {
    if (!cur) return;
    if (l >= res.size()) res.push_back({cur->val});
    else res[l].push_back(cur->val);
    level(cur->left, res, l + 1);
    level(cur->right, res, l + 1);
  }
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    level(root, res, 0);
    reverse(res.begin(), res.end());
    return res;
  }
};