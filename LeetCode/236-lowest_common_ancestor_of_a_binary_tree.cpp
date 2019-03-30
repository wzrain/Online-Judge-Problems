/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Use a set to record the ancestors of one node
// and find the other node's ancestor.
// No need to calculate level information.
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q) return NULL;
    unordered_map<TreeNode*, TreeNode*> prt;
    //unordered_map<TreeNode*, int> level;
    unordered_set<TreeNode*> pascts;
    prt.insert(make_pair(root, nullptr));
    //level[root] = 1;
    int found = 0;
    queue<TreeNode*> nq;
    nq.push(root);
    while (!nq.empty() && found < 2) {
      int sz = nq.size();
      for (int s = 0; s < sz; ++s) {
        if (nq.front()->left) {
          //level[nq.front()->left] = level[nq.front()] + 1;
          nq.push(nq.front()->left);
          prt.insert(make_pair(nq.front()->left, nq.front()));
        }
        if (nq.front()->right) {
          //level[nq.front()->right] = level[nq.front()] + 1;
          nq.push(nq.front()->right);
          prt.insert(make_pair(nq.front()->right, nq.front()));
        }
        if (nq.front() == p || nq.front() == q) found++;
        if (found == 2) break;
        nq.pop();
      }
    }
    // while (level[p] > level[q]) p = prt[p];
    // while (level[q] > level[p]) q = prt[q];
    // while (p != q) {
    //   p = prt[p];
    //   q = prt[q];
    // }
    while (p) {
      pascts.insert(p);
      p = prt[p];
    }
    while (pascts.find(q) == pascts.end()) q = prt[q];
    return q;
  }
};

// recursive
// the process of finding parents is exactly the same
// as the backtracking process of recursion
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // If the return value is not NULL, at least 
    // one target node is included in this subtree.
    if (!root || root == p || root == q) return root; 
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    // The least common ancestor is the only node 
    // that have one target node in each of its subtree.
    if (l && r) return root;
    if (!l) return r;
    return l;
  }
};