/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// using deque
class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    deque<TreeNode*> q, tmp;
    q.push_back(root);
    int sz = 1;
    while (!q.empty()) {
      for (int i = 0; i < sz / 2 + sz % 2; ++i) {
        if (q.front()->val != q.back()->val) return false;
        if (q.front()->left) {
          tmp.push_front(q.front()->left);
          if (q.back()->right) tmp.push_back(q.back()->right);
          else return false;
        }
        if (q.front()->right) {
          tmp.push_front(q.front()->right);
          if (q.back()->left) tmp.push_back(q.back()->left);
          else return false;
        }
        q.pop_front();
        q.pop_back();
      }
      q = tmp;
      tmp.clear();
      sz = q.size();
    }
    return true;
  }
};