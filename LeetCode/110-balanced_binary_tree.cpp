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
  int depth(TreeNode* rt, bool& flag) {
    if (!flag) return -1;
    if (!rt) return 0;
    int ld = depth(rt->left, flag), rd = depth(rt->right,flag);
    if (max(ld, rd) - min(ld, rd) >= 2) flag = false;
    return 1 + max(ld, rd);
  } 
  bool isBalanced(TreeNode* root) {
    bool flag = true;
    depth(root, flag);
    return flag;
  }
};