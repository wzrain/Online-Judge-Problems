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
class Solution_recur {
public:
    int maxDepth(TreeNode* root) {
      if (!root) return 0;
      return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// BFS solution
class Solution_bfs {
public:
  int maxDepth(TreeNode* root) {
    int res = 0;
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      for (int c = 0; c < sz; ++c) {
        TreeNode* h = q.front();
        q.pop();
        if (h->left) q.push(h->left);
        if (h->right) q.push(h->right);
      }
      res++;
    }
    return res;
  }
};

// DFS solution
class Solution_dfs_nonrecur {
public:
  int maxDepth(TreeNode* root) {
    int res = 0;
    if (!root) return 0;
    vector<TreeNode*> stk;
    vector<int> dstk;
    int curd = 0;
    while (root) {
      curd++;
      if (res < curd) res = curd;
      if (root->right) {
        stk.push_back(root->right);
        dstk.push_back(curd);
      }
      root = root->left;
      if (!root && !stk.empty()) {
        root = stk.back();
        stk.pop_back();
        curd = dstk.back();
        dstk.pop_back();
      }
    }
    return res;
  }
};