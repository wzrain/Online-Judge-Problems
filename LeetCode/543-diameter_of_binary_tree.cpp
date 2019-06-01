/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// similar to 124
class Solution {
public:
  int dfs(TreeNode* cur, int& res) {
    if (!cur) return 0;
    int ld = dfs(cur->left, res), rd = dfs(cur->right, res);
    res = max(res, ld + rd);
    return max(ld, rd) + 1;
  }
  int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    dfs(root, res);
    return res;
  }
};