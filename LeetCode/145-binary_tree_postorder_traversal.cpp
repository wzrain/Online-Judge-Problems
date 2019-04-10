/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_1 {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    vector<TreeNode*> stk;
    stk.push_back(root);
    while (!stk.empty()) {
      TreeNode* l = stk.back()->left;
      while (l) {
        stk.push_back(l);
        l = l->left;
      }
      while (!stk.empty() && !stk.back()->right) {
        res.push_back(stk.back()->val);
        stk.pop_back();
      }
      if (!stk.empty()) {
        TreeNode* tmp = stk.back()->right;
        stk.back()->right = NULL;
        stk.push_back(tmp);
      }
    }
    return res;
  }
};

// postorder is the reverse of preorder from right to left
class Solution_2 {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    vector<TreeNode*> stk;
    TreeNode* tmp = root;
    while (tmp) {
      res.push_back(tmp->val);
      if (tmp->left) stk.push_back(tmp->left);
      tmp = tmp->right;
      if (!tmp &&!stk.empty()) {
        tmp = stk.back();
        stk.pop_back();
      }
    }
    reverse(res.begin(),res.end());
    return res;
  }
};

class Solution_3 {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    vector<TreeNode*> stk;
    stk.push_back(root);
    while (!stk.empty()) {
      TreeNode* tmp = stk.back();
      stk.pop_back();
      res.push_back(tmp->val);
      if (tmp->left) stk.push_back(tmp->left);
      if (tmp->right) stk.push_back(tmp->right);
    }
    reverse(res.begin(),res.end());
    return res;
  }
};

// Morris traversal
// In postorder traversal, when a node's left-subtree traversal finished,
// which means the right-most elements points back to the node, the right
// path hasn't been actually added to the result.
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode* dummy = new TreeNode(0), *cur = dummy;
    dummy->left = root;
    while (cur) {
      if (!cur->left) cur = cur->right;
      else {
        TreeNode* tmp = cur->left;
        while (tmp->right && tmp->right != cur) tmp = tmp->right;
        if (!tmp->right) {
          tmp->right = cur;
          cur = cur->left;
        }
        else {
          tmp->right = NULL;
          tmp = cur->left;
          res.push_back(tmp->val);
          int cnt = 1;
          while (tmp->right) {
            tmp = tmp->right;
            res.push_back(tmp->val);
            cnt++;
          }
          reverse(res.end() - cnt, res.end());
          cur = cur->right;
        }
      }
    }
    return res;
  }
};