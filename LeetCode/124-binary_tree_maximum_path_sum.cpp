/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// First thought about dp with memoization. 
// Traversing every node to find the longest path across this node. 
// Since every node will only be visited once, there's no need for
// memoization, but just use recursion to get the longest path starting
// from a node's left and right son. So when the recursion returns, the
// current node's value should be always added. Since this value might
// be negative, the entire return value could be negative, so use the 
// non-negative operation to discard negative paths.
class Solution {
public:
  int dfs(TreeNode* cur, int& res) {
    if (!cur) return 0;
    int l = dfs(cur->left, res), r = dfs(cur->right, res);
    res = max(res, max(l, 0) + max(r, 0) + cur->val);
    return cur->val + max(0, max(l, r));
  }
  int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    dfs(root, res);
    return res;
  }
};