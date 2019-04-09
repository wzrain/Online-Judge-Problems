/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// recursive inorder traversal
// Actually it will need O(logn) space for recursion.
class Solution {
public:
  void inorder(TreeNode* cur, TreeNode* &prev, TreeNode* &wrong, TreeNode* &cand, bool& flag) {
    if (flag) return;
    if (!cur) return;
    inorder(cur->left, prev, wrong, cand, flag);
    if (prev && cur->val < prev->val) {
      if (!wrong) {
        wrong = prev;
        cand = cur;
      }
      else {  // 1 2 *6* 4 5 *3* 7 (6 > 4, 5 > 3)
        swap(wrong->val, cur->val);
        flag = true;
        return;
      }
    }
    prev = cur;
    inorder(cur->right, prev, wrong, cand, flag);
  }
  void recoverTree(TreeNode* root) {
    bool flag = false;
    TreeNode* wrong = NULL, *cand = NULL, *prev = NULL;
    inorder(root, prev, wrong, cand, flag);
    if (!flag) swap(wrong->val, cand->val); // 1 2 *4* *3* 5 6 7 (4 > 3)
                                            // two wrong positions are adjacent
  }
};