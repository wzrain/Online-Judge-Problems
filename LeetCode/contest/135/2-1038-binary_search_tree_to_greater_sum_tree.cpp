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
class Solution {
public:
  void inorder(TreeNode* cur, int& sum) {
    if (!cur) return;
    inorder(cur->right, sum);
    cur->val += sum;
    sum = cur->val;
    inorder(cur->left, sum);
  }
  TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    inorder(root, sum);
    return root;
  }
};

// non-recursive solution
class Solution {
public:
  TreeNode* bstToGst(TreeNode* root) {
    if (!root) return root;
    vector<TreeNode*> stk;
    stk.push_back(root);
    TreeNode* cur = root;
    int sum = 0;
    while (!stk.empty()) {
      while (cur->right) {
        cur = cur->right;
        stk.push_back(cur);
      }
      // find the last node with a left son
      while (!stk.empty() && !stk.back()->left) {
        // visit the nodes with visited right subtrees
        stk.back()->val += sum;
        sum = stk.back()->val;
        stk.pop_back();
      }
      if (!stk.empty()) {
        cur = stk.back()->left;
        // visit the node with visited right subtrees and start to visit its left subtree
        stk.back()->val += sum;
        sum = stk.back()->val;
        stk.pop_back();
        stk.push_back(cur);
      }
    }
    return root;
  }
};