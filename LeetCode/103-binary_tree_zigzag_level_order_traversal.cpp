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

// use deque
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    deque<TreeNode*> q;
    q.push_back(root);
    int par = 1;
    while (!q.empty()) {
      vector<int> tmp;
      int sz = q.size();
      for (int s = 0; s < sz; ++s) {
        TreeNode* cur;
        if (par) {
          cur = q.front();
          q.pop_front();
          if (cur->left) q.push_back(cur->left);
          if (cur->right) q.push_back(cur->right);
        }
        else {
          cur = q.back();
          q.pop_back();
          if (cur->right) q.push_front(cur->right);
          if (cur->left) q.push_front(cur->left);
        }
        tmp.push_back(cur->val);
      }
      par ^= 1;
      res.push_back(tmp);
    }
    return res;
  }
};