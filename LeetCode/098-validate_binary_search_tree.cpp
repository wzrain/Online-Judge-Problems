/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Note that the definition of the binary search tree is 
// a node's left son's value is less than its own value and
// its right son's value is larger than its own value, RECURSIVELY.
// Therefore checking only the node's son is inadequate.
// Similar to binary search on arrays, every time we get a
// RANGE and the target is in the range. For a node, when searching 
// its left subtree the maximum, which is the right bound of the
// RANGE is the node's value, which is also the left bound
// for the right subtree.
class Solution {
public:
  void valid(TreeNode* root, bool& flag, long mn, long mx) {
    if (!flag) return;
    if (!root) return;
    if (root->val >= mx || root->val <= mn) {
      flag = false;
      return;
    }
    if (root->left) valid(root->left, flag, mn, root->val);
    if (root->right) valid(root->right, flag, root->val, mx);
    // if (root->left) {
    //   if (root->left->val >= root->val || root->left->val <= mn) { // this is the mn and mx for root->left
    //     flag = false;
    //     return;
    //   }
    //   valid(root->left, flag, mn, root->val);
    // }
    // if (root->right) {
    //   if (root->right->val <= root->val || root->right->val >= mx) { // this is the mn and mx for root->right
    //     flag = false;
    //     return;
    //   }
    //   valid(root->right, flag, root->val, mx);
    // }
  }
  bool isValidBST(TreeNode* root) {
    bool flag = true;
    long l = -2147483649, r = 2147483648;
    valid(root, flag, l, r);
    return flag;
  }
};

// Inorder traversal is for traversing elements in order,
// so every elements visited should be greater than the 
// previously visited element.
// To avoid using long, just use the node for tracking.
class Solution {
public:
  void valid(TreeNode* rt, TreeNode* &prev, bool& flag) {
    if (!flag) return;
    if (!rt) return;
    valid(rt->left, prev, flag);
    if (prev && rt->val <= prev->val) {
      flag = false;
      return;
    }
    prev = rt;
    valid(rt->right, prev, flag);
  }
  bool isValidBST(TreeNode* root) {
    bool flag = true;
    TreeNode* prev = NULL;
    valid(root, prev, flag);
    return flag;
  }
};

// iterative version
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    vector<TreeNode*> stk;
    TreeNode* prev = NULL;
    stk.push_back(root);
    while (!stk.empty()) {
      TreeNode* l = stk.back()->left;
      while (l) {
        stk.push_back(l);
        l = l->left;
      }
      while (!stk.empty() && !stk.back()->right) {
        if (prev && stk.back()->val <= prev->val) return false;
        prev = stk.back();
        stk.pop_back();
      }
      if (!stk.empty()) {
        if (prev && stk.back()->val <= prev->val) return false;
        prev = stk.back();
        stk.pop_back();
        stk.push_back(prev->right);
      }
    }
    return true;
  }
};