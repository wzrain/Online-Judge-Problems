/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_recur {
public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int ld, rd;
    if (root->left) ld = minDepth(root->left);
    else ld = 2000000000;
    if (root->right) rd = minDepth(root->right);
    else rd = 2000000000;
    return ld < rd ? ld + 1 : rd + 1;
  }
};

// BFS
class Solution_nonrecur {
public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    int d = 0;
    q.push(root);
    while (!q.empty()) {
      d++;
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        TreeNode* tmp = q.front();
        if (!tmp->left && !tmp->right) return d;
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
        q.pop();
      }
    }
    return d;
  }
};