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
  unordered_map<TreeNode*, TreeNode*> parent;
  void dfs(TreeNode* tgt, int k, vector<int>& res, int l) {
    if (!tgt) return;
    if (l == k) {
      res.push_back(tgt->val);
      return;
    }
    dfs(tgt->left, k, res, l + 1);
    dfs(tgt->right, k, res, l + 1);
  }
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    parent[root] = NULL;
    while (!q.empty()) {
      if (q.front()->left) {
        parent.insert(make_pair(q.front()->left, q.front()));
        q.push(q.front()->left);
      }
      if (q.front()->right) {
        parent.insert(make_pair(q.front()->right, q.front()));
        q.push(q.front()->right);
      }
      q.pop();
    }
    dfs(target, K, res, 0);
    TreeNode* p = target;
    int l = 1;
    while (parent[p]) {
      if (K - l == 0) {
        res.push_back(parent[p]->val);
        break;
      }
      if (p == parent[p]->left) dfs(parent[p]->right, K - l, res, 1);
      else dfs(parent[p]->left, K - l, res, 1);
      p = parent[p];
      l++;
    }
    return res;
  }
};