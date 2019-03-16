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