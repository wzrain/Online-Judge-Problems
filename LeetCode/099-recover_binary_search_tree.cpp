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

// Morris traversal
// When doing traversal it's crucial to know whether a node's left
// subtree traversal is finished. In Morris traversal every time
// we encounter a node with non-empty left subtree, we find the 
// right-most node of that left subtree(which is exactly the previous
// node of the current node), and set the right son of that right-most
// node as the current node so that if the left subtree finished traversal
// it will automatically go back to the current node. Since every edge
// between two nodes will be visited twice at most, the complexity is O(n).
// Especially in inorder traversal, when we encounter a node with no left
// subtree, that node is ok to be added in the result. Otherwise, the node
// will be waiting until its left subtree finished traversal. So every time
// we encounter a node with non-empty left subtree, we check whether there's
// a loop so that the visit of the current node is from its previous node
// which is the right-most node of its subtree.
// In preorder traversal we add it to the result every time we encounter a new
// node, and that "loop" indicates that the current node's left subtree has
// finished traversal and the current node is not a new node.
class Solution {
public:
  void recoverTree(TreeNode* root) {
    TreeNode* cur = root, *prev = NULL, *wrong = NULL, *cand = NULL;
    while (cur) {
      if (!cur->left) {
        if (prev && cur->val < prev->val) {
          if (wrong) cand = cur;
          else {
            wrong = prev;
            cand = cur;
          }
        }
        prev = cur;
        cur = cur->right;
      }
      else {
        TreeNode* tmp = cur->left;
        while (tmp->right && tmp->right != cur) tmp = tmp->right;
        if (tmp->right == NULL) {
          tmp->right = cur;
          cur = cur->left;
        }
        else {
          tmp->right = NULL;
          if (prev && cur->val < prev->val) {
            if (wrong) cand = cur;
            else {
              wrong = prev;
              cand = cur;
            }
          }
          prev = cur;
          cur = cur->right;
        }
      }
    }
    swap(wrong->val, cand->val);
  }
};